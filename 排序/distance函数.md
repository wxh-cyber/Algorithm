# ``distance``函数

<hr />

在 C++ 标准库中，``std::distance`` 是一个非常常用的函数，定义在 ``<iterator>`` 头文件中。

它的主要作用是：**计算两个迭代器之间的距离（即它们之间相隔的元素个数）**。

<hr />

## 1.函数原型

```cpp
template< class InputIt >
typename std::iterator_traits<InputIt>::difference_type 
std::distance( InputIt first, InputIt last );
```
返回值类型通常是带符号的整数类型（如 ``ptrdiff_t`` 或 ``long long``），取决于迭代器的底层实现。

<hr />

## 2.核心特点与复杂度

``std::distance`` 的内部实现会根据迭代器的**类型**自动选择最优的计算方式：

- **随机访问迭代器（Random Access Iterator）：如 ``std::vector``、``std::array``、``std::deque`` 的迭代器或原生指针**。
    - **复杂度**：𝑂(1)（常数时间）。
    - **底层实现**：直接相减 ``last - first``。
    - **特点**：支持反向计算，如果 ``first`` 在 ``last`` 后面，结果将是负数。

- **顺序/前向/双向迭代器（Input/Forward/Bidirectional Iterator）：如 ``std::list``、``std::forward_list``、``std::map``、``std::set`` 的迭代器**。
    - **复杂度**：𝑂(𝑁)（线性时间）。
    - **底层实现**：从 ``first`` 开始不断递增，直到等于 ``last``，统计递增的次数。
    - **特点**：**不支持反向计算**。对于这些迭代器，``first`` 必须能够通过递增到达 ``last``，否则会导致未定义行为（通常是死循环或崩溃）。

<hr />

## 3.使用示例

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {
    // 1. 在 vector 中使用 (随机访问迭代器)
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto it1 = vec.begin();
    auto it2 = vec.begin() + 3; // 指向 40

    std::cout << "Vector distance (it1 -> it2): " << std::distance(it1, it2) << "\n"; // 输出 3
    std::cout << "Vector distance (it2 -> it1): " << std::distance(it2, it1) << "\n"; // 输出 -3 (支持负数)

    // 2. 在 list 中使用 (双向迭代器)
    std::list<int> lst = {10, 20, 30, 40, 50};
    auto lit1 = lst.begin();
    auto lit2 = lst.end();

    std::cout << "List distance (begin -> end): " << std::distance(lit1, lit2) << "\n"; // 输出 5

    // 注意：对于 list，不能反向计算，比如 std::distance(lit2, lit1) 会导致未定义行为！

    return 0;
}
```

<hr />

## 4.为什么使用 ``std::distance`` 而不是直接相减 ``last - first``？

1. **泛型编程的要求**：在编写模板函数时，你不知道传入的容器是 ``std::vector`` 还是 ``std::list``。直接使用 ``last - first`` 对于 ``std::list`` 的迭代器会导致**编译错误**（因为双向迭代器没有定义 ``-`` 运算符）。而 ``std::distance`` 可以自动适配所有类型的迭代器。
2. **代码统一性**：无论底层容器是什么，``std::distance`` 提供了一致的接口来获取距离。

<hr />

## 5.实际应用场景

常用于在泛型算法中获取容器或区间的长度，或者获取某个元素在容器中的索引位置：
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 查找值为 3 的元素
    auto it = std::find(vec.begin(), vec.end(), 3);
    
    if (it != vec.end()) {
        // 利用 distance 计算它是在第几个位置（索引）
        std::cout << "元素 3 的索引是: " << std::distance(vec.begin(), it) << "\n"; // 输出 2
    }
    
    return 0;
}
```