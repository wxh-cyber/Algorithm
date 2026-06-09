/**
 *  @link https://www.luogu.com.cn/problem/P1255
 */
 #include <iostream>
 #include <cstdio>
 #define N 250                                      //每一位存储8位数据，2000位数据需要250个数组元素
 using namespace std;

 int n;
 int f[3][N+10],g;
 int main(){
    f[0][N]=f[1][N]=1;
    scanf("%d",&n);                                  //输入楼梯层数

    if(!n) {                                         //对0进行特判
        puts("0");
        return 0;
    }

    for(int i=2;i<=n;i++){
        for(int j=N;j>0;j--){
            f[i%3][j]=(f[(i+1)%3][j]+f[(i+2)%3][j]+g)%100000000;
            g=(f[(i+1)%3][j]+f[(i+2)%3][j]+g)/100000000;
        }
    }

    int j=1;
    while(!f[n%3][j]&&j<N) j++;                      //处理前导0

    for(int i=j;i<=N;i++){
        if(i!=j){
            //当i与j相等时，说明当前的数已经是最高位，因此不需要输出前导0
            //补足前导0
            if(f[n%3][i]<1e7) putchar(48);
            if(f[n%3][i]<1e6) putchar(48);
            if(f[n%3][i]<1e5) putchar(48);
            if(f[n%3][i]<1e4) putchar(48);
            if(f[n%3][i]<1e3) putchar(48);
            if(f[n%3][i]<1e2) putchar(48);
            if(f[n%3][i]<1e1) putchar(48);
        }
        printf("%d",f[n%3][i]);
    }

    return 0;
 }