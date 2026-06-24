#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief 归并排序
 *  @param arr 待排序的数组
 *  @param tmp 辅助数组
 *  @param left 左半部分起始索引
 *  @param mid 左半部分结束索引
 *  @param right 右半部分结束索引
 *  @return 无
 *  @note 时间复杂度：O(nlogn)，空间复杂度：O(n)
 *  @note 稳定排序
 */
template<typename T>
void merge(vector<T>& arr,vector<T>& tmp,int left,int mid,int right){
    int i=left;                                   //左半部分起始索引
    int j=mid+1;                                  //右半部分起始索引
    int k=left;                                   //辅助数组的起始索引

    // 比较两个子区间的元素，将较小的放入辅助数组
    // 使用 <= 保证排序的稳定性
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            tmp[k++]=arr[i++];
        }else{
            tmp[k++]=arr[j++];
        }
    }

    //将左半部分剩余元素放入辅助数组
    while(i<=mid){
        tmp[k++]=arr[i++];
    }

    //将右半部分剩余元素放入辅助数组
    while(j<=right){
        tmp[k++]=arr[j++];
    }

    //将排好序的辅助数组拷贝回原数组
    for(int p=left;p<=right;p++){
        arr[p]=tmp[p];
    }
}

/**
 *  @brief 归并排序辅助函数
 *  @param arr 待排序的数组
 *  @param tmp 辅助数组
 *  @param left 左半部分起始索引
 *  @param right 右半部分结束索引
 *  @return 无
 *  @note 时间复杂度：O(nlogn)，空间复杂度：O(n)
 */
template<typename T>
void mergeSortHelper(vector<T>& arr,vector<T>& tmp,int left,int right){
    //递归出口：区间长度为1或0
    if(left>=right) return;

    int mid=left+(right-left)/2;                //防止数组下标溢出

    mergeSortHelper(arr,tmp,left,mid);
    mergeSortHelper(arr,tmp,mid+1,right);

    //合并：将两个有序数组合并回原数组arr
    merge(arr,tmp,left,mid,right);
}

/**
 *  @brief 归并排序
 *  @param arr 待排序的数组
 *  @return 无
 *  @note 时间复杂度：O(nlogn)，空间复杂度：O(n)
 */
template<typename T>
void mergeSort(vector<T>& arr){
    if(arr.empty()) return;

    // 预先分配好辅助数组，避免在递归中频繁 new/delete 造成开销
    vector<T> tmp(arr.size());
    mergeSortHelper(arr,tmp,0,arr.size()-1);
}

// ==================== 测试用例 ====================
int main(){
    //测试整数
    vector<int> nums={38, 27, 43, 3, 9, 82, 10};
    mergeSort(nums);

    cout<<"Sorted integers:";
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;

    //测试浮点数
    vector<double> doubles={3.14, 1.41, 2.71, 0.99};
    mergeSort(doubles);

    cout<<"Sorted doubles:";
    for(double d:doubles){
        cout<<d<<" ";
    }
    cout<<endl;

    return 0;
}