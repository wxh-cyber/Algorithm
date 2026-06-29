#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief 堆排序
 * @param arr 待排序数组
 * @param n 数组长度
 * @tparam T 数组元素类型
 * @return void
 * @note 时间复杂度：O(nlogn)
 * @note 空间复杂度：O(1)
 * @note 稳定性：不稳定
 * @note 适用场景：适用于任何可比类型的数组
 */
template <typename T> void heapSort(T arr[], int n) {
  // 如果数组长度小于2，直接返回
  if (n < 2)
    return;

  // 1.构建最大堆
  // 从最后一个非叶子节点开始，依次向上调整
  for (int i = n / 2 - 1; i >= 0; i--) {
    int parent = i; // 将当前节点设为父节点

    while (true) {
      int left = 2 * parent + 1;  // 左子节点
      int right = 2 * parent + 2; // 右子节点
      int largest = parent;       // 假设父节点是最大的

      if (left < n && arr[left] > arr[largest]) { // 如果左子节点大于最大值节点
        largest = left;
      }

      if (right < n &&
          arr[right] > arr[largest]) { // 如果右子节点大于最大值节点
        largest = right;
      }

      if (largest == parent)
        break; // 如果父节点是最大的，直接退出循环

      swap(arr[parent], arr[largest]); // 否则交换父节点和最大值节点
      parent = largest;                // 将最大值节点设为父节点，继续向上调整
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    // 将当前最大值（堆顶）换到数组末尾
    swap(arr[0], arr[i]);

    // 对剩下的元素重新调整堆顶
    int parent = 0;
    while (true) {
      int left = 2 * parent + 1;
      int right = 2 * parent + 2;
      int largest = parent;

      // 堆的大小缩小为i
      if (left < i && arr[left] > arr[largest]) {
        largest = left;
      }

      if (right < i && arr[right] > arr[largest]) {
        largest = right;
      }

      if (largest == parent)
        break;

      swap(arr[parent], arr[largest]);
      parent = largest;
    }
  }
}

// ================= 简单测试 =================
int main() {
  int arr1[] = {12, 11, 13, 5, 6, 7};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  heapSort(arr1, n1);

  cout << "整型数组排序：";
  for (int i = 0; i < n1; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;

  // 同样适用于其他可比类型，如 double
  double arr2[] = {3.14, 1.41, 2.71, 0.99};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  heapSort(arr2, n2);

  cout<<"浮点数组排序：";
  for(int i=0;i<n2;i++){
    cout<<arr2[i]<<" ";
  }
  cout<<endl;

  return 0;
}