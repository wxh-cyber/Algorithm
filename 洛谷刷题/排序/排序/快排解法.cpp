/**
 *  @link https://www.luogu.com.cn/problem/P1177
 */

 /** 
 #include<iostream>
 #include<algorithm>
 using namespace std;
 
 const long long MAXN=1e5+10;
 
 int n;
 long long num[MAXN];
 
 int partition(long long arr[],int low,int high){
     long long pivot=arr[high];
     int i=low-1;
 
     for(int j=low;j<high;j++){
         if(arr[j]<=pivot){
             i++;
             swap(arr[i],arr[j]);
         }
     }
 
     swap(arr[i+1],arr[high]);
     return i+1;
 }
 
 void quickSort(long long arr[],int low,int high){
     if(low<high){
         int pi=partition(arr,low,high);
 
         quickSort(arr,low,pi-1);
         quickSort(arr,pi+1,high);
     }
 }
 
 int main(){
     cin>>n;
     for(int i=0;i<n;i++){
         cin>>num[i];
     }
 
     quickSort(num,0,n-1);
 
     for(int i=0;i<n;i++){
         if(i!=n-1){
             cout<<num[i]<<" ";
         }else {
             cout<<num[i];
         }
     }
     
     return 0;
 }

 运行结果：后三个例子会超时
*/

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int MAXN=1e5+10;

int n;
long long num[MAXN];

/**
 * @brief 插入排序
 * @param arr 待排序数组
 * @param l 左边界
 * @param r 右边界
 * @return void
 */
void insertionSort(long long arr[],int l,int r) {
    for(int i=l+1;i<=r;i++){
        long long key=arr[i];
        int j=i-1;
        while(j>=l&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

/**
 * @brief 三数取中
 * @param arr 待排序数组
 * @param l 左边界
 * @param r 右边界
 * @return long long 三数中的中位数
 */
long long medianOfThree(long long arr[],int l,int r){
    int mid=l+(r-l)/2;

    if(arr[l]>arr[mid]) swap(arr[l],arr[mid]);
    if(arr[l]>arr[r]) swap(arr[l],arr[r]);
    if(arr[mid]>arr[r]) swap(arr[mid],arr[r]);

    return arr[mid];
}

/**
 * @brief 快速排序
 * @param arr 待排序数组
 * @param l 左边界
 * @param r 右边界
 * @return void
 */
void quickSort(long long arr[],int l,int r) {
    if(l>=r) return;

    //小区间优化
    if(r-l+1<=16){
        insertionSort(arr, l, r);
        return;
    }

    long long pivot=medianOfThree(arr,l,r);

    int lt=l,i=l,gt=r;
    while(i<=gt){
        if(arr[i]<pivot){
            swap(arr[lt],arr[i]);
            lt++;
            i++;
        }else if(arr[i]>pivot){
            swap(arr[i],arr[gt]);
            gt--;
        }else {
            i++;
        }
    }

    quickSort(arr,l,lt-1);
    quickSort(arr,gt+1,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    quickSort(num,0,n-1);

    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<num[i];
    }

    return 0;
}