// 适合：稠密图、Floyd、n 较小（n ≤ 3000 左右，注意空间）
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=1005;
const int INF=0x3f3f3f3f;

int n,m;                                       //点数、边数
int u,v,w;                                     //边起点、边终点、边权值
int g[MAXN][MAXN];                             //g是存图的邻接矩阵

/**
 *  @brief init - 邻接矩阵初始化
 *  @return 无
 */
void init(){
    memset(g,0x3f,sizeof(g));                    //初始时，用INF表示所有点都无边
    for(int i=1;i<=n;i++){  
        g[i][i]=0;                                              //点到自身距离为0
    }
}

/**
 *  @brief addEdge - 添加边
 *  @param {int} u - 边起点
 *  @param {int} v - 边终点
 *  @param {int} w - 边权值
 *  @return 无
 */
void addEdge(int u,int v,int w){
    g[u][v]=w;                                  //有向图
    //g[v][u]=w;                                //无向图取消注释
}

/**
 *  @brief print - 输出邻接矩阵
 *  @return 无
 */
void print(){
    cout<<"=====邻接矩阵存图====="<<endl;
    for(int u=1;u<=n;u++){
        cout << "点 " << u << " 的出边:";
        for(int v=1;v<=n;v++){
            if(v!=u&&g[u][v]!=INF){
                cout << "  " << v << "(w=" << g[u][v] << ")";
            }
        }

        cout<<endl;
    }

    cout<<endl;
}

/**
 *  @brief bfs - 广度优先遍历
 *  @param {int} s - 出发点
 *  @return 无
 */
void bfs(int s){
    vector<bool> vis(n+1,false);                      //vis[i]表示节点i是否已经被访问过
    queue<int> q;                                                //采用队列q实现bfs

    q.push(s);                                              //原点入队
    vis[s]=true;                                                 //标记原点已经访问过
    while(!q.empty()){
        int u=q.front();                                         //取队头元素为u
        q.pop();                                                 //队头元素出队

        cout << " " << u;
        for(int v=1;v<=n;v++){                                   //依次遍历所有节点
            if(!vis[v]&&g[u][v]!=INF){                           //如果v先前没有被遍历过，且从u到v可达
                vis[v]=true;                                     //标记vis[v]为已访问
                q.push(v);                                   //v入队
            }
        }
    }

    cout<<endl;
}

int main(){
    cin>>n>>m;                                   //输入点数和边数

    init();                                      //初始化邻接矩阵
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;                            //输入每条边的信息
        addEdge(u,v,w);                          //不断更新邻接矩阵
    }

    print();                                     //输出邻接矩阵
    bfs(1);                                   //bfs

    return 0;
}