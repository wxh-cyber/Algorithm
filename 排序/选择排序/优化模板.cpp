#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <utility>     
using namespace std;

/**
 *  utility:内部包含了swap函数。
 */

 /**
  * @brief selectionSort - 选择排序
  * @param arr - 待排序的数组
  * @param n - 数组的长度
  * @return 无
  * @note typename T 代表元素类型，size_t n 代表数组的长度
  */
 template<typename T,size_t n>
 void selectionSort(T (&arr)[n]){
    for(size_t i=0;i<n-1;i++){
        size_t minIndex=i;                               // 假设当前位置的元素就是最小的

        //内层循环：在未排序区间[i+1,n-1]中寻找真正的最小元素
        for(size_t j=i+1;j<n;j++){
            // 如果找到比当前最小值更小的元素，更新最小值的索引
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }

        //如果最小值不是当前位置的元素，交换它们
        if(minIndex!=i){
            swap(arr[i],arr[minIndex]);
        }
    }
 }

 /**
  *  @brief selectionSort - 选择排序
  *  @param first 指向待排序区间的起始位置
  *  @param last 指向待排序区间的结束位置
  *  @return 无
  *  @note 
  *      针对标准容器（如vector）的重载版本，使用迭代器
  *      模板参数：RandomAccessIterator 代表随机访问迭代器类型
  */
 template<typename RandomAccessIterator>
 void selectionSort(RandomAccessIterator first,RandomAccessIterator last){
    //空容器直接返回
    if(first==last) return;

    for(RandomAccessIterator i=first;i!=last-1;i++){
        RandomAccessIterator minIt=i;                            //假设当前迭代器指向的元素最小

        //在剩余未排序部分寻找最小值
        for(RandomAccessIterator j=i+1;j!=last;j++){
            if(*j<*minIt){
                minIt=j;
            }
        }

        //交换最小值到当前位置
        if(minIt!=i){
            swap(*i,*minIt);
        }
    }
 }

 /**
  *  @brief print - 打印数组
  *  @param arr - 待打印的数组
  *  @param n - 数组的长度
  *  @return 无
  *  @note 打印数组的辅助模板函数
  */
 template<typename T,size_t n>
 void print(const T (&arr)[n]){
    for(size_t i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
 }

int main(){
    // 1.测试1：整型数组
    int intArr[]={64, 25, 12, 22, 11};
    cout<<"排序前(int):";
    print(intArr);
    selectionSort(intArr);                        //调用数组版模板
    cout<<"排序后(int):";
    print(intArr);

    // 2.测试2：浮点型数组
    double doubleArr[]={3.14, 1.618, 2.718, 0.577, 4.669};
    cout<<"排序前(double):";
    print(doubleArr);
    selectionSort(doubleArr);
    cout<<"排序后(double):";
    print(doubleArr);

    // 3.测试3：字符串数组
    string strArr[]={"banana", "apple", "orange", "grape", "cherry"};
    cout<<"排序前(string):";
    print(strArr);
    selectionSort(strArr);
    cout<<"排序后(string):";
    print(strArr);

    // 4.测试4：标准容器（vector）
    vector<int> vec={9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout<<"排序前(vector):";
    for(int v:vec){
        cout<<v<<" ";
    }
    cout<<endl;

    selectionSort(vec.begin(),vec.end());

    cout<<"排序后(vector):";
    for(int v:vec){
        cout<<v<<" ";
    }
    cout<<endl;

    return 0;
}