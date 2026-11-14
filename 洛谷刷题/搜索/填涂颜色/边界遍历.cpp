/**
 *  @link https://www.luogu.com.cn/problem/P1162
 */

 #include <iostream>
 #include <queue>
 using namespace std;

 const int MAXN=35;

 int n;                                                      //方阵大小
 queue<pair<int,int>> q;                                     //采用队列实现bfs
 int map[MAXN][MAXN];                                        //map存储初始时，输入的数据
 int vis[MAXN][MAXN]={0};                             //vis记录是否已被访问过
 
 //方向数组，对应上下左右四个方向
 int dx[4]={-1,1,0,0};                       
 int dy[4]={0,0,1,-1};

 /**
  *  @brief bfs - 广度优先遍历
  *  @param {int} x - 横坐标
  *  @param {int} y - 纵坐标
  *  @return 无
  */
 void bfs(int x,int y){
    vis[x][y]=1;                                                //更新(x,y)的访问状态
    q.push({x,y});                            //将(x,y)入队

    while(!q.empty()){
        auto [curX,curY]=q.front();                   //取队首元素的坐标
        q.pop();                                                //队首元素出队

        for(int i=0;i<4;i++){                                   //依次遍历上下左右四个方向
            int nx=curX+dx[i];
            int ny=curY+dy[i];

            if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]){        //如果遍历的坐标没有越界，且之前未被访问过
                vis[nx][ny]=1;                                 //更新该坐标访问状态
                q.push({nx,ny});             //将该坐标入队
            } 
        }
    }
 }

 int main(){
    cin>>n;                                                   //输入方阵大小
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];                                   //输入方阵数据

            if(map[i][j]) {
                vis[i][j]=1;                                  //如果输入为边界，则默认不可达
            }
        }
    }

    //遍历方阵的上边界和下边界
    /**
     *  @note 
     *    1.对于外层循环，初始时，i为0，j从0到n-1，遍历的是方阵的上边界。经过一次迭代后，i变为n-1，j依然从0到n-1,遍历的是下边界。
     *      在接下来，i=2n-1，当n＞1时，显然并不符合循环条件，因此总共只遍历了上边界和下边界这两行数据
     *    2.注意，由于不能保证对称性，因此内层循环j需要遍历所有的下标
     */
    for(int i=0;i<n;i=i+n-1){
        for(int j=0;j<n;j++){
            if(vis[i][j]) continue;                      //如果该点已经被遍历过，或者不可达，则跳过
            bfs(i,j);                               //否则在该点进行bfs
        }
    }

    //遍历方阵的左边界和右边界
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j=j+n-1){
            if(vis[i][j]) continue;
            bfs(i,j);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //如果该点已经被遍历过，或者为边界，则直接输出原先的数据
            if(vis[i][j]) cout<<map[i][j]<<" ";   
            //否则是内部的0，输出2     
            else cout<<2<<" ";
        }

        cout<<endl;
    }

    return 0;
 }