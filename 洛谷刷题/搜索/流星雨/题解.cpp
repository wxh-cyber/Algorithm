/**
 *  @link https://www.luogu.com.cn/problem/P2895
 */

 #include <iostream>
 #include <cstring>
 #include <queue>
 using namespace std;

 const int MAXN=305;
 const int MAXM=5e4+5;

 int m;                                                      //m陨石数量
 int dx[4]={-1,1,0,0};                       //dx和dy为方向数组
 int dy[4]={0,0,-1,1};
 int map[MAXN][MAXN];                                        //map[i][j]表示到达（i,j）花费的最短时间
 int show[MAXN][MAXN];                                       //show[i][j]表示陨石击落后的状态，-1表示始终不会被击中，否则在t时刻被击中

 /**
  *  @brief meter - 陨石结构体
  *  @param {int} x - 击中横坐标
  *  @param {int} y - 击中纵坐标
  *  @param {int} t - 击中时间
  */
 struct meter{
    int x;
    int y;
    int t;
 }meters[MAXM];

 queue<pair<int,int>> q;                                   //采用队列进行广度优先遍历

 int main(){
    cin>>m;                                                //输入陨石数量
    memset(show,-1,sizeof(show));           //初始化show数组为-1

    for(int i=0;i<m;i++){
        int x1,y1,t;
        cin>>x1>>y1>>t;                                   //输入陨石的坐标和时间

        meters[i].x=x1;                                   //存储到对应结构体数组中
        meters[i].y=y1;
        meters[i].t=t;

        if(x1==0&&y1==0&&t==0){                           //如果刚开始就袭击了出发点，显然无处可避，输出-1
            cout<<"-1"<<endl;
            return 0;
        }

        if(show[x1][y1]==-1||t<show[x1][y1]){            //如果之前这个地方没有被击中，或者当前袭击的时间小于之前记录的最早时间，则更新为当前时间
            show[x1][y1]=t;
        }

        for(int i=0;i<4;i++){
            //依次遍历上下左右四格
            int x2=x1+dx[i];
            int y2=y1+dy[i];

            //如果遍历的格在矩阵范围内，且从来没有被陨石袭击过，或者当前袭击的时间小于以前被袭击的时间，则更新为当前袭击的时间
            /**
             *  @note 注意x和y输入上限300，但是有可能最终躲避的节点的x或者y大于300，为考虑到边界情况，需要通过MAXN进行上界判断。
             */
            if(x2>=0&&x2<=MAXN&&y2>=0&&y2<=MAXN&&(show[x2][y2]==-1||t<show[x2][y2])){
                show[x2][y2]=t;
            }
        }
    }

    memset(map,-1,sizeof(map));                        //初始化map数组为-1
    
    q.push({0,0});                                    //刚开始将(0,0)入队
    map[0][0]=0;                                                     //显然到达出发点的时间为0
    while(!q.empty()){                                               //广度优先遍历
        //获取到队首元素的横纵坐标
        int x=q.front().first;                                       
        int y=q.front().second;
        q.pop();                                                     //队首元素出队

        /**
         *  @note 由于本题的广度优先数值本身就是从小到大，因此，如果碰到永久不会被袭击的坐标，则直接输出对应结果。
         */
        if(show[x][y]==-1){
            cout<<map[x][y]<<endl;
            return 0;
        }

        for(int i=0;i<4;i++){
            //依次遍历上下左右四格
            int nx=x+dx[i];
            int ny=y+dy[i];

            //记录遍历到相邻节点的时间为nextTime
            int nextTime=map[x][y]+1;
            //如果相邻节点不过界，且之前未被遍历到，而且这个节点永久不会被袭击或者遍历到时，暂时还没有被袭击，则可以遍历到该节点。
            if(nx>=0&&nx<=MAXN&&ny>=0&&ny<=MAXN&&map[nx][ny]==-1&&(show[nx][ny]==-1||nextTime<show[nx][ny])){
                map[nx][ny]=nextTime;
                q.push({nx,ny});

                //如果确实永久不会被袭击，直接输出对应结果
                if(show[nx][ny]==-1){
                    cout<<map[nx][ny]<<endl;
                    return 0;
                }
            }
        }
    }

    //最终返回的是无路可走的情况
    cout<<"-1"<<endl;

    return 0;
 }