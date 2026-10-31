#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief upperBound - 二分查找右边界
 *  @param {vector<int>} nums - 二分查找数组
 *  @param {int} target - 查找数字对象
 *  @return {int} ans - 右侧边界
 */
int upperBound(vector<int> &nums, int target) {
  int left = 0, right = nums.size();
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

int main() {
  vector<int> nums = {1, 3, 5, 5, 5, 7, 9};
  int target = 5;

  cout << "upperBound:   " << upperBound(nums, target)
       << endl; // 5（5的下一个）

  return 0;
}