/**
 *  @link https://www.luogu.com.cn/problem/P1162
 */

 #include <iostream>
 using namespace std;

 const int MAXN=35;

 int n;                                                         //方阵的大小
 int map[MAXN][MAXN];                                           //map存储初始时，输入的数据

 //方向数组，对应上下左右四个方向
 int dx[4]={-1,1,0,0};
 int dy[4]={0,0,-1,1};

 /**
  *  @brief dfs - 深度优先遍历
  *  @param {int} x - 横坐标
  *  @param {int} y - 纵坐标
  *  @return 无
  */
 void dfs(int x,int y){
    //如果越界，或者该坐标点已经访问过，或者本身为边界，不可达，则直接返回
    if(x<0||x>=n||y<0||y>=n||map[x][y]!=0) return;

    map[x][y]=2;                                      //已经访问过的点，标记为2，与边界1相区分
    for(int i=0;i<4;i++){
        //依次遍历上下左右四个方向
        dfs(x+dx[i],y+dy[i]);
    }
 }

 int main(){
    cin>>n;                                           //输入方阵的大小
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];                           //输入方阵数据
        }
    }

    //依次从上下左右四个边界开始dfs遍历
    //如果只从单个边界，如左上角遍历，则可能出现左上角部分为一个连通分量，从而其他区域被判定为不可达，被误判为2的情况
    //因此四个边界都需要dfs
    for(int i=0;i<n;i++){
        dfs(i,0);
        dfs(0,i);
        dfs(n-1,i);
        dfs(i,n-1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==0){
                cout<<2<<" ";                                  //遍历后仍为0，说明是内部的点，输出2
            }else if(map[i][j]==1){
                cout<<1<<" ";                                  //边界输出1
            }else{
                cout<<0<<" ";                                  //外部输出0
            }
        }

        cout<<endl;
    }

    return 0;
 }