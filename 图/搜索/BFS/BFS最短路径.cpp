#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFSShortestPath{
    private:
        vector<vector<int>> graph;                           //采用二维vector来表示无向图
        vector<int> distance;                                //采用distance数组来表示从源点到每个点的最短距离
        vector<int> parent;                                  //采用parent数组来表示遍历时，单个点的前向节点
        int n;                                               //n表示节点总数

    public:
        /**
         *  @brief BFSShortestPath - 构造函数
         *  @param {int} nodes - 节点数量
         *  @note 初始化时，输入节点总数，初始化graph二维数组、距离distance和前向parent数组
         */
        BFSShortestPath(int nodes):n(nodes){
            graph.resize(n);
            distance.resize(n);
            parent.resize(n);
        }

        /**
         *  @brief addEdge - 添加无向边
         *  @param {int} u - 无向边的一点
         *  @param {int} v - 无向边的另一点
         *  @return 无
         *  @note 由于是无向边，因此从u到v和从v到u都要添加
         */
        void addEdge(int u,int v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        /**
         *  @brief bfs - 广度优先遍历获取最短路径
         *  @param {int} source - 出发源点下标
         *  @return 无
         */
        void bfs(int source){
            //初始化distance和parent数组全部为-1
            fill(distance.begin(),distance.end(),-1);
            fill(parent.begin(),parent.end(),-1);

            queue<int> q;                                     //构造一个队列queue，注意queue只支持从头部出队和从尾部入队
            distance[source]=0;                               //源点到自身的距离为0
            q.push(source);                              //将源点入队

            while(!q.empty()){                                //当队列非空时，不断执行操作
                int u=q.front();                              //取出队首元素，记为u
                q.pop();                                      //队首元素出队

                for(int v:graph[u]){                          //graph[u]中不是-1的点，即为u的所有相邻节点，依次遍历
                    if(distance[v]==-1){                      //如果该节点先前没有遍历过
                        distance[v]=distance[u]+1;            //更新该节点到源点的距离
                        parent[v]=u;                          //更新该节点的前驱节点为u
                        q.push(v);                        //将该节点入队
                    }
                }
            }
        }

        /**
         *  @brief getDistance - 获取从源节点出发到目标节点的距离
         *  @param {int} target - 目标节点下标
         *  @return {int} distance[target] - 实际距离
         */
        int getDistance(int target){
            return distance[target];
        }

        /**
         *  @brief getPath - 获取从源节点到目标节点，中间依次经过的所有节点
         *  @param {int} source - 源节点下标
         *  @param {int} target - 目标节点下标
         *  @return {vector<int>} path - 最终的路径
         */
        vector<int> getPath(int source,int target){
            //不可达时，返回空的vector
            if(distance[target]==-1){
                return {};
            }

            vector<int> path;                                               //构造一个vector数组
            for(int v=target;v!=-1;v=parent[v]){                            //依次遍历v的前向节点
                path.push_back(v);                                     //将每次遍历到的节点加入path尾部
            }

            reverse(path.begin(),path.end());                  //翻转，以确保源节点在path[0]的位置
            return path;                                                   //返回最终结果
        }

        /**
         *  @brief isReachable - 是否可达函数
         *  @param {int} target - 目标节点下标
         *  @return {true|false} - 是否可达
         */
        bool isReachable(int target){
            return distance[target]!=-1;
        }
};

int main(){
    //创建无向图
    BFSShortestPath bfs(8);

    //具体图可参见BFS最短路径示意图
    bfs.addEdge(0,1);
    bfs.addEdge(0, 3);
    bfs.addEdge(1, 2);
    bfs.addEdge(3, 4);
    bfs.addEdge(3, 7);
    bfs.addEdge(4, 5);
    bfs.addEdge(4, 6);
    bfs.addEdge(4, 7);
    bfs.addEdge(5, 6);
    bfs.addEdge(6, 7);

    //从节点0开始BFS
    int source=0;
    bfs.bfs(source);

    //查询到各个节点的最短路径
    cout<<"从节点 "<<source<<" 出发的最短路径："<<endl;

    for(int target=0;target<8;target++){
        int dist=bfs.getDistance(target);
        if(dist==-1){
            cout<<"到节点 "<<target<<" :不可达"<<endl;
        }else{
            vector<int> path=bfs.getPath(source,target);
            cout<<"到节点 "<<target<<" (距离=" << dist << "): ";
            for(int i=0;i<path.size();i++){
                if(i>0) cout<<"->";
                cout<<path[i];
            }
            
            cout<<endl;
        }
    }

    return 0;
}