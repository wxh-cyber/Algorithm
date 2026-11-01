/**
 *  @link https://www.luogu.com.cn/problem/P1102
 */

#include <iostream>
#include <map>
typedef long long LL;
using namespace std;

const int MAXN=2e5+5;

int n;                                                         //n表示数组长度
LL c,ans=0;                                                    //c表示差值，ans表示答案
LL nums[MAXN];                                                 //nums数组用于存储输入的数组
map<LL,LL> mp;                                                 //mp数组用于存储每个数出现的次数，是初始状态下出现的次数

int main() {
  cin >> n >> c;                                              //输入数组长度和差值
  for (int i = 0; i < n; i++) {
    cin >> nums[i];                                           //输入数组元素
    mp[nums[i]]++;                                            //记录初始状态下每个数出现的次数
    nums[i]-=c;                                               //将数组元素减去差值
  }

  for(int i=0;i<n;i++) {
    ans+=mp[nums[i]];                                         //统计每个数减去差值后出现的次数
  }

  cout << ans << endl;                                        //输出答案
  return 0;
}