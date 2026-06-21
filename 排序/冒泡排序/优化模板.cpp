#include <iostream>
using namespace std;

/**
 * @brief 冒泡排序
 * @param arr 数组
 * @param n 数组长度
 * @return void
 */
template<typename T>
void bubbleSort(T arr[],int n){
    //外层循环控制需要比较的趟数，n-1趟即可排好序
    for(int i=0;i<n-1;i++){
        //标记这一趟是否发生过交换
        bool swapped=false;

        //内层循环进行相邻元素比较
        //n-i-1是因为每经过一趟，最大的元素已经“浮”到末尾了，不需要再比较
        for(int j=0;j<n-1-i;j++){
            //如果前一个元素大于后一个元素，则交换它们（把大的往后推）
            if(arr[j]>arr[j+1]){
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                swapped=true;
            }
        }

        // 如果这一趟没有发生任何交换，说明数组已经完全有序，提前退出
        if(!swapped){
            break;
        }
    }
}

/**
 *  @brief 打印数组
 *  @param arr 数组
 *  @param n 数组长度
 *  @return void
 */
template<typename T>
void print(T arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // 测试 1：整型数组
    int intArr[] = {5, 1, 4, 2, 8};
    int n1 = sizeof(intArr) / sizeof(intArr[0]);
    cout << "排序前 (int): ";
    print(intArr, n1);
    bubbleSort(intArr, n1);
    cout << "排序后 (int): ";
    print(intArr, n1);

    // 测试 2：浮点型数组
    double doubleArr[] = {3.14, 1.618, 2.718, 0.577};
    int n2 = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "排序前 (double): ";
    print(doubleArr, n2);
    bubbleSort(doubleArr, n2);
    cout << "排序后 (double): ";
    print(doubleArr, n2);

    return 0;
}