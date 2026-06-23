#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <functional>
using namespace std;

/**
 * @brief 插入排序
 * @param first 指向第一个元素的迭代器
 * @param last 指向最后一个元素的迭代器
 * @param comp 比较函数对象，用于比较两个元素的大小\
 * 默认为std::less<T>，即升序排序\
 * 如果需要降序排序，可以使用std::greater<T>
 * @return 无
 */
template<typename RandomAccessIterator,typename Compare>
void insertionSort(RandomAccessIterator first,RandomAccessIterator last,Compare comp){
    //空容器直接返回
    if(first==last) return;

    for(RandomAccessIterator it=first+1;it!=last;it++){
        //auto会自动推导出迭代器指向的值的类型
        auto key=std::move(*it);
        RandomAccessIterator j=it-1;

        //将大于key的元素往后移
        while(j>=first&&comp(key,*j)){
            *(j+1)=std::move(*j);
            j--;
        }

        *(j+1)=std::move(key);
    }
}

/**
 * @brief 插入排序
 * @param first 指向第一个元素的迭代器
 * @param last 指向最后一个元素的迭代器
 * @return 无
 */
template<typename RandomAccessIterator>
void insertionSort(RandomAccessIterator first,RandomAccessIterator last){
    //使用默认的比较函数less<T>
    insertionSort(first,last,less<decltype(*first)>());
}


//测试代码
int main(){
    //测试vector
    vector<int> vec={8,3,1,7,0};
    insertionSort(vec.begin(),vec.end());
    cout<<"Vector 排序：";
    for(int v:vec){
        cout<<v<<" ";
    }
    cout<<endl;

    //测试原生数组
    int arr[]={9,4,2,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    //降序排序
    insertionSort(arr,arr+n,greater<int>());
    cout<<"原生数组排序：";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}