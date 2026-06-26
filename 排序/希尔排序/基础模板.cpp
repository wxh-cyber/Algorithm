#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 希尔排序
 * @param arr 待排序的数组
 * @return 无返回值
 */
void shellSort(vector<int>& arr){
    int n=arr.size();

    // 1. gap：增量，从数组长度的一半开始，每次减半，直到为1
    for(int gap=n/2;gap>0;gap/=2){
        
        // 2.从gap位置开始往后遍历
        // 这实际上是在同时对多个子序列进行插入排序
        for(int i=gap;i<n;i++){
            int temp=arr[i];                   // 当前待插入的元素
            int j=i;

            // 3.插入排序逻辑
            // 同一组的元素间隔为gap
            // 如果前面的元素比temp大，就向后移动gap位
            while(j>=gap&&arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }

            // 插入到正确位置
            arr[j]=temp;
        }
    }
}

int main(){
    vector<int> nums={9, 1, 2, 5, 7, 4, 8, 6, 3, 5};

    shellSort(nums);

    for(int num:nums){
        cout<<num<<" ";
        // 输出: 1 2 3 4 5 5 6 7 8 9
    }

    return 0;
}