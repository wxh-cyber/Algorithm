/**
 *  @link https://www.luogu.com.cn/problem/P1014
 */

 /**
  *  具体分析过程请参见数学推导。
  *  本方法是通过数学推导，从而省略了枚举循环的过程。
  */

 #include <iostream>
 #include <cmath>
 using namespace std;

 float n;
 int main(){
    cin>>n;
    int k=int(sqrt(n*2-1.75)+0.5);
    
    n-=k*(k-1)/2;

    if(k%2==1) 
        cout<<k-n+1<<'/'<<n;
	else 
        cout<<n<<'/'<<k-n+1;

    return 0;
 }