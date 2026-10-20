/**
 *  @link https://www.luogu.com.cn/problem/P1996
 */

 #include <iostream>
 #include <queue>
 using namespace std;

 int n,m;                                            //n表示总人数，m表示特定的序号
 int nowNum=1;                                       //nowNum表示当前遍历到的人的报数
 queue<int> q;                                       //采用队列进行处理

 int main(){
    cin>>n>>m;                                       //输入总人数和特定序号
    for(int i=1;i<=n;i++){                           //初始化队列
        q.push(i);
    }

    while(!q.empty()){                               //队列非空时，持续循环
        if(nowNum==m){                               //当前人的报数为m时，输出这个人的下标
            cout<<q.front()<<" ";
            nowNum=1;                                //将nowNum重置为1
        }else{
            nowNum++;                                //当前人的报数不是m时，nowNum自增
            q.push(q.front());                   //将这个人转移到队尾
        }

        q.pop();                                     //无论当前人的报数是否为m，这个人都需要出队
    }

    return 0;
 }