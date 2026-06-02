/**
 *  @link https://www.luogu.com.cn/problem/P1045
 */
 #include <iostream>
 #include <cmath>
 using namespace std;

 int p;                                                //2的幂次
 unsigned long long a[510]={0,1},t;                    //a数组用于存储最后500位，t用于存储进位

 int main(){
     cin>>p;
     cout<<(int)(p*log10(2))+1<<endl;                  //计算出最终的位数

     for(;p>=0;p-=60){                                 //p每次迭代60
         t=0;                                          //初始进位为0
         //注意外层循环是2的幂次，内层循环是500位，表示p每进行一次迭代，则a数组中的每一位都要乘以2的p次幂
         for(int j=1;j<=500;j++){
             if(p>=60) a[j]<<=60;
             else a[j]<<=p;
             a[j]+=t;                                  //先加上低位进位，再进行后续处理
             t=a[j]/10;                                //由于是十进制下的运算，因此均以10作为除法和取模的标准
             a[j]%=10;
         }
     }

     a[1]-=1;                                          //最终不退位，直接减1
     for(int i=500;i>=1;i--){                          //输出对应的结果
         cout<<(char)(a[i]+'0');
         if(i%50==1) cout<<endl;
     }

     return 0;
 }