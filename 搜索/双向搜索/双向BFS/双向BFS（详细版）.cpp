#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 *  @brief bidirectionalBFS - 双向BFS
 *  @param {T} start - 开始节点
 *  @param {T} end - 结束节点
 *  @param {F} getNeighbors - 获取邻接节点
 *  @return {int} result - 从起点遍历到终点所需总步数
 */
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
            T u=move(q.front());
            q.pop();

            const int step=distSelf.find(u)->second+1;

            for(auto& v:getNeighbors(u)){
                //该状态在正向遍历中已经被访问过，因此跳过
                if(distSelf.count(v)) continue;
                //若正向和反向相遇，则返回最终遍历的总步数：正向步数+反向步数+1                                     
                if(distOther.count(v)) return distSelf[u]+distOther[v]+1;

                //否则，说明正向遍历还没有访问过v节点，增加v节点的映射
                distSelf.emplace(v,step);
                //v节点入队
                q.push(v);
            }
        }

        return -1;
    };

    /**
     *  @note
     *    每轮拓展“较小”的一侧。
     *    若某一侧队列先耗尽仍未相遇，则说明不可达。
     */
    while(!qStart.empty()&&!qEnd.empty()){
        int ans=(qStart.size()<=qEnd.size())?expand(qStart,distStart,distEnd):expand(qEnd,distEnd,distStart);
        if(ans!=-1) return ans;
    }

    return -1;
}

// =====================================================================
//                          测试代码
// =====================================================================

// ---------- 测试 1：网格迷宫 ----------
// 0 = 空地，1 = 墙；四方向移动；求 (0,0) 到 (R-1,C-1) 的最少步数
void testMaze(){
    vector<vector<int>> grid={
        {0,0,1,0,0},
        {0,0,1,0,1},
        {0,0,0,0,1},
        {1,1,0,1,0},
        {0,0,0,0,0}
    };

    int R=grid.size(),C=grid[0].size();
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    auto encode=[C](int r,int c){
        return r*C+c;
    };

    auto neighbors=[&](int v){
        int x=v/C,y=v%C;
        vector<int> res;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0&&nx<R&&ny>=0&&ny<C&&grid[nx][ny]==0){
                res.push_back(encode(nx,ny));
            }
        }

        return res;
    };

    int steps=bidirectionalBFS(encode(0,0),encode(R-1,C-1),neighbors);
    cout<<"最短步数= "<<steps<<endl;
}

int main(){
    testMaze();

    return 0;
}