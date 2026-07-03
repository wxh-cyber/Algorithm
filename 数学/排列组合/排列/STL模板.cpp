#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief 打印容器中的元素
 * @param vec 要打印的容器
 * @tparam T 容器中元素的类型
 * @return void
 */
template<typename T>
void print(const vector<T>& vec){
    for(const auto& x:vec){
        cout<<x<<" ";
    }
    cout<<endl;
}

/**
 * @brief 生成容器的所有排列
 * @return void
 */
void permutation_example(){
    // 1. 初始化数据
    vector<int> v={1,2,3};

    // 2. 关键步骤：先排序，生成字典序最小的排列
    sort(v.begin(),v.end());

    // 3. 循环生成所有排列
    // do-while 结构确保打印第一个排列（初始状态）
    do{
        print(v);
    }while(next_permutation(v.begin(),v.end()));

    // 如果要生成逆序的排列，可以使用 std::prev_permutation
}

int main(){
    permutation_example();

    return 0;
}