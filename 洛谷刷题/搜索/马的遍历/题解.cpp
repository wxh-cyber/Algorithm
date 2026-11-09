/**
 *  @link https://www.luogu.com.cn/problem/P1443
 */

 #include <iostream>
 #include <cstring>
 #include <queue>
 #include <cstdio>
 using namespace std;

 const int MAXN=405;

 int n,m;
 int x,y;
 int f[MAXN][MAXN];
 int dx[8]={-2,-2,-1,-1,1,1,2,2};
 int dy[8]={1,-1,2,-2,2,-2,1,-1};
 bool vis[MAXN][MAXN];
 queue<pair<int,int>> q;

 int main(){
    cin>>n>>m>>x>>y;
    x--;
    y--;

    memset(f,-1,sizeof(f));
    memset(vis,0,sizeof(vis));

    f[x][y]=0;
    vis[x][y]=1;
    q.push({x,y});
    while(!q.empty()){
        int x0=q.front().first;
        int y0=q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++){
            int nx=x0+dx[i];
            int ny=y0+dy[i];

            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]){
                f[nx][ny]=f[x0][y0]+1;
                vis[nx][ny]=1;
                q.push({nx,ny});
            }else{
                continue;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%-5d",f[i][j]);
        }

        printf("\n");
    }

    return 0;
 }