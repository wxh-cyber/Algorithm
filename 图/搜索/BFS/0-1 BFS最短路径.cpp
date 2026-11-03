#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

/**
 *  @brief zeroOneBFS - 0-1 BFS算法
 *  @param {vector<vector<pair<int,int>>>} adj - 邻接表
 *  @param {int} src - 出发点序号
 *  @param {int} n - 节点总数
 *  @return {vector<int>} result - 从源点出发到所有点的最短距离结果
 */
vector<int> zeroOneBFS(vector<vector<pair<int,int>>>& adj,int src,int n){
    vector<int> dist(n,INT_MAX);                                  //n个节点的距离数组，初始化所有节点的最短距离均为最大值
    deque<int> dq;                                                

    dist[src]=0;                                                  //定义源点到自身距离为0
    dq.push_back(src);                                            //将源点入队尾

    while(!dq.empty()){
        int u=dq.front();                                         //取出队头的元素，定义为u
        dq.pop_front();                                           //队头元素出队

        for(auto& edge:adj[u]){                                   //遍历u的邻接表
            int v=edge.first;                                     //每一项都对应一个相邻节点v和权值weight
            int weight=edge.second;

            if(dist[u]+weight<dist[v]){                           //如果通过u到达v的距离更短，则更新
                dist[v]=dist[u]+weight;

                if(weight==0){
                    dq.push_front(v);                             //如果边权为0，将v插入队头
                }else{
                    dq.push_back(v);                              //如果边权为1，将v插入队尾
                }
            }
        }
    }

    return dist;                                                  //返回最终结果
}

int main(){
    int n=9,src=0;
    // 边列表，每个元素为 {u, v, weight}
    vector<vector<int>> edges={
        {0,1,0},{0,7,1},{1,2,1},{1, 7, 1},
        {2, 3, 0}, {2, 5, 0}, {2, 8, 1}, {3, 4, 1}, {3, 5, 1},
        {4, 5, 1}, {5, 6, 1}, {6, 7, 1}, {7, 8, 1}
    };
    
    //构建邻接表
    vector<vector<pair<int,int>>> adj(n);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // 无向图，双向添加
    }

    vector<int> dist=zeroOneBFS(adj,src,n);
    cout << "从节点 " << src << " 出发的最短路径距离: ";
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}