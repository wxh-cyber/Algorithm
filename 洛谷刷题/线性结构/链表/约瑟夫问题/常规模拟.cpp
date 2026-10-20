/**
 *  @link https://www.luogu.com.cn/problem/P1996
 */

 #include <cstdio>
 using namespace std;

 const int MAXN=105;

 int n,m;                                           //n表示总人数，m表示指定序号数
 int s=0;                                           //s表示环形队列人数下标，范围1-n
 bool visited[MAXN]={0};                        //visited数组标记是否已经出队

 int main(){
    scanf("%d %d",&n,&m);                   //输入总人数和指定序号数
    for(int i=0;i<n;i++){                          //由于所有人最终都要出列，所以外层循环n次
        for(int j=0;j<m;j++){                      //内层循环记录当前人的报数，j表示报数
            if(++s>n) s=1;                         //当下标s超过n时，重新从1开始遍历
            if(visited[s]) j--;                    //如果当前已经出队，则j应该保持不变
        }

        printf("%d ",s);                    //输出每次报m的人的序号下标
        visited[s]=1;                               //更新出队数组
    }

    return 0;
 }