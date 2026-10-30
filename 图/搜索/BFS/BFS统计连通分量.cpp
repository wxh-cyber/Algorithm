#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//定义方向数组，用于上下左右移动
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

/**
 *  @brief bfs - 广度优先遍历
 *  @param {vector<vector<char>>} grid - 遍历的图
 *  @param {int} x - 出发点横坐标
 *  @param {int} y - 出发点纵坐标
 *  @return 无
 */
void bfs(vector<vector<char>>& grid,int x,int y){
    int rows=grid.size();                                     //行数
    int cols=grid[0].size();                                  //列数

    queue<pair<int,int>> q;                                   //采用队列q进行处理
    q.push({x,y});                                            //出发点坐标入队
    grid[x][y]='0';                                           //标记为已访问

    while(!q.empty()){
        auto [curX,curY]=q.front();                           //获取到队首的横纵坐标
        q.pop();                                              //队首元素出队

        //遍历四个方向
        for(int i=0;i<4;i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];

            //如果遍历到的点位于图内，且该节点为1
            if(nx>=0&&nx<rows&&ny>=0&&ny<cols&&grid[nx][ny]=='1'){
                grid[nx][ny]='0';                              //标记为0
                q.push({nx,ny});                               //入队
            }
        }
    }
}

/**
 *  @brief numIslands - 岛屿数量计算函数
 *  @param {vector<vector<char>>} - 遍历的图
 *  @return {int} count - 岛屿数量
 */
int numIslands(vector<vector<char>>& grid){
    //如果图为空，直接返回0
    if(grid.empty()) return 0;

    int rows=grid.size();                                      //行数
    int cols=grid[0].size();                                   //列数
    int count=0;                                               //岛屿数量

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]=='1'){
                //发现一座岛屿，使用bfs标记整座岛屿
                bfs(grid,i,j);
                count++;                                       //更新岛屿数量
            }
        }
    }

    return count;                                              //返回最终结果
}

int main(){
    vector<vector<char>> grid={
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout<<"岛屿数量："<<numIslands(grid)<<endl;

    return 0;
}