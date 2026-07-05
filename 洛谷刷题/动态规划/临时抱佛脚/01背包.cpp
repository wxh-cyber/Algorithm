/**
 *  @link https://www.luogu.com.cn/problem/P2392
 */

#include <iostream>
#include <algorithm>
using namespace std;

int sum,t;                                                 // sum表示当前一科的作业总时间，t是最终答案
int a[5],homework[25];                                     // 数组a存储每科的作业数量，数组homework存储每科的作业时间
int dp[2501];                                              // dp数组用于01背包

int main(){
    for(int i=1;i<=4;i++){                                 // 输入每科的作业数量
        cin>>a[i];
    }

    for(int i=1;i<=4;i++){
        sum=0;                                             // 初始化sum为0

        for(int j=1;j<=a[i];j++){
            cin>>homework[j];
            sum+=homework[j];
        }

        // 01背包
        for(int j=1;j<=a[i];j++){
            for(int k=sum/2;k>=homework[j];k--){
                dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);
            }
        }

        // 01背包的本质是在总容量最多为sum/2的情况下，尽可能地装满背包，这样能保证另一侧的时间尽可能少
        t+=sum-dp[sum/2];

        // 清空dp数组
        for(int j=0;j<=sum/2;j++){
            dp[j]=0;
        }
    }
    
    cout<<t;
    
    return 0;
}