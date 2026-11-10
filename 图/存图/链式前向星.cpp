#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//========== 全局设置 ==========
const int MAXN = 1005;        // 点数上限（邻接矩阵受此限制）
const int MAXM = 100005;      // 边数上限（无向图请开两倍！）

int n,m;                      //点数、边数

int head[MAXN];                             // head[u]：u 的第一条出边编号
int nxt[MAXM];                              // nxt[i] ：同起点的下一条边编号
int to_[MAXM];                              // to_[i] ：第 i 条边的终点
int wt[MAXM];                               // wt[i]  ：第 i 条边的边权
int tot;                                    // 边计数器

void init(){
    tot=0;
    memset(head,-1,sizeof(head));       //-1表示无边
}

void addEdge(int u,int v,int w){
    to_[tot]=v;
    wt[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}



int main(){


    return 0;
}