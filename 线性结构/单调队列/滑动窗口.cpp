#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 *  @brief maxSlidingWindow - 滑动窗口最大值函数
 *  @param {vector<int>} nums - 全体遍历的数组
 *  @param {int} k - 滑动窗口最大值范围
 *  @return {vector<int>} - result - 滑动窗口全程最大值
 *  @note
 *    时间复杂度 O(n)：每个元素最多入队一次、出队一次，虽然内层有 while 循环，但总的弹出次数不超过 n，属于"均摊分析"。
 *    空间复杂度 O(k)：队列中最多同时存在 k 个下标。
 */
vector<int> maxSlidingWindow(vector<int>& nums,int k){
    vector<int> result;                                             //result用于存储滑动窗口全程最大值
    deque<int> dq;                                                  //dq存储的是下标，且这些下标对应的具体数值在dq中单调递减
    //队首是当前窗口最大值的下标

    for(int i=0;i<nums.size();i++){

        // ---------- 第 1 步：清理队首 ----------
        // 如果队首下标已经滑出窗口左边界（窗口是 [i-k+1, i]），
        // 说明它已经不在窗口内，必须移除，否则它可能是过期的"旧最大值"
        // 判断条件：dq.front() <= i - k 等价于 dq.front() < i - k + 1
        if(!dq.empty()&&dq.front()<=i-k){
            dq.pop_front();
        }

        // ---------- 第 2 步：清理队尾（维持单调性） ----------
        // 只要队尾对应的值 <= 当前元素 nums[i]，就把它弹掉。
        // 原因：这些元素比 nums[i] 小（或相等），而且会比 nums[i] 先滑出窗口。
        //       所以在 nums[i] 还在窗口里的这段时间，它们绝不可能成为最大值，
        //       留着只会浪费空间，直接淘汰。
        // 注意循环弹出，可能一次淘汰多个
        while(!dq.empty()&&nums[dq.back()]<nums[i]){
            dq.pop_back();
        }

         
        // ---------- 第 3 步：当前元素入队 ----------
        // 经过上一步清理后入队，保证队列仍然单调递减
        dq.push_back(i);                                            

        // ---------- 第 4 步：收集结果 ----------
        // 只有当窗口完整形成后（即 i >= k-1 时），才开始记录答案
        if(i>=k-1){
            result.push_back(nums[dq.front()]);                     //队首就是窗口最大值
        }
    }

    return result;                                                  //返回最终结果
}

int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;

    vector<int> ans=maxSlidingWindow(nums,k);
    for(int x:ans){
        cout<<x<<" ";
        // 输出: 3 3 5 5 6 7
    }

    return 0;
}