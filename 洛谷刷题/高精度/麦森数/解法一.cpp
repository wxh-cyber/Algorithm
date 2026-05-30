/**
 *  @link https://www.luogu.com.cn/problem/P1045
 */
 #include <iostream>
 #include <cstdio>
 #include <cmath>
 typedef long long ll;
 using namespace std;

 ll n;
 int cnt;                                          //cnt用于记录输出状态下，每行的位数
 int a[1010],res[1010];

 /**
  *  @brief multiply1
  *  @note 高精度乘法
  *  @return void
  */
 void multiply1(){
     int tmp[1010]={0};
     for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            tmp[i+j]+=res[i]*a[j];
        }
     }

     int t=0;
     for(int i=0;i<500;i++){
        //先加上低位的进位，再进行数据处理
        tmp[i]+=t;
        res[i]=tmp[i]%10;
        t=tmp[i]/10;
     }
 }

 /**
  *  @brief multiply2
  *  @note 高精度乘法
  *  @return void
  */
 void multiply2(){
     int tmp[1010]={0};
     for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            tmp[i+j]+=a[i]*a[j];
        }
     }

     int t=0;
     for(int i=0;i<500;i++){
        tmp[i]+=t;
        a[i]=tmp[i]%10;
        t=tmp[i]/10;
     }
 }

 /**
  *  @brief quick_pow
  *  @param p 指数
  *  @note 快速幂
  *  @return void
  */
 void quick_pow(int p){
    res[0]=1;
    a[0]=2;
    while(p){
        if(p&1) multiply1();
        multiply2();
        p>>=1;
    }
 }

 int main(){
    scanf("%ld",&n);
    int length=n*log10(2)+1;
    printf("%d\n",length);
    quick_pow(n);
    res[0]-=1;                         //因为不可能退位，所以直接减1
    for(int i=499;i>=0;i--){
        if(cnt==50) {
            printf("\n");
            cnt=0;
        }
        printf("%d",res[i]);
        cnt++;
    }

    return 0;
 }