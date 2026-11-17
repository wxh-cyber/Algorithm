#include <iostream>
#include <map>
#include <utility>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T,typename F>
int bidirectionalBFS(T start,T end,F getNeighbors){
    //边界条件特判，返回0
    if(start==end) return 0;

    /**
     *  @note
     *    两侧状态表：dist[u] = 从该侧起点到 u 的距离，同时充当 visited。
     *    用 unordered_map<T,int> 而不用 unordered_set + 独立距离，因为扩展时需要 O(1) 读距离。
     */
    unordered_map<T,int> distStart,distEnd;
    queue<T> qStart,qEnd;

    /**
     *  @note
     *    顺序细节：
     *      emplace 拷贝一份进 map 后，才能把 start/end move 进队列。
     *      如果写成 qStart.push(std::move(start)); distStart.emplace(start, 0);
     *      start 已被移动为空对象，map 里存的就是空值——这一步极易写反。
     */
    distStart.emplace(start,0);
    distEnd.emplace(end,0);
    qStart.push(move(start));
    qEnd.push(move(end));

    /**
     *  @note
     *    扩展某一侧 BFS 的一整层。
     *    返回 >=0：本层扩展过程中发现对侧已访问的节点，值即完整最短距离；
     *    返回 -1：本层扩展完毕仍未相遇。
     */
    auto expand=[&](queue<T>& q,unordered_map<T,int>& distSelf,unordered_map<T,int>& distOther)->int{
        while(!q.empty()){
            T u=q.front();
            q.pop();

            for(auto& v:getNeighbors(u)){
                if(distSelf.count(v)) continue;
                if(distOther.count(v)) return distSelf[u]+distOther[v];

            }
        }
    }
}

int main(){


    return 0;
}