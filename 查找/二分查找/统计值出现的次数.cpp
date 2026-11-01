#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief lowerBound函数 - 返回第一个大于等于target的下标
 *  @param {vector<int>} v - 有序数组
 *  @param {int} target - 目标值
 *  @return {int} - 第一个大于等于target的下标
 *  @note 左闭右开区间[left,right)
 *  @note 注意循环条件为left<right
 *  @note left即为第一个大于等于target的下标
 *  @note 时间复杂度为O(logn)
 *  @note 空间复杂度为O(1)
 *  @note 适用于有序数组
 *  @note 适用于查找第一个大于等于target的下标
 *  @note 
 *    这里采用了左闭右开区间[left, right)的写法，循环条件为left < right。
 *    初始时right设为数组长度而非长度减一，这样可以避免遗漏最后一个元素的检查。在每次循环中，计算中间下标mid。
 *    如果v[mid] < target，说明目标只可能在右半区，因此将left更新为mid + 1；否则（v[mid] >= target），说明目标在左半区（包括mid本身），因此将right更新为mid。
 *    当循环结束时，left即为第一个大于等于target的元素下标。
 *    如果target大于数组中所有元素，left最终会等于数组长度，表示没有找到符合条件的元素（应插入在末尾）
 */
int lowerBound(const vector<int>& v,int target){
    int left=0,right=v.size();                        //左闭右开区间[left,right)

    while(left<right){                                //注意循环条件为left<right
        int mid=left+(right-left)/2;
        if(v[mid]<target){
            left=mid+1;                               //v[mid]<target，目标在右半区
        }else{
            right=mid;                                //v[mid]>=target，目标在左半区，或者就是mid
        }
    }

    return left;                                      //left即为第一个大于等于target的下标
}

/**
 *  @brief upperBound函数 - 返回第一个大于target的下标
 *  @param {vector<int>} v - 有序数组
 *  @param {int} target - 目标值
 *  @return {int} - 第一个大于target的下标
 *  @note 左闭右开区间[left,right)
 *  @note 注意循环条件为left<right
 *  @note left即为第一个大于target的下标
 *  @note 时间复杂度为O(logn)
 *  @note 空间复杂度为O(1)
 *  @note
 *    该实现与lowerBound非常类似，区别在于while循环内部的判断条件。
 *    这里使用了v[mid] <= target来判断：如果中间元素小于等于目标值，则目标只可能在右半区，将left更新为mid + 1；否则（v[mid] > target），目标在左半区（包括mid），将right更新为mid。
 *    循环结束后，left即为第一个大于target的元素下标。如果数组中所有元素都小于等于target，left最终会等于数组长度，表示没有找到大于目标的元素。
 */
int upperBound(const vector<int>& v,int target){
    int left=0,right=v.size();                        //左闭右开区间[left,right)

    while(left<right){
        int mid=left+(right-left)/2;
        if(v[mid]<=target){
            left=mid+1;                               // v[mid] <= target，目标在右半区
        }else{
            right=mid;                                // v[mid] > target，目标在左半区或就是mid
        }
    }

    return left;                                      // left即为第一个大于target的下标
}

/**
 *  @brief count - 统计指定元素个数
 *  @param {vector<int>} 
 */
int countNum(const vector<int>& v,int target){
    int first=lowerBound(v,target);                   //第一个 >= target的下标
    int last=upperBound(v,target);                    //第一个 > target 的下标
    return last-first;                                //相减即为等于target的元素个数
}

int main(){
    vector<int> arr = {10, 20, 30, 30, 30, 40, 50};
    int target = 30;
    int count=countNum(arr,target);

    cout << "Number of occurrences of " << target << ": " << count << endl;

    return 0;
}