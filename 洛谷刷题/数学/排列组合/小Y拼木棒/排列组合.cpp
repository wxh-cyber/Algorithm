/**
 *  @link https://www.luogu.com.cn/problem/P3799
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
const ll MOD=1e9+7;

int n,maxa;                                    // n表示所有边的数量，maxa表示最大的边的长度
ll ans;                                        // ans表示最终的答案
int a[MAXN],num[MAXN];                         // 数组a存储所有的边的长度，num数组存储长度为i的边的数量

/**
 *  @brief 求组合数
 *  @param  n  从n个数中取
 *  @param  k  从n个数中取k个数
 *  @return    组合数
 *  @note 注意，本题实际上只会在1和2中选取，因此可以直接使用特判写法
 */
ll combine(ll n,ll k){
    //求得从n个数中取出k个数的组合
    //此处k=1 / 2，用了特判写法。
    //k = 1 时，C(x, 1) = x;
    //k = 2 时，C(x, 2) = x * (x - 1) / 2;
    return k==1ll?n:(n*(n-1ll)/2ll)%MOD;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        num[a[i]]++;
    }

    for(int i=2;i<=maxa;i++){                                     //枚举两根相等的边
        if(num[i]>=2ll){
            // 注意这里不要写成ans=(ans+combine(num[i],2))%MOD;
            // 这是考虑到仅仅有两根相等的边的情况，如果第三条边没有符合要求的，则不应该包括在ans内
            ll times=combine(num[i],2)%MOD;
            for(int j=1;j<=i/2;j++){
                //若第三条边由两条等长的边构成
                if(j!=i-j&&num[j]>=1&&num[i-j]>=1){
                    ans+=times*combine(num[j],1)*combine(num[i-j],1)%MOD;
                }

                //若第三条边由一条长边和一条短边构成
                if(j==i-j&&num[j]>=2){
                    ans+=times*combine(num[j],2)%MOD;
                }

                //对答案取模
                ans%=MOD;
            }
        }
    }

    printf("%lld",ans);
    
    return 0;
}