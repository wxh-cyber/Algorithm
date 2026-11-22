#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/**
 *  @brief bidirectionalBFS - 双向BFS
 *  @param {T} start - 开始节点
 *  @param {T} end - 结束节点
 *  @param {F} getNeighbors - 获取邻接节点
 *  @return {int} result - 从起点遍历到终点所需总步数
 *  @note
 *     约定：
 *       - T 需可 std::hash（int / string 等；pair 建议编码成 int）
 *       - getNeighbors(node) 返回 vector<T>（值类型），需可范围 for 遍历
 *       - 边权全为 1；带权图请用双向 Dijkstra
 *     返回：
 *       - start == end   → 0
 *       - 存在路径       → 最少边数
 *       - 不可达         → -1
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

    int R=grid.size(),C=grid[0].size();                           //R和C分别表述行数和列数
    //采用方向数组表示上下左右四个方向
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    /**
     *  @brief encode - 二维转一维
     *  @param {int} r - 行下标
     *  @param {int} c - 列下标
     *  @return {int} result - 转换后的一维结果
     */
    auto encode=[C](int r,int c){
        return r*C+c;
    };

    /**
     *  @brief neighbors - 获取节点v的临接节点
     *  @param {int} v - 节点v，形式为一维形式
     *  @return {vector<int>} - v的邻接节点数组，形式均为一维形式
     */
    auto neighbors=[&](int v){
        int x=v/C,y=v%C;                                //从一维恢复到二维

        vector<int> res;
        for(int i=0;i<4;i++){                           //依次遍历上下左右四个方向
            int nx=x+dx[i];
            int ny=y+dy[i];

            //如果遍历的点没有越界，且为空地，则加入数组
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&grid[nx][ny]==0){
                res.push_back(encode(nx,ny));
            }
        }

        return res;                                     //返回最终结果
    };

    //调用双向BFS获得最终结果
    int steps=bidirectionalBFS(encode(0,0),encode(R-1,C-1),neighbors);
    cout<<"最短步数= "<<steps<<endl;
}

// ---------- 测试 2：LeetCode 127 单词接龙 ----------
// 每次只能改一个字符，求 beginWord -> endWord 经过的最少单词数
/**
 *  @link https://leetcode.cn/problems/word-ladder/description/
 *  @brief ladderLength - 单词变换步数函数
 *  @param {string} beginWord - 初始字符
 *  @param {string} endWord - 结束字符
 *  @param {vector<string>} wordList - 单词列表
 *  @return {int} steps - 最终变换步数
 */
int ladderLength(const string& beginWord,const string& endWord,vector<string> wordList){
    //将wordList中的所有单词都映射到set中，以去除重复的情况
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    //如果最终的单词都不在set中，则说明无论如何都不能满足要求，直接返回0
    if(!wordSet.count(endWord)) return 0;

    /**
     *  @brief neighbors - 获取单词的所有变换形式
     *  @param {string} word - 初始的单词
     *  @return {vector<string>} res - 所有可能变换结果
     */
    auto neighbors=[&](const string& word){
        vector<string> res;                                //res存放所有可能的变换结果
        string cur=word;                                   //cur拷贝一份当前的word

        for(size_t i=0;i<cur.size();i++){                  //依次遍历单词中的每一位
            char old=cur[i];                               //记录原单词中的特定一位的字母为old
            for(char c='a';c<='z';c++){                    //从a到z遍历所有字母
                if(c==old) continue;                       //遍历到原先的字母，直接跳过
                cur[i]=c;                                  //否则视为一种新的情况
                //在set中查找这种情况，如果找到了，符合要求，加入res
                if(wordSet.count(cur)) res.push_back(cur);
            }

            cur[i]=old;                                    //回溯
        }

        return res;                                        //返回最终遍历结果
    };

    //获取最终步数
    int steps=bidirectionalBFS(beginWord,endWord,neighbors);
    //输出结果
    return steps==-1?0:steps;
}

/**
 *  @brief testLadder - 测试用例
 *  @return 无
 */
void testLadder(){
    int r=ladderLength("hit","cog",{"hot","dot","dog","lot","log","cog"});
    cout<<r<<endl;
}

// ---------- 测试 3：不可达场景 ----------
// 起终点被墙完全隔开，应返回 -1
void testUnreachable(){
    vector<vector<int>> grid={
        {0,1,0},
        {0,1,0},
        {0,1,0}
    };

    int R=grid.size(),C=grid[0].size();
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    auto neighbors=[&](int v){
        int r=v/C,c=v%C;

        vector<int> res;
        for(int i=0;i<4;i++){
            int nx=r+dx[i];
            int ny=c+dy[i];

            if(nx>=0&&nx<R&&ny>=0&&ny<C&&grid[nx][ny]==0){
                res.push_back(nx*C+ny);
            }
        }

        return res;
    };

    int steps=bidirectionalBFS(0, C-1, neighbors);
    cout<<steps<<endl;
}

int main(){
    testMaze();
    testLadder();

    return 0;
}