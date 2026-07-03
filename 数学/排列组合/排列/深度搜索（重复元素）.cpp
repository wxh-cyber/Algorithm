#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  @brief 深度搜索的基本框架
 *  @param nums 输入的数组
 *  @param used 标记数组，记录元素是否已经被使用
 *  @param path 记录当前路径
 *  @param res 记录所有路径
 *  @return void
 *  @note 时间复杂度 O(n!)，空间复杂度 O(n)
 */
template<typename T>
void dfs_unique(vector<T>& nums,vector<int>& used,vector<T>& path,vector<vector<T>>& res){
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }

    for(int i=0;i<nums.size();i++){
        // 剪枝核心：如果当前元素已用，或者(当前元素等于前一个 且 前一个未用)，则跳过
        // 可以理解为，对于所有相同的元素，该算法本质上是将它们都视为了一个单独的整体，从而达到去重效果
        if(used[i]||(i>0&&nums[i]==nums[i-1]&&!used[i-1])) continue;

        used[i]=true;
        path.push_back(nums[i]);

        dfs_unique(nums,used,path,res);

        path.pop_back();
        used[i]=false;
    }
}

/**
 *  @brief 打印二维数组
 *  @param res 二维数组
 *  @return void
 *  @note 时间复杂度 O(n^2)，空间复杂度 O(1)
 */
template<typename T>
void print(const vector<vector<T>>& res){
    for(const auto& v:res){
        for(const auto& x:v){
            cout<<x<<" ";
        }

        cout<<endl;
    }

    cout<<"Total: "<<res.size()<<endl<<endl;
}

int main(){
    vector<int> nums={1,2,3,4,5};

    //关键：去重前必须先排序
    sort(nums.begin(),nums.end());

    vector<vector<int>> res;
    vector<int> path;
    vector<int> used(nums.size(),false);

    dfs_unique(nums,used,path,res);

    print(res);

    return 0;
}