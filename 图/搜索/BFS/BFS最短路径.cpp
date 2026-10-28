#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFSShortestPath{
    private:
        vector<vector<int>> graph;                           //采用二维vector来表示无向图
        vector<int> distance;
        vector<int> parent;
        int n;

    public:
        BFSShortestPath(int nodes):n(nodes){
            graph.resize(n);
            distance.resize(n);
            parent.resize(n);
        }

        void addEdge(int u,int v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        void bfs(int source){
            fill(distance.begin(),distance.end(),-1);
            fill(parent.begin(),parent.end(),-1);

            queue<int> q;
            distance[source]=0;
            q.push(source);

            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(int v:graph[u]){
                    if(distance[v]==-1){
                        distance[v]=distance[u]+1;
                        parent[v]=u;
                        q.push(v);
                    }
                }
            }
        }

        int getDistance(int target){
            return distance[target];
        }

        vector<int> getPath(int source,int target){
            //不可达
            if(distance[target]==-1){
                return {};
            }

            vector<int> path;
            for(int v=target;v!=-1;v=parent[v]){
                path.push_back(v);
            }

            reverse(path.begin(),path.end());
            return path;
        }

        bool isReachable(int target){
            return distance[target]!=-1;
        }
};

int main(){
    //创建无向图
    BFSShortestPath bfs(8);

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