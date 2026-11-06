/**
 *  @link https://www.luogu.com.cn/problem/P3853
 */

 #include <iostream>
 #include <cstdio>
 #include <cctype>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e5+5;

 int n,k;                                               //n表示原有的路标数，k表示至多插入的数量
 ll l,leftx,rightx,mid,ans;                             //l表示起点到终点距离，leftx、rightx和mid分表表示左右区间和中央，ans记录最终结果
 ll dist[MAXN];                                         //dist[i]表示第i个路标到起点的距离

 /**
  *  @brief read - 快速读入
  *  @return {int} result - 快速读入结果
  */
 inline int read(){
    int x=0;
    int f=1;
    char ch=getchar();

    while(!isdigit(ch)&&!isgraph(ch)){
        ch=getchar();
    }

    if(ch=='-'){
        f=-1;
        ch=getchar();
    }

    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^'0');
        ch=getchar();
    }

    return f*x;
 }

 /**
  *  @brief check - 检查距离x是否符合要求
  *  @param {long long} x - 距离
  *  @return {true|false} - 是否符合要求
  */
 bool check(ll x){
    int num=0;                                              //num统计当前已经新插入的路标数
    ll prev=0;                                              //prev表示前一个路标距离起点距离，初始状态为0

    //当x==0时，系统会进入死循环，因此需要进行特判
    if(x==0) return false;

    for(int i=1;i<=n+1;i++){                                //依次遍历所有路标，以及最后的终点
        if(dist[i]-prev>x){                                 //如果当前一个路标距离前一个路标的距离大于当前的x
            prev+=x;                                        //在前一个路标后每次距离x就插入一个新的路标
            i--;                                            //i始终遍历的是原有的路标，因此在插入新的路标之后，i不应该发生变化
            num++;                                          //每插入一个路标，num自增一次
        }else{
            prev=dist[i];                                   //否则更新prev为当前的dist[i]
        }
    }

    if(num<=k){
        return true;                                        //如果插入路标数小于等于k，符合条件
    }else{
        return false;                                       //反之，不符合条件
    }
 }

 int main(){
    l=read();                                            //输入起点到终点的距离
    n=read();                                            //输入路标总数n
    k=read();                                            //输入待插入的路标数k
    for(int i=1;i<=n;i++){
        dist[i]=read();                                  //依次输入n个路标到起点的距离
    }
    dist[n+1]=l;                                         //特别地，用dist[n+1]表示终点到起点的距离

    leftx=0;                                             //初始化二分区间左右两侧
    rightx=l;
    while(leftx<=rightx){
        mid=leftx+(rightx-leftx)/2;
        if(check(mid)){                               //如果mid符合条件
            ans=mid;                                    //更新答案
            rightx=mid-1;                               //可能存在更小的x，因此更新rightx
        }else{
            leftx=mid+1;                                //否则更新leftx
        }
    }

    cout<<ans<<endl;                                    //输出最终答案

    return 0;
 }