# ``move``函数

``std::move`` 是 C++11 引入的一个非常重要的函数，但它的名字其实极具误导性。

最核心的一点是：``std::move`` **本身绝对不会移动任何数据**！

它的真正作用仅仅是进行一次**类型的强制转换**：把一个左值转换成右值引用，从而让编译器去优先匹配移动语义（移动构造函数或移动赋值运算符）。

<hr />

## 1. 底层原理

``std::move`` 的源码，极其简单，本质上就是一个 ``static_cast``：
```cpp
template <typename T>
typename remove_reference<T>::type&& move(T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}
```
它把传入的参数强制转换成了 ``&&``（右值引用）类型。

<br />

## 2. 为什么要转成右值引用（移动语义）？

在 C++11 之前，对象的赋值通常是**深拷贝**。比如对于 ``std::string`` 或 ``std::vector`` 这种在堆上分配内存的类，将 A 赋值给 B，B 会重新申请内存，把 A 的数据一个个复制过去。这非常耗时。

C++11 引入了**移动语义**。如果 B 发现 A 是一个“将亡值”（右值，比如临时对象，或者你明确表示不再需要的对象），B 就不需要傻乎乎地去复制数据了，它可以直接把 A 内部指向堆内存的指针“偷”过来，然后把 A 的指针置空。这就叫“移动”，耗时只需 O(1)。

<br />

## 3. 例子

```cpp
#include <iostream>
#include <string>
#include <utility> // std::move 在这里

int main() {
    std::string str1 = "Hello, this is a very long string!";
    std::cout << "str1: " << str1 << " (长度: " << str1.length() << ")\n";

    // 普通拷贝：str1 内部的数据被完整复制到 str2
    std::string str2 = str1; 
    std::cout << "拷贝后 -> str1: " << str1 << ", str2: " << str2 << "\n\n";

    // 使用 std::move：告诉编译器“我不需要 str1 了，把它当右值看”
    // 这会触发 string 的移动构造函数，str3 直接接管了 str1 的内部内存
    std::string str3 = std::move(str1); 
    
    std::cout << "移动后 -> str1: " << str1 << " (长度: " << str1.length() << ")\n";
    std::cout << "移动后 -> str3: " << str3 << "\n";

    return 0;
}
```

**运行结果**
```text
str1: Hello, this is a very long string! (长度: 35)
拷贝后 -> str1: Hello, this is a very long string!, str2: Hello, this is a very long string!

移动后 -> str1:  (长度: 0)
移动后 -> str3: Hello, this is a very long string!
```

<br />

## 4. 在优化版插入排序中的体现

在优化版插入排序中，有这样一段代码：
```cpp
auto key = std::move(*it); 
// ...
*(j + 1) = std::move(*j);
```
如果你的容器里存的是 int 这样的基本类型，``std::move`` 不会有任何性能影响（因为拷贝 int 本身就很快）。

但如果容器里存的是 ``std::string``，当元素往后移一位 ``*(j + 1) = *(j)`` 时，默认会发生深拷贝。我们加上 ``std::move`` 后，变成了 ``*(j + 1) = std::move(*(j))``，这就把原来的拷贝变成了“指针所有权的转移”，大大提升了排序大对象时的速度。

<br />

## 5. 注意事项

1. **被 ``std::move`` 后的原对象处于“有效但未指定”的状态**。通常它的内部资源已经被掏空了（比如变成空字符串、空数组），你可以给它赋新值，或者让它析构，但**不要再去读取它的内容**。

2. 基本类型（如 ``int``, ``float``, ``double``）使用 ``std::move`` 没有任何意义，编译器会忽略它，依然进行普通赋值。