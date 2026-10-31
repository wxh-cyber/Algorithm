/**
 *  @link https://www.luogu.com.cn/problem/P2249
 */

#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN=1e6+5;

int n,m;                                              //n表示数字总数，m表示查询次数
ll q;                                                 //q表示每次要查询的数字对象
ll nums[MAXN];                                        //nums数组存放所有数

/**
 *  @brief search - 二分查找，优先返回最左侧符合要求的结果
 *  @param {ll} nums[] - 查找的数组对象
 *  @param {ll} target - 查找的数字对象
 *  @return {int} ans - 返回的下标结果
 */
int search(ll nums[],ll target){
    int left=1,right=n;                                       //初始化左侧指针left和右侧指针right1
    int ans=-1;                                               //初始时，答案为-1

    while(left<=right){
        int mid=left+(right-left)/2;                          //每次mid指向当前区间的中间值
        if(nums[mid]>=target){                                //如果所求的目标值位于左侧区间或者中间
            /**
             *  @note 
             *    事实上，如果不考虑优先返回最左侧结果，可以参考二分查找基础版的模板，将mid、左侧区间和右侧区间分别写成三个不同的条件分支。
             *    但是由于本题已经限定了优先返回最左侧结果，因此在进行条件判定时，将mid和左侧区间两种情况视为同一个条件。
             *    与此同时，通过ans记录下每次相等状态下的mid的最新坐标。这可以在保证如果初始状态下，nums[mid]==target的情况下，依然可以在左侧区间不断递归查找，从而找到最左侧的结果。    
             */
            if(nums[mid]==target){                            //如果所求的目标值恰好位于中间，则先更新ans为mid
                ans=mid;
            }

            right=mid-1;                                      //更新右侧指针
        }else{
            left=mid+1;                                       //如果所求的目标值位于右侧区间，则更新左侧指针
        }
    }

    return ans;                                               //返回最终结果
}

int main(){
    cin>>n>>m;                                                 //输入数字数量n和查询次数m
    for(int i=1;i<=n;i++){
        cin>>nums[i];                                          //输入所有数据
    }

    while(m--){
        cin>>q;                                                //每次都输入一个查询对象
        cout<<search(nums,q)<<" ";                      //输出最终结果
    }
    
    return 0;
}