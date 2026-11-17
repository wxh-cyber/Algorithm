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

 queue<State> q1,q2;
 map<State,int> mp1,mp2;

 //方向数组，遍历上下左右四个方向
 int dx[4]={-1,1,0,0};
 int dy[4]={0,0,-1,1};

 void bfs(queue<State> &q,map<State,int> &m1,map<State,int> &m2){
    auto u=q.front();
    q.pop();

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(u.A[i][j]==0){
                xx=i;
                yy=j;
            }
        }
    }

    for(int i=0;i<4;i++){
        int nx=xx+dx[i];
        int ny=yy+dy[i];
        if(nx>=0&&nx<3&&ny>=0&&ny<3){
            auto v=u;
            swap(v.A[xx][yy],v.A[nx][ny]);
            
            if(m2.count(v)){
                cout<<m1[u]+m2[v]<<endl;
                exit(0);
            }

            if(!m1.count(v)){
                m1[v]=m1[u]+1;
                q.push(v);
            }
        }
    }
 }

 int main(){
    cin>>I;
    State in,out;
    in=I;
    out=O;

    mp1[in]=0;
    q1.push(in);
    mp2[out]=1;
    q2.push(out);

    if(I==O){
        cout<<0;
        return 0;
    }

    while(1){
        bfs(q1,mp1,mp2);
        bfs(q2,mp2,mp1);
    }

    return 0;
 }