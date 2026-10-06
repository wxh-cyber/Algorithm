/**
 *  @link https://www.luogu.com.cn/problem/P1029
 */

 #include <iostream>
 #include <cmath>
 #include <algorithm>
 using namespace std;

 // algorithm：提供__gcd方法用于快速返回两数的最大公因数。

 //由于单个的m或者n的数据范围达到了10^5，因此需要开成long long的形式
 long long m,n;                               //m和n分别表示指定的最大公因数和最小公倍数
 long ans;                                    //ans记录最终的答案数量
 
 int main(){
    cin>>m>>n;

    if(m==n) ans--;                            //如果最大公因数和最小公倍数相同，则说明存在x==y的情况，此时需要减去重复情况

    n*=m;                                      //将两数的积存入n中
    for(long long i=1;i<=sqrt(n);i++){
        if(n%i==0&&__gcd(i,n/i)==m){
            ans+=2;
        }
    }

    cout<<ans;

    return 0;
 }