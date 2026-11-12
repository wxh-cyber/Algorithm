#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=1005;

int n,m;                                                //点数、边数
int u,v,w;                                              //边起点、边终点、边权值

/**
 *  @brief Edge - 边对象
 *  @param {int} to - 边终点
 *  @param {int} w - 边权值
 */
struct Edge{
    int to;
    int w;
};

vector<Edge> adj[MAXN];                                   //邻接表

/**
 *  @brief addEdge - 添加边
 *  @param {int} u - 边起点
 *  @param {int} v - 边终点
 *  @param {int} w - 边权值
 *  @return 无
 */
void addEdge(int u,int v,int w){
    adj[u].push_back({v,w});                   //有向图
    //adj[v].push_back({u,w});                            //无向图取消注释
}

/**
 *  @brief bfs - 广度优先遍历
 *  @param {int} s - 原点
 *  @return 无
 */
void bfs(int s){
    vector<bool> vis(n+1,false);               //vis[i]表示节点i是否已经被遍历过
    queue<int> q;                                         //采用队列实现广度优先遍历

    q.push(s);                                       //原点入队
    vis[s]=true;                                          //更新原点访问状态
    cout << "BFS 从 " << s << " 出发的访问顺序:";
    while(!q.empty()){
        int u=q.front();                                  //取队首元素为u
        q.pop();                                          //队首元素出队

        for(auto& e:adj[u]){
            cout << "  " << e.to << "(w=" << e.w << ")";   //依次遍历u的所有邻接节点
        }
        cout<<endl;
    }
}

/**
 *  @brief print - 输出邻接表
 *  @return 无
 */
void print(){
    cout<<"=====邻接表存图====="<<endl;
    for(int u=1;u<=n;u++){
        cout << "点 " << u << " 的出边:";
        for(auto &e:adj[u]){
             cout << "  " << e.to << "(w=" << e.w << ")";
        }

        cout<<endl;
    }

    cout<<endl;
}

int main(){
    cin>>n>>m;                                                    //输入点数、边数                  
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;                                             //输入所有边的相关信息
        addEdge(u,v,w);                                           //更新邻接表
    }

    print();                                                      //输出邻接表
    bfs(1);                                                    //bfs

    return 0;
}