/**
 *  @link https://www.luogu.com.cn/problem/P1803
 */

 #include <iostream>
 #include <cstring>
 using namespace std;

 const int MAXN=1e6+7;

 /**
  *  @note 
  *    f[i-1]:时刻i没有比赛结束，或者不选结束时刻为i的比赛
  *    f[p[i]]:选择结束时刻为i的比赛，最晚从p[i]时刻开始
 */

 int n;
 int f[MAXN];                  // f[i] = [0, i] 内能参加的最多比赛数
 int p[MAXN];                  // p[e] = 结束时刻为 e 的比赛的最晚开始时刻，-1 表示不存在

 int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    memset(p,-1,sizeof(p));                      //初始化所有比赛结束时刻的开始时刻为-1

    int maxT=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[b]=max(p[b],a);                           //同一时刻结束取最晚时刻开始
        maxT=max(maxT,b);                           //记录最大结束时刻
    }

    for(int i=0;i<=maxT;i++){
        //f[0]=0
        f[i]=(i>0?f[i-1]:0);

        if(p[i]!=-1){
            f[i]=max(f[i],f[p[i]]+1);
        }
    }

    cout<<f[maxT]<<endl;
    
    return 0;
 }