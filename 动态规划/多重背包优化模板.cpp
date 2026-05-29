#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=1005;                   //物品种类上限
const int MAXM=2005;                   //背包容量上限

int dp[MAXN];                          //dp数组，一维空间优化版
struct Node {
    int w;                             //重量
    int v;                             //价值
};

int main(){
    int n,m;                           //n物品种类数，m背包容量
    if(cin>>n>>m){
        vector<Node> items;            //存储拆分后的所有物品

        for(int i=1;i<=n;i++){
            int w,v,s;
            cin>>w>>v>>s;              //读入重量、价值、数量

            //对数量s进行二进制拆分
            for(int k=1;k<=s;k<<=1){
                s-=k;                  //减去已经拆分出的数量
                items.push_back({k*w,k*v});        //存入新物品：重量=k*w，价值=k*v
            } 

            //处理剩余的数
            if(s>0){
                items.push_back({s*w,s*v});        //存入新物品：重量=s*w，价值=s*v
            }
        }

        //0-1背包求解过程
        //此时问题已经转化为标准的0-1背包，物品总数为items.size()
        for(const auto& item:items){
            //倒序遍历，确保每个物品只被选中一次
            for(int j=m;j>=item.w;j--){
                dp[j]=max(dp[j],dp[j-item.w]+item.v);        //状态转移方程：dp[j]=max(dp[j],dp[j-item.w]+item.v)
            }
        }

        cout<<dp[m]<<endl;        //输出最大价值
    }

    return 0;
}