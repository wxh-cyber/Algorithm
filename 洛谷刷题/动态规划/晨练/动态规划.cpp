/**
 *  @link https://www.luogu.com.cn/problem/P1353
 */

 #include <iostream>
 #include <algorithm>
 using namespace std;

 const int MAXN=1e4+5;
 const int MAXM=505;

 int n,m;
 int d[MAXN];
 int f[MAXN][MAXM];

 int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }

    f[1][1]=d[1];
    for(int i=1;i<n;i++){
        for(int j=0;j<=min(i,m)&&i+j<=n;j++){
            if(j==0)
                f[i][0]=max(f[i][0],f[i-1][0]);
            else
                f[i+j][0]=max(f[i+j][0],f[i][j]);
            f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+d[i+1]);
        }
    }

    cout<<f[n][0]<<endl;

    return 0;
 }