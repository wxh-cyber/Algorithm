/**
 *  @link https://www.luogu.com.cn/problem/P1825
 */

#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 305;

int n, m;
int endx, endy;
char map[MAXN][MAXN];
int vis[MAXN][MAXN] = {0};
int dist[MAXN][MAXN]={0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int,int>> q;

pair<int,int> goto_another(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == map[x][y] && (i != x || j != y)) {
                return {i,j};
            }
        }
    }

    return {x,y};
}

void bfs(int x, int y) {
    if (x == endx && y == endy)
        return;

    vis[x][y]=1;

    if (map[x][y] >= 'A' && map[x][y] <= 'Z') {
        auto [tx,ty]=goto_another(x, y);
        if(!vis[tx][ty]){
            vis[tx][ty]=1;
            dist[tx][ty]=dist[x][y];
            q.push({tx,ty});
        }
    }else{
        q.push({x,y});
    }

    while(!q.empty()){
        auto [curX,curY]=q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && map[nx][ny] != '#') {
                vis[nx][ny]=1;
                dist[nx][ny]=dist[curX][curY]+1;

                if(map[nx][ny]>='A'&&map[nx][ny]<='Z'){
                    auto [tx,ty]=goto_another(nx, ny);
                    if(!vis[tx][ty]){
                        vis[tx][ty]=1;
                        dist[tx][ty]=dist[nx][ny];
                        q.push({tx,ty});
                    }
                }else{
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
      for (int j = 0;j<m;j++){
          cin>>map[i][j];
          if(map[i][j]=='#') vis[i][j]=1;
          if(map[i][j]=='=') {
              endx=i;
              endy=j;
          }
      }
  }

  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(map[i][j]=='@'){
              bfs(i,j);
          }
      }
  }

  cout<<dist[endx][endy]<<endl;

  return 0;
}