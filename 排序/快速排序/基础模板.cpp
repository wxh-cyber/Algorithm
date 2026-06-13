#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief partition函数，用于划分数组
 * @param arr 待划分的数组
 * @param low 划分的起始下标
 * @param high 划分的结束下标
 * @return 基准值的下标
 */
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];                       //基准值选择最后一个元素
    int i=low-1;                               //i指向小于pivot的区域的最后一个元素

    //j从low遍历到high-1
    for(int j=low;j<high;j++){
        //如果当前元素小于等于pivot
        if(arr[j]<=pivot){
            i++;                               //小于等于pivot的区域扩大一格
            swap(arr[i],arr[j]);               //把小元素换到前面
        }
    }

    // 循环结束后，[low, i] 都小于 pivot，[i+1, high-1] 都大于 pivot
    // 把 pivot (也就是 arr[high]) 换到中间正确的位置
    std::swap(arr[i + 1], arr[high]);
    
    // 返回 pivot 的最终下标
    return i + 1; 
}

/**
 * @brief 快速排序函数
 * @param arr 待排序的数组
 * @param low 排序的起始下标
 * @param high 排序的结束下标
 * @return void
 */
void quickSort(vector<int>& arr,int low,int high){
    if(low<high){
        //1.划分，获取pivot的位置
        int pi=partition(arr,low,high);

        //2.递归排序pivot左边的子数组
        quickSort(arr,low,pi-1);

        //3.递归排序pivot右边的子数组
        quickSort(arr,pi+1,high);
    }
}

int main(){
    vector<int> arr={10,7,8,9,1,5};
    int n=arr.size();

    cout<<"原始数组：";
    for(int x:arr) {
        cout<<x<<" ";
    }
    cout<<"\n";

    quickSort(arr,0,n-1);

    cout<<"排序后的数组：";
    for(int x:arr) {
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}