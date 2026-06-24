#include <iostream>
#include <vector>
using namespace std;

/**
 *  @brief 归并排序
 *  @param arr 待排序的数组
 *  @return 无
 *  @note 时间复杂度：O(nlogn)，空间复杂度：O(n)
 */
void mergeSort(vector<int>& arr){
    //递归出口：元素个数为1或0时，天然有序
    if(arr.size()<=1) return;

    //1.分：将数组从中间切成两半，并拷贝出左右两个子数组
    int mid=arr.size()/2;

    vector<int> left(arr.begin(),arr.begin()+mid);
    vector<int> right(arr.begin()+mid,arr.end());

    //2.治：递归排序左右两半
    mergeSort(left);
    mergeSort(right);

    //3.合：将两个有序数组合并回原数组arr
    int i=0,j=0,k=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<=right[i]){
            arr[k++]=left[i++];
        }else{
            arr[k++]=right[j++];
        }
    }

    //处理剩余元素
    while(i<left.size()) arr[k++]=left[i++]; 
    while(j<right.size()) arr[k++]=right[j++];
}

//测试
int main(){
    vector<int> arr={38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr);

    for(int num:arr){
        cout<<num<<" ";
    }
    // 输出: 3 9 10 27 38 43 82

    return 0;
}