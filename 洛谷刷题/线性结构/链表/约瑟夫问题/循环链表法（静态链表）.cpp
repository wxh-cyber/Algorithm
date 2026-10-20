/**
 *  @link https://www.luogu.com.cn/problem/P1996
 */
 #include <cstdio>
 using namespace std;

 const int MAXN=105;

 int n,m;                                        //n表示总人数，m表示特定的报数   
 int next[MAXN];                                 //next数组用来保存当前节点的下一个节点的下标

 int main(){
    scanf("%d %d",&n,&m);                //输入总人数和特定报数

    for(int i=1;i<n;i++){
        next[i]=i+1;                            //易知从1~n-1的下一个节点下标
    }
    next[n]=1;                                  //第n个节点的下一个节点的下标为1

    int prev=n,cur=1;                           //采用prev和cur分别表示前驱节点和当前节点的下标
    for(int i=1;i<=n;i++){                      //由于队列中所有人最终都要出队，所以外层循环n次
        for(int j=1;j<m;j++){                   //由于初始状态下的cur指针指向的人，报数为1，故移动m-1次后，cur指向的人报数一定为m
            prev=cur;                           //每次移动都更新prev和cur指针
            cur=next[cur];
        }

        printf("%d ",cur);              //输出报数为m的人的下标
        next[prev]=next[cur];                  //通过赋新的值，等同于删除了cur这个节点
        cur=next[cur];                         //cur指向被删除节点的下一个节点
    }

    return 0;
 }