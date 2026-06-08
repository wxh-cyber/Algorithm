/**
 *  @link https://www.luogu.com.cn/problem/P1255
 */
 #include<iostream>
using namespace std;
#define EXIT cout<<n,exit(0)                           //采用宏定义简化退出的代码

const int MAXN=2505;
int n,m;                                               //n表示楼梯的层数，m表示数位的位数
int a[MAXN],b[MAXN],ans[MAXN];                         

/**
 * @brief 采用递推的思想，从第三层开始，每层的数字都是前两层的和
 * @return void
 */
void add(){
    a[1]=1;                                  //当台阶为一级时，只有一种走法
    b[1]=2;                                  //当台阶为二级时，有两种走法
    m=1;                                     //m表示数位的位数，初始为1

    for(int i=3;i<=n;i++){                   //外层i表示当前的层数，从第三层开始
        for(int j=1;j<=m;j++){               //内层j表示当前的数位，从个位开始
            ans[j]=a[j]+b[j];
        }

        for(int j=1;j<=m;j++){
            if(ans[j]>9){                    //如果当前的数位大于9，就需要进位
                ans[j]-=10;
                ++ans[j+1];
                if(j==m) m++;
            }
        }

        for(int j=1;j<=m;j++){
            a[j]=b[j];                       //本质是对递推的优化
            b[j]=ans[j];
        }
    }
}

int main(){
    cin>>n;                                  //输入楼梯的层数
    if(n<3) EXIT;                            //当楼梯的层数小于3时，直接输出对应的结果
    add();                                   //调用add函数，计算结果
    for(int i=m;i;i--) cout<<ans[i];         //输出结果
    
    return 0;
}