#include <iostream>
#include <vector>
using namespace std;

class BFSShortestPath{
    private:
        vector<vector<int>> graph;
        vector<int> distance;
        vector<int> path;
        int n;

    public:
        BFSShortestPath(int nodes):n(nodes){
            graph.resize(n);
            distance.resize(n);
            path.resize(n);
        }

        void addEdge(int u,int v){
            
        }
};

int main(){


    return 0;
}