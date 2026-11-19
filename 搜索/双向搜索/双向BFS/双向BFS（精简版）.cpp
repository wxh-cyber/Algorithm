#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 *  @brief bidirectionalBFS - 双向BFS
 *  @param {T} start - 开始节点
 *  @param {T} end - 结束节点
 *  @param {F} getNeighbors - 获取邻接节点
 *  @return {int} result - 从起点到终点的总步数
 */
template<typename T,typename F>
int bidirectionalBFS(T start,T end,F getNeighbors){
    if(start==end) return 0;

    unordered_map<T,int> mp1,mp2;
    queue<T> q1,q2;

    mp1[start]=0;
    mp2[end]=1;
    q1.push(start);
    q2.push(end);

    auto expand=[&](queue<T>& q,unordered_map<T,int> &mp1,unordered_map<T,int> &mp2){
        while(!q.empty()){
            T u=q.front();
            q.pop();

            int step=mp1[u]+1;
            for(const auto&v:getNeighbors(u)){
                if(mp1.count(v)) continue;
                if(mp2.count(v)){
                    return mp1[u]+mp2[v];
                }

                mp1[v]=step;
                q.push(v);
            }
        }

        return -1;
    };

    while(!q1.empty()&&!q2.empty()){
        int ans=(q1.size()<=q2.size())?expand(q1,mp1,mp2):expand(q2,mp2,mp1);
        if(ans!=-1) return ans;
    }

    return -1;
}

int main(){


    return 0;
}