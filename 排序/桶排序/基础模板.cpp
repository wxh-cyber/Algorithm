#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  @brief 桶排序函数
 *  @param arr 待排序的数组
 *  @return void
 */
void bucketSort(vector<int>& arr){
    //如果数组为空，则直接返回
    if(arr.empty()) return;

    // 1.找出最大值和最小值，用于确定数据范围
    int maxVal=*max_element(arr.begin(),arr.end());
    int minVal=*min_element(arr.begin(),arr.end());

    // 2.设定桶的数量（这里固定用5个桶）
    int bucketCount=5;
    vector<vector<int>> buckets(bucketCount);

    // 3.将数据分配到各个桶中
    for(int val:arr){
        //计算当前值应该放到第几个桶
        //公式：(当前值-最小值)*(桶数-1)/(最大值-最小值)
        int index=(val-minVal)*(bucketCount-1)/(maxVal-minVal);
        buckets[index].push_back(val);
    }

    // 4.对每个桶内的数据进行排序
    for(int i=0;i<bucketCount;i++){
        sort(buckets[i].begin(),buckets[i].end());
    }

    // 5.将各个桶中的数据按顺序倒回原数组
    int idx=0;
    for(int i=0;i<bucketCount;i++){
        for(int val:buckets[i]){
            arr[idx++]=val;
        }
    }
}

// 测试代码
int main(){
    vector<int> arr = {42, 32, 33, 52, 37, 47, 51, 10, 99, 1};

    cout << "排序前: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    bucketSort(arr);

    cout << "排序后: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    return 0;
}