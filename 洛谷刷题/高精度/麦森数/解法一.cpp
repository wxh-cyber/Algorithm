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
/**
  *  思考：为什么这里定义了两个高精度乘法函数？
  *  答：第一个函数multiply()是用于将两个不相同的高精度数相乘，而第二个函数multiply()是用于将一个高精度数与自身相乘。
  *      具体来说，第一个函数的作用是将当前数与2的n次方相乘，而第二个函数的作用是2的n次方自身的迭代。
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
    while(p){                      //本质是将十进制p转化为二进制的形式
        if(p&1) multiply1();
        multiply2();
        p>>=1;
    }
 }

 int main(){
    scanf("%ld",&n);                   //输入2的n次方
    int length=n*log10(2)+1;           //计算最终结果的位数
    printf("%d\n",length);
    quick_pow(n);                      
    res[0]-=1;                         //因为不可能退位，所以直接减1
    /**
     *  分析：为什么不可能退位？
     *    2^0=1
     *    2^1=2
     *    2^2=4
     *    2^3=8
     *    2^4=16
     *    2^5=32
     *    2^6=64
     *    2^7=128
     *    ...
     *  通过找规律可知，2的n次方的个位数字只有可能是2、4、8、6，所以不可能退位。
     */
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