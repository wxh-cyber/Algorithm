#include <iostream>
using namespace std;

/**
 *  @brief 选择排序
 *  @param arr 待排序的数组
 *  @param n 数组的长度
 *  @return 无
 */
void selectionSort(int arr[],int n){
    // i表示当前需要填入最小值的位置
    for(int i=0;i<n-1;i++){
        // 假设当前位置i就是最小值的位置
        int min_idx=i;

        //在i后面的元素中寻找真正的最小值
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;                                //更新最小值下标
            }
        }

        if(min_idx!=i){
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;                            //交换arr[i]和arr[min_idx]
        }
    }
}

/**
 *  @brief 打印数组
 *  @param arr 待打印的数组
 *  @param n 数组的长度
 *  @return 无
 */
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]); // 计算数组长度

    cout << "排序前: ";
    print(arr, n);

    selectionSort(arr, n);

    cout << "排序后: ";
    print(arr, n);

    return 0;
}