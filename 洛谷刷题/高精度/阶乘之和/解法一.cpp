/**
 *    @link https://www.luogu.com.cn/problem/P1009
 */
 #include<iostream>
 #include<cstdio>
 using namespace std;

 int n; 
 int a[101]={0},s[101]={0};                         //a数组存储阶乘计算结果，s数组存储最终加和

 /**
  *  @brief 高精度乘法
  *  @param x 乘数
  */
 void multiply(int x){
    int carry=0;
    for(int i=100;i>=0;i--){
        a[i]=a[i]*x+carry;
        carry=a[i]/10;
        a[i]%=10;
    }
 }

 /**
  *  @brief 高精度加法
  */
 void add(){
    int carry=0;
    for(int i=100;i>=0;i--){
        s[i]=s[i]+a[i]+carry;
        carry=s[i]/10;
        s[i]%=10;
    }
 }

 /**
  *  @brief 输出
  */
 void print(){
     int w;
     for(int i=0;i<=100;i++){
        if(s[i]!=0){
            w=i;
            break;
        }
     }

     for(int i=w;i<=100;i++){
        printf("%d",s[i]);
     }
 }

 int main(){
    scanf("%d",&n);
    s[100]=a[100]=1;
    for(int i=2;i<=n;i++){
        // 本处阶乘实际上是对先前的结果进行复用
        multiply(i);
        add();
    }
    print();

    return 0;
 }