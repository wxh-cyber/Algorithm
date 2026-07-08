/**
 *  @link https://www.luogu.com.cn/problem/P1158
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;                                                 //导弹的数量
ll x11, y11, x22, y22;                                 //两套导弹系统的坐标
ll ans = 0x3f3f3f3f;                                   // 答案
int dist1[MAXN], dist2[MAXN], dp[MAXN + 1];            // dist1[i] 表示第 i 个导弹到第一个系统的距离，dist2[i] 表示第 i 个导弹到第二个系统的距离，dp[i] 表示第 i 个导弹到第二个系统的距离的最大值

/**
 *  @brief 计算两个点之间的距离
 *  @param x 第一个点的横坐标
 *  @param y 第一个点的纵坐标
 *  @param cx 第二个点的横坐标
 *  @param cy 第二个点的纵坐标
 *  @return 两个点之间的距离平方
 */
inline ll distance(ll x, ll y, ll cx, ll cy) {
  return (x - cx) * (x - cx) + (y - cy) * (y - cy);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> x11 >> y11 >> x22 >> y22 >> n;                             // 输入两个导弹系统的坐标和导弹的数量
  vector<pair<ll,ll>> a(n+1);                                // 存储每个导弹距离到两个导弹系统的距离
  for(int i=1;i<=n;i++){
    ll x,y;    
    cin>>x>>y;                                                      // 输入导弹的坐标

    int d1=distance(x,y,x11,y11);                            // 计算导弹到第一个系统的距离
    int d2=distance(x,y,x22,y22);                            // 计算导弹到第二个系统的距离

    a[i]={d1,d2};                                      // 存储导弹到两个系统的距离
  }

  sort(a.begin()+1,a.end());                            // 按照导弹到第一个系统的距离从小到大排序

  //填充 dis1, dis2 数组（便于理解 DP 过程）
  for(int i=1;i<=n;i++){
    dist1[i]=a[i].first;
    dist2[i]=a[i].second;
  }

  //初始化 dp 数组
  memset(dp,0,sizeof(dp));
  // 计算 dp 数组
  for(int i=n;i>0;i--){
    dp[i]=max(dp[i+1],dist2[i]);          //后缀最大值
  }
  
  for(int i=0;i<=n;i++){
    ll cost1=(i==0?0:dist1[i]);
    ll cost2=dp[i+1];
    ans=min(ans,cost1+cost2);
  }

  cout<<ans<<endl;

  return 0;
}