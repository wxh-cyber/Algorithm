#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief binarySearch - 二分查找
 *  @param {vector<int>} nums - 查找数组
 *  @param {int} target - 查找元素
 *  @return {int} mid - 查找元素对应下标
 *  @note 本模板在一个单调不减数列中查找元素时，如果有多个相同元素均位于初始状态下的中间位置，则不会查找到最左侧的元素。
 */
int binarySearch(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1; // 闭区间 [left, right]
  while (left <= right) {
    int mid = left + (right - left) / 2; // 防止 (left+right) 溢出
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      left = mid + 1; // 目标在右半部分
    } else {
      right = mid - 1; // 目标在左半部分
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 3, 5, 5, 5, 7, 9};
  int target = 5;

  cout << "binarySearch: " << binarySearch(nums, target)
       << endl; // 2（任一位置）
  return 0;
}