#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename RandomIt>
void insertion_sort(RandomIt first, RandomIt last) {
  // 如果加工数组的长度小于等于1，直接返回
  if (first == last)
    return;

  for (RandomIt i = first + 1; i < last; i++) {
    auto key = *i;
    RandomIt j = i - 1;
    while (j >= first && *j > key) {
      *(j + 1) = *j;
      j--;
    }

    *(j + 1) = key;
  }
}

// 2. 三数取中法选择 pivot
template <typename RandomIt>
void median_of_three(RandomIt first, RandomIt last) {
  RandomIt mid = first + (last - first) / 2;
  // 对首、中、尾三个元素进行排序，确保 *first <= *mid <= *(last-1)
  if (*first > *mid)
    std::swap(*first, *mid);
  if (*first > *(last - 1))
    std::swap(*first, *(last - 1));
  if (*mid > *(last - 1))
    std::swap(*mid, *(last - 1));
  // 把中位数（pivot）换到首位，作为划分基准
  std::swap(*first, *mid);
}

// 3. 三路划分的快速排序核心实现
template <typename RandomIt>
void quick_sort_impl(RandomIt first, RandomIt last) {
  // 小区间优化：元素个数小于 16 时使用插入排序
  if (last - first < 16) {
    insertion_sort(first, last);
    return;
  }

  // 选择 pivot 并放到首位
  median_of_three(first, last);
  auto pivot = *first;

  // 三路划分：
  // [first, lt)  < pivot
  // [lt, i)      = pivot
  // [i, gt)      未处理
  // [gt, last)   > pivot
  RandomIt lt = first;
  RandomIt gt = last;
  RandomIt i = first + 1;

  while (i < gt) {
    if (*i < pivot) {
      std::swap(*i, *lt);
      ++lt;
      ++i;
    } else if (*i > pivot) {
      --gt;
      std::swap(*i, *gt);
      // 这里 i 不自增，因为从 gt 换过来的元素还没检查过
    } else {
      ++i;
      // 等于 pivot，直接跳过
    }
  }

  // 递归处理小于 pivot 和大于 pivot 的部分
  // 中间等于 pivot 的部分 [lt, gt) 已经就位，不需要再参与递归！
  quick_sort_impl(first, lt);
  quick_sort_impl(gt, last);
}

// 对外暴露的排序接口
template <typename RandomIt> void my_quick_sort(RandomIt first, RandomIt last) {
  if (first == last)
    return;
  quick_sort_impl(first, last);
}

int main() {
  // 测试 1：随机数组
  std::vector<int> v1 = {3, 6, 8, 10, 1, 2, 1};
  my_quick_sort(v1.begin(), v1.end());
  std::cout << "Test 1: ";
  for (int x : v1)
    std::cout << x << " ";
  std::cout << "\n";

  // 测试 2：大量重复元素（三路划分的强项）
  std::vector<int> v2 = {5, 5, 5, 5, 5, 1, 5, 5, 5};
  my_quick_sort(v2.begin(), v2.end());
  std::cout << "Test 2: ";
  for (int x : v2)
    std::cout << x << " ";
  std::cout << "\n";

  // 测试 3：已经有序的数组（三数取中法的强项，不会退化）
  std::vector<int> v3 = {1,  2,  3,  4,  5,  6,  7,  8,  9,
                         10, 11, 12, 13, 14, 15, 16, 17, 18};
  my_quick_sort(v3.begin(), v3.end());
  std::cout << "Test 3: ";
  for (int x : v3)
    std::cout << x << " ";
  std::cout << "\n";

  return 0;
}