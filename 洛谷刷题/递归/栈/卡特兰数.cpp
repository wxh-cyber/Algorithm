/**
 *  @link https://www.luogu.com.cn/problem/P1044
 */

 /**
  *  @note 注意：long long最大约为9.22*10^18，因此只要2n>=21，即n>=11，阶乘就溢出了。
  *             因此本题采用边乘边除的形式，避免溢出。
  *
  *  卡特兰数：C(2n,n)/(n+1)，具体推导过程请见算法模板的组合部分的卡特兰数部分。
  */

 #include <iostream>
 typedef long long ll;
 using namespace std;

 int n;

 /* 
 // 采用递归的方法计算阶乘，会导致栈溢出
 ll factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
 }

 ll combine(int n,int m){
    return factorial(n)/(factorial(m)*factorial(n-m));
 }
 */


 ll ktl(int n){
    ll ans=1;

    for(int i=1;i<=n;i++){
        ans=ans*(n+i)/i;
    }

    return ans/(n+1);
 }

 int main(){
    cin>>n;

    cout<<ktl(n);

    return 0;
 }