#include <iostream>
using namespace std;

/**
 * @brief 插入排序
 * @param arr 数组
 * @param n 数组长度
 * @return 无
 */
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

int main(){
    int arr[]={5,2,9,1,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}