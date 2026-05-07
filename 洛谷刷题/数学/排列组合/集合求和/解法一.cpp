/**
 *    @link https://www.luogu.com.cn/problem/P2415
 */
 #include<iostream>
 #include<cmath>
 using namespace std;

 int a[31],i=0,j;
 long long s=0;
 int main(){
    while(cin>>a[i++]);
    for(j=0;j<i;j++){
        s+=a[j];
    }
    s*=pow(2,i-2);
    /**
     *  思考：为什么解法一是i-2，而解法二是i-1？
     *  这是因为在解法一中，对于while(cin>>a[i++])，i++会先沿用当前的i，再自增
     *  即使最后一次读入失败了，i也已经加了1
     *  所以i-2实际上是补偿了前面多加的1，底层还是乘以2的n-1次方
     */
    cout<<s;

    return 0;
 }