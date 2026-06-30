# ``iter_swap``函数

<hr />

在 C++ 标准库中，``std::iter_swap`` 是一个非常实用的算法函数，定义在 ``<algorithm>`` 头文件中。

它的主要作用是：**交换两个迭代器所指向的元素的值**。

<br />

## 1.函数原型

```cpp
template< class ForwardIt1, class ForwardIt2 >
void iter_swap( ForwardIt1 a, ForwardIt2 b );
```

<hr />

## 2.核心特点

- **交换的是值，而不是迭代器本身**：执行后，迭代器 ``a`` 和 ``b`` 的指向并不会改变，改变的是它们所指向的内存空间里存储的值。
- **支持不同类型的迭代器**：只要两个迭代器指向的类型可以通过 ``std::swap`` 相互交换即可，它们不必是同一种容器或同一种迭代器类型。
- **内部实现**：它的底层实现非常简单，基本上等同于调用 ``std::swap(*a, *b)``。但它会结合 ADL（依赖实参的查找）机制，确保能调用到特定类型的最佳 ``swap`` 函数。

<hr />

## 3.使用示例

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    std::cout << "交换前: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << "\n";

    // 交换第一个元素和最后一个元素的值
    std::iter_swap(vec.begin(), vec.end() - 1);

    std::cout << "交换后: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
```

**输出**：
```text
交换前: 10 20 30 40 50 
交换后: 50 20 30 40 10 
```

<hr />

## 4.为什么使用 ``std::iter_swap`` 而不是 ``std::swap(*a, *b)``？

虽然 ``std::iter_swap(a, b)`` 和 ``std::swap(*a, *b)`` 的效果几乎一样，但在编写泛型算法时，推荐使用 ``std::iter_swap``，原因如下：

1. **代码可读性**：``iter_swap`` 语义明确，直接表明“我要交换这两个迭代器指向的元素”。
2. **安全性**：在模板编程中，如果 ``a`` 或 ``b`` 不是传统的指针或迭代器（例如某些代理对象），直接使用 ``*a`` 可能会有意想不到的副作用。``std::iter_swap`` 封装了这些细节。
3. **优化与 ADL**：``std::iter_swap`` 内部会先 ``using std::swap;``，然后调用 ``swap(*a, *b);``。这保证了如果你的自定义类型定义了专属的 ``swap`` 函数，它能被正确调用，而不是强制使用通用的 ``std::swap``。

<hr />

## 5.实际使用场景

``std::iter_swap`` 常用于实现各种排序算法（如冒泡排序、选择排序、快速排序）或重排算法。例如，在实现选择排序时，可以用它将当前最小值交换到正确位置：
```cpp
template <typename ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end) {
    for (ForwardIt i = begin; i != end; ++i) {
        ForwardIt min_it = std::min_element(i, end);
        // 交换当前位置和最小值位置的元素
        std::iter_swap(i, min_it); 
    }
}
```