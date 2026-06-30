#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/**
 * @note 头文件说明：
 *  algorithm:提供了iter_swap函数
 *  functional:提供了less函数
 *  iterator:提供了distance函数
 */

 /**
  * @brief 向下调整堆
  * @param first 数组起始迭代器
  * @param n 数组长度
  * @param i 待调整的节点索引
  * @param compare 比较函数
  * @return void
  */
template <typename RandomIt, typename Compare>
void siftDown(RandomIt first, size_t n, size_t i, Compare compare) {
  while (true) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // 如果左子节点存在且大于当前最大节点
    if (left < n && compare(*(first + largest), *(first + left))) {
      largest = left;
    }

    // 如果右子节点存在且大于当前最大节点
    if (right < n && compare(*(first + largest), *(first + right))) {
      largest = right;
    }

    // 如果最大节点已经是当前节点，说明堆性质已满足，结束调整
    if (largest == i) {
      break;
    }

    // 交换并继续向下调整
    iter_swap(first + i, first + largest);
    i = largest;
  }
}

/**
 * @brief 堆排序
 * @param first 数组起始迭代器
 * @param last 数组结束迭代器
 * @param compare 比较函数
 * @return void
 */
template <
    typename RandomIt,
    typename Compare = less<typename iterator_traits<RandomIt>::value_type>>
void heapSort(RandomIt first, RandomIt last, Compare comp = Compare()) {
  // 获取到数组长度
  size_t n = distance(first, last);
  // 如果数组长度小于2，直接返回
  if (n < 2)
    return;

  // 1.构建最大堆
  // 从最后一个非叶子节点开始，从下往上、从右往左进行 siftDown
  for (long long i = n / 2 - 1; i >= 0; i--) {
    siftDown(first, n, static_cast<size_t>(i), comp);
  }

  // 2.逐个提取元素
  // 将堆顶元素（最大值）交换到数组末尾，然后对剩下的元素重新调整堆
  for (size_t i = n - 1; i > 0; i--) {
    iter_swap(first, first + i);
    siftDown(first, i, 0, comp);
  }
}

// ================= 测试代码 =================
int main() {

  // 测试 1: 升序排序 (默认)
  vector<int> vec = {12, 11, 13, 5, 6, 7, 3, 1, 9};
  cout << "原始数组: ";
  for (int v : vec)
    cout << v << " ";
  cout << "\n";

  heapSort(vec.begin(), vec.end());
  cout << "升序排序: ";
  for (int v : vec)
    cout << v << " ";
  cout << "\n";

  // 测试 2: 降序排序 (使用 std::greater)
  heapSort(vec.begin(), vec.end(), std::greater<int>());
  cout << "降序排序: ";
  for (int v : vec)
    cout << v << " ";
  cout << "\n";

  // 测试 3: 原生数组排序
  int arr[] = {4, 10, 3, 5, 1};
  heapSort(std::begin(arr), std::end(arr));
  cout << "原生数组升序: ";
  for (int v : arr)
    cout << v << " ";
  cout << "\n";

  return 0;
}