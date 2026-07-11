# `lower_bound`函数

在C++中，`std::lower_bound` 是定义在 `<algorithm>` 头文件中的一个非常实用的STL算法。它主要用于在**已排序**的区间内进行快速查找。

<hr />

### 核心概念

`lower_bound` 的作用是：在一个升序（默认）的区间中，寻找**第一个大于或等于**（`>=`）给定目标值的元素的位置。

因为底层使用的是二分查找，所以它的时间复杂度是 $O(\log N)$，比普通的从头到尾遍历（$O(N)$）要快得多。

<hr />

### 函数签名

```cpp
// 默认版本 (使用 operator< 进行比较，适用于升序区间)
template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);
// 自定义比较版本
template <class ForwardIterator, class T, class Compare>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```

<hr />

### 参数与返回值

*   **参数：**
    *   `first` 和 `last`：表示查找区间的起始和结束迭代器（左闭右开区间 `[first, last)`）。
    *   `val`：要查找的目标值。
    *   `comp`：自定义的比较函数（可选）。如果区间是降序排列的，必须传入 `std::greater<T>()`。
*   **返回值：**
    *   返回一个**迭代器**，指向区间中第一个不小于（即大于等于）`val` 的元素。
    *   如果区间中所有的元素都小于 `val`，则返回 `last`（即区间的末尾）。

<hr />

### 代码示例

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // 包含 lower_bound
int main() {
    // 注意：必须是有序序列（默认升序）
    std::vector<int> v = {1, 2, 3, 3, 3, 4, 5, 7};
    // 1. 查找存在的值：找第一个 >= 3 的元素
    auto it1 = std::lower_bound(v.begin(), v.end(), 3);
    if (it1 != v.end()) {
        // it1 - v.begin() 可以计算出元素的下标
        std::cout << "第一个 >= 3 的元素下标是: " << (it1 - v.begin()) 
                  << ", 值为: " << *it1 << std::endl; 
    }
    // 输出: 第一个 >= 3 的元素下标是: 2, 值为: 3
    // 2. 查找不存在的值，但区间内有比它大的数：找第一个 >= 6 的元素
    auto it2 = std::lower_bound(v.begin(), v.end(), 6);
    if (it2 != v.end()) {
        std::cout << "第一个 >= 6 的元素下标是: " << (it2 - v.begin()) 
                  << ", 值为: " << *it2 << std::endl;
    }
    // 输出: 第一个 >= 6 的元素下标是: 7, 值为: 7
    // 3. 查找比所有元素都大的值：找第一个 >= 8 的元素
    auto it3 = std::lower_bound(v.begin(), v.end(), 8);
    if (it3 == v.end()) {
        std::cout << "没有找到 >= 8 的元素，返回了 end() 迭代器" << std::endl;
    }
    // 输出: 没有找到 >= 8 的元素，返回了 end() 迭代器
    return 0;
}
```

<hr />

### 与 `upper_bound` 的区别

`lower_bound` 经常与它的“兄弟”函数 `std::upper_bound` 配合使用：
*   `lower_bound`：找第一个 **`>=`** val 的元素。
*   `upper_bound`：找第一个 **`>`**  val 的元素。

在包含多个相同元素的区间中（如上面的 `{1, 2, 3, 3, 3, 4, 5, 7}`）：
*   `lower_bound(v.begin(), v.end(), 3)` 会指向**第一个** `3`（下标为2）。
*   `upper_bound(v.begin(), v.end(), 3)` 会指向第一个 `3` 后面的元素，也就是 `4`（下标为5）。

这两个函数一起使用，可以非常方便地求出一个有序区间中等于某个值的元素个数（即求等于某值的区间边界）：

```cpp
int count = std::upper_bound(v.begin(), v.end(), 3) - std::lower_bound(v.begin(), v.end(), 3);
// 结果为 3，因为序列中有 3 个 3
```

<hr />

### 重要注意事项

1. **前提是必须排序**：`lower_bound` 不会自动帮你排序，如果你在一个无序的数组上使用它，结果是未定义的（随机的）。
2. **降序序列的使用**：如果你的容器是降序排列的（比如 `{7, 5, 4, 3, 2, 1}`），必须提供自定义比较器：
   ```cpp
   auto it = std::lower_bound(v.rbegin(), v.rend(), 3, std::greater<int>());
   // 或者不用反向迭代器：
   auto it = std::lower_bound(v.begin(), v.end(), 3, std::greater<int>());
   // 此时它的逻辑变为寻找第一个 <= val 的元素
   ```
