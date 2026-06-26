#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 希尔排序
 * @tparam T 数组元素类型
 * @param arr 待排序的数组
 * @return 无返回值
 */
template<typename T>
void shellSort(vector<T>& arr){
    int n=arr.size();
    if(n<=1) return;

     
    // 1. 确定增量，初始增量通常为数组长度的一半
    for(int gap=n/2;gap>0;gap/=2){

        // 2. 从 gap 开始，对每个子序列进行插入排序
        // 这里的逻辑是：虽然间隔是 gap，但我们是按顺序从 gap 位置开始向后遍历
        // 这样可以一次性处理所有子序列的插入操作，代码更简洁
        for(int i=gap;i<n;i++){
            T temp=arr[i];                            // 待插入的元素
            int j=i;

            // 3. 插入排序的核心逻辑
            // 同一组内的元素间隔为 gap
            // 如果前面的元素比 temp 大，则后移
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }

            // 找到合适的位置插入
            arr[j]=temp;
        }
    }
}

// ==================== 测试用例 ====================
int main(){
    //测试整数
    vector<int> nums = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};

    cout<<"排序前：";
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;

    shellSort(nums);

    cout<<"排序后：";
    for(int num:nums){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}