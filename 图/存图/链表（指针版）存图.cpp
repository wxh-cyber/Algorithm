// 适合：学习阶段理解链式结构；用完记得释放内存
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=1005;

int n,m;                                               //点数、边数
int u,v,w;                                             //边起点、边终点、边权值

/**
 *  @brief EdgeNode - 边类型节点
 *  @param {int} to - 边终点
 *  @param {int} w - 边权值
 *  @param {EdgeNode*} next - 边节点指针
 */
struct EdgeNode{
    int to;
    int w;
    EdgeNode *next;
    EdgeNode(int t,int val):to(t),w(val),next(nullptr){}
};

EdgeNode* head[MAXN];                                   //每个点一条边链表

/**
 *  @brief addEdge - 添加边
 *  @param {int} u - 边起点
 *  @param {int} v - 边终点
 *  @param {int} w - 边权值
 *  @return 无
 */
void addEdge(int u,int v,int w){
    EdgeNode* e=new EdgeNode(v,w);
    e->next=head[u];                                    //头插法
    head[u]=e;
}

/**
 *  @brief bfs - 广度优先遍历
 *  @param {int} s - 出发点
 *  @return 无
 */
void bfs(int s){
    vector<bool> vis(n+1,false);             //采用vis记录是否被访问过
    queue<int> q;                                       //队列q实现bfs

    q.push(s);                                     //起点入队
    vis[s]=true;                                        //更新起点访问状态
    while(!q.empty()){
        int u=q.front();                                //取队首元素为节点u
        q.pop();                                        //队首元素出队

        cout<<" "<<u;
        for(EdgeNode* p=head[u];p!=nullptr;p=p->next){  //依次遍历以u节点为起点的边
            if(!vis[p->to]){                            //如果边终点没有被遍历过
                vis[p->to]=true;                        //更新边终点访问状态
                q.push(p->to);                     //边终点入队
            }
        }
    }

    cout<<endl;
}

/**
 *  @brief print - 输出存图
 *  @return 无
 */
void print(){
    cout<<"=====链表（指针版）存图====="<<endl;
    for(int u=1;u<=n;u++){
        cout << "点 " << u << " 的出边:";
        for(EdgeNode* p=head[u];p!=nullptr;p=p->next){
            cout << "  " << p->to << "(w=" << p->w << ")";
        }

        cout<<endl;
    }

    cout<<endl;
}

/**
 *  @brief freeList - 释放动态空间
 *  @return 无
 */
void freeList(){
    for(int u=1;u<=n;u++){
        EdgeNode* p=head[u];
        while(p!=nullptr){
            EdgeNode* tmp=p->next;
            delete p;
            p=tmp;
        }

        head[u]=nullptr;
    }

}

int main(){
    cin>>n>>m;                                          //输入点数和边数
    for(int i=1;i<=n;i++){
        head[i]=nullptr;                                //初始化链表
    }

    for(int i=1;i<m;i++){
        cin>>u>>v>>w;                                   //依次输入各条边信息
        addEdge(u,v,w);                                 //更新链表
    }

    print();                                            //输出存图
    bfs(1);                                           //bfs
    freeList();                                         //释放链表

    return 0;
}