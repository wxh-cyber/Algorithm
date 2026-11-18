/**
 *  @link https://www.luogu.com.cn/problem/P1379
 */

 #include <iostream>
 #include <utility>
 #include <cstdlib>
 #include <string>
 #include <queue>
 #include <map>
 using namespace std;

 /**
  *  @note
  *    utility:swap
  *    cstdlib:exit
  */

 int xx,yy;                                            //数字0的坐标
 string I,O="123804765";                               //输入字符串和输出字符串

 struct State{
    int A[3][3];
    State()=default;

    /**
     *  @brief State - 构造函数
     *  @param {string} s - 初始化字符串
     *  @return 无
     */
    State(string s){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                A[i][j]=s[i*3+j]-'0';
            }
        }
    }

    /**
     *  @brief < - 运算符重载
     *  @param {State} a - 比较对象a
     *  @param {State} b - 比较对象b
     *  @return {true|false} - 比较结果
     */
    friend bool operator<(const State &a,const State &b){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a.A[i][j]!=b.A[i][j]){
                    return a.A[i][j]<b.A[i][j];
                }
            }
        }

        return false;
    }
 };

 queue<State> q1,q2;                                             //q1和q2分别处理双向遍历的BFS
 map<State,int> mp1,mp2;                                         //mp1[u]记录从正向遍历到u时经过的步数

 //方向数组，遍历上下左右四个方向
 int dx[4]={-1,1,0,0};
 int dy[4]={0,0,-1,1};

 /**
  *  @brief bfs - 双端bfs
  *  @param {queue<State>} q - 单向处理队列
  *  @param {map<State,int>} m1 - 正向映射
  *  @param {map<State,int>} m2 - 反向映射
  *  @return 无
  */
 void bfs(queue<State> &q,map<State,int> &m1,map<State,int> &m2){
    auto u=q.front();                                 //获取到队首元素u
    q.pop();                                                 //队首元素出队

    //搜寻0的下标，并记录为(xx,yy)
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(u.A[i][j]==0){
                xx=i;
                yy=j;
            }
        }
    }

    for(int i=0;i<4;i++){
        int nx=xx+dx[i];                           //依次搜寻四个方向
        int ny=yy+dy[i];
        if(nx>=0&&nx<3&&ny>=0&&ny<3){              //如果搜寻的对象没有越界
            auto v=u;                       //复制一份当前的对象u，存入v
            swap(v.A[xx][yy],v.A[nx][ny]);               //交换这个搜寻点与0的位置
            
            if(m2.count(v)){               //如果反向映射中存在v，说明此时两者已经相遇
                cout<<m1[u]+m2[v]<<endl;          //返回最终的结果，即从正向出发u的步数和反向出发v的步数之和
                exit(0);                     //退出程序
            }

            if(!m1.count(v)){              //反之则是还没有相遇，记录下正向遍历到v的步数
                m1[v]=m1[u]+1;                    //显然在u的步数上加1
                q.push(v);                    //v入队
            }
        }
    }
 }

 int main(){
    cin>>I;                                           //输入初始字符串
    State in,out;                                     //in和out分别表示初始状态和结束状态
    in=I;                                             //初始化开始和结束状态
    out=O;

    mp1[in]=0;                                        //从正向遍历初始状态显然为0
    q1.push(in);                                 //初始状态入队
    mp2[out]=1;                                       //从反向遍历结束状态，这里为1是考虑到两者相遇时，桥接还需要1步
    q2.push(out);                                //结束状态入队

    if(I==O){                                        //如果初始状态和结束状态相同，则无需操作，直接返回0
        cout<<0;
        return 0;
    }

    while(1){
        //每次都正向遍历和反向遍历
        bfs(q1,mp1,mp2);
        bfs(q2,mp2,mp1);
    }

    return 0;
 }