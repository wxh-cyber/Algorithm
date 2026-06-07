/**
 *  @link https://www.luogu.com.cn/problem/P1255
 */
 #include<iostream>
using namespace std;
#define EXIT cout<<n,exit(0)

const int MAXN=2505;
int n,m;                                               //n表示楼梯的层数，m表示数位的位数
int a[MAXN],b[MAXN],ans[MAXN];

void add(){
    a[1]=1;
    b[1]=2;
    m=1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[j]=a[j]+b[j];
        }
        for(int j=1;j<=m;j++){
            if(ans[j]>9){
                ans[j]-=10;
                ++ans[j+1];
                if(j==m) m++;
            }
        }
        for(int j=1;j<=m;j++){
            a[j]=b[j];
            b[j]=ans[j];
        }
    }
}

int main(){
    cin>>n;
    if(n<3) EXIT;
    add();
    for(int i=m;i;i--) cout<<ans[i];
    
    return 0;
}