# ``nth_element``函数

<hr />

C++ 中的 ``nth_element`` 是 ``<algorithm>`` 库提供的一个非常实用且高效的排序相关函数。

用一句话概括它的功能：**它可以从一个序列中找出第 n 小的元素，并将其放置在序列的第 n 个位置上，同时保证它左边的元素都不大于它，右边的元素都不小于它**。

<br />

## 1.核心功能与特性

假设你有一个数组，并调用了 ``nth_element(v.begin(), v.begin() + n, v.end())``，执行后会发生以下三件事：

1. **定位**：第 n 个位置（从0开始计数）上的元素，变成了**如果整个数组排好序后应该在这个位置上的元素**（即第 n 小的元素）。
2. **左分区**：第 n 个位置之前的所有元素，都**小于或等于**该元素（但它们内部是无序的）。
3. **右分区**：第 n 个位置之后的所有元素，都**大于或等于**该元素（但它们内部也是无序的）。

<br />

## 2.函数签名

```cpp
// 默认使用 operator< 比较
void nth_element(RandomIt first, RandomIt nth, RandomIt last);

// 自定义比较规则
void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp);
```
- **first**: 序列的起始迭代器。
- **nth**: 你想要找的“第 n 大/小”元素应该在的位置迭代器。
- **last**: 序列的结束迭代器。
- **comp**: 自定义的比较函数（默认是 ``a < b``，即找第 n 小；如果传入 ``a > b``，则是找第 n 大）。

<br />

## 3.算法复杂度

- **平均时间复杂度**：O(N)。
- 最坏时间复杂度：O(N²)（但 C++ 标准库通常采用 Introselect 算法，在检测到退化为最坏情况时会自动切换算法，所以极难触达最坏情况）。

**对比 std::sort**：

如果只是为了找中位数或第 K 小的元素，使用 ``sort`` 需要 O(NlogN) 的时间，而 ``nth_element`` 只需要 O(N)。当数据量很大时，``nth_element`` 的性能优势非常明显。它之所以快，是因为它**不需要对整个序列进行完全排序**，只要保证第 n 个位置对了且左右分区对了，就直接停止。

<br />

## 4.代码示例

**示例1：寻找第3小的元素**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {9, 3, 7, 1, 5, 2, 8, 6, 4};
    
    // 寻找第 3 小的元素（索引为 2）
    std::nth_element(v.begin(), v.begin() + 2, v.end());
    
    std::cout << "第 3 小的元素是: " << v[2] << std::endl; // 必定输出 3
    
    std::cout << "执行后的数组: ";
    for (int n : v) {
        std::cout << n << " ";
    }
    // 输出可能为: 1 2 3 7 5 9 8 6 4 
    // 注意: v[2]一定是3，v[0]、v[1]一定<=3，v[3]及之后一定>=3，但左右两边内部是无序的
    
    return 0;
}
```

<br />

**示例2：寻找中位数**
```cpp
std::vector<int> v = {5, 2, 8, 1, 9, 4};
// 中位数位置为 size / 2 = 3
std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
int median = v[v.size() / 2]; // 找到中位数
```

<br />

**示例3：找第K大的元素（自定义比较器）**
```cpp
std::vector<int> v = {1, 5, 2, 8, 3};
// 找第 2 大的元素（索引为 1）
std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
int second_largest = v[1]; // 结果为 5
```

<br />

## 5.易混淆点

``nth_element`` 和 ``partial_sort``：

- ``nth_element``：只保证第 n 个位置上的元素是正确的，左右两边**无序**。时间复杂度 O(N)。
- ``partial_sort``：保证前 n 个元素是整个序列中最小的 n 个，**并且这前 n 个元素是排好序的**。时间复杂度 O(NlogK)。

**选择建议**：

- 如果你只需要知道“第 K 名是谁”，用 ``nth_element``。
- 如果你需要“找出成绩前 10 名的同学，并且按分数高低排好”，用 ``partial_sort``。