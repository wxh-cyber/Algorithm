/**
 *  @link https://www.luogu.com.cn/problem/P1803
 */

 #include <iostream>
 #include <algorithm>
 using namespace std;

 const int MAXN=1e6+7;

int n,ans;                              //n为比赛数量，ans为覆盖的最多比赛数量

struct node {                           //定义每场比赛的开始时间和结束时间
    int start;
    int end;
}com[MAXN];

/**
 *  @brief 比较函数，按照结束时间早的排序，如果结束时间相同，则按照开始时间晚的排序
 *  @param x 第一个比赛
 *  @param y 第二个比赛
 *  @return 如果第一个比赛的结束时间小于第二个比赛的结束时间，则返回true，否则返回false
 *  @note 注意：优先排结束时间，是为了保证，不把最后一场比赛排到前面
 */
bool cmp(node x,node y){
    if(x.end!=y.end) return x.end<y.end;
    return x.start>y.start;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>com[i].start>>com[i].end;
    }

    sort(com+1,com+n+1,cmp);

    int end=-1;                                         //定义在动态迭代过程中的比赛结束时间
    for(int i=1;i<=n;i++){
        if(com[i].start>=end){
            ans++;
            end=com[i].end;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}