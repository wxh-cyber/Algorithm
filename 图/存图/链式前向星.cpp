#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//========== 全局设置 ==========
const int MAXN = 1005;   // 点数上限（邻接矩阵受此限制）
const int MAXM = 100005; // 边数上限（无向图请开两倍！）

int n, m;                // 点数、边数
int u,v,w;               //起点、终点、权值

int head[MAXN]; // head[u]：u 的第一条出边编号
int nxt[MAXM];  // nxt[i] ：同起点的下一条边编号
int to_[MAXM];  // to_[i] ：第 i 条边的终点
int wt[MAXM];   // wt[i]  ：第 i 条边的边权
int tot;        // 边计数器

/**
 *  @note
 *    边的“编号” 0 ~ tot-1 才是主角。to_、wt、nxt三个数组都是按“边的编号”索引的，而 head是按“点的编号”索引的，它是从“点”跳到“边”的唯一入口。
 */

 /**
  *  @brief init - 初始化
  *  @return 无
  */
void init() {
  tot = 0;
  memset(head, -1, sizeof(head)); //-1表示无边
}

/**
 *  @brief addEdge - 增加新边
 *  @param {int} u - 边起点
 *  @param {int} v - 边终点
 *  @param {int} w - 边权值
 *  @return 无
 *  @note
 *    “新边指旧边，挂钩换新边”。顺序不能乱——必须先用 head[u] 更新 nxt[tot]，再改
 * head[u]。
 */
void addEdge(int u, int v, int w) {
  to_[tot] = v;       // ① 记录新边信息：终点 v、权值 w
  wt[tot] = w;
  nxt[tot] = head[u]; // ② 新边指向"原来的第一条边"（接上旧链）
  head[u] = tot++;    // ③ 挂钩换新：u 的第一条边变成新边，编号自增
}

/**
 *  @brief bfs - 链式前向星广度优先搜索
 *  @param {int} s - 出发点
 *  @return 无
 */
void bfs(int s){
    vector<bool> vis(n+1,false);                    //记录点是否被访问过，初始均为false
    queue<int> q;                                              //采用队列实现广度优先遍历

    q.push(s);                                            //起点入队
    vis[s]=true;                                               //记录起点被访问了

    cout << "BFS 从 " << s << " 出发的访问顺序:";
    while(!q.empty()){
        int u=q.front();                                       //取队首元素作为起点u
        q.pop();                                               //队首元素出队

        cout<<" "<<u;                                          //输出队首元素
        for(int i=head[u];i!=-1;i=nxt[i]){                     //以u为起点，遍历所有相关的边
            if(!vis[to_[i]]){                                  //如果编号为i的边的终点，没有被访问过
                vis[to_[i]]=true;                              //更新其访问状态
                q.push(to_[i]);                           //将其入队
            }
        }
    }

    cout<<endl;
}

/**
 *  @brief print - 输出存图
 *  @return 无
 */
void print() {
  cout << "===== 链式前向星存图 =====\n";
  for (int u = 1; u <= n; u++) {
    cout << "点 " << u << " 的出边:";
    for (int i = head[u]; i != -1; i = nxt[i])
      //每次都输出从u可达哪些点v，以及相应的权值
      cout << "  " << to_[i] << "(w=" << wt[i] << ")";
    cout << "\n";
  }
  cout << "\n";
}

int main() { 
    cin>>n>>m;                                       //输入点数、边数

    init();
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;                                //依次输入m条边的相关信息
        addEdge(u,v,w);                              //存图
    }

    print();                                         //输出图
    bfs(1);                                       //bfs

    return 0; 
}