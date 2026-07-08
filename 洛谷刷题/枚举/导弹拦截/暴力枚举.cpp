/**
 *  @link https://www.luogu.com.cn/problem/P1158
 */

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN=1e5+5;

int n;                                                //导弹的数量
int x11,y11,x22,y22;                                  //两套导弹系统的坐标，注意这里由于引入了cmath库，所以不能出现y1
int ans=0x3f3f3f3f;                                   //答案
struct daodan{
    int d1;                                           //到第一个系统的距离
    int d2;                                           //到第二个系统的距离
    int x;                                            //导弹的横坐标
    int y;                                            //导弹的纵坐标
}daodans[MAXN];

/**
 *  @brief  按照到第一个系统的距离进行排序
 *  @param  a 导弹a
 *  @param  b 导弹b
 *  @retval 导弹a到第一个系统的距离是否小于导弹b到第一个系统的距离
 */
bool cmp(daodan a,daodan b){
    return a.d1<b.d1;
}

int main(){
    cin>>x11>>y11>>x22>>y22>>n;                                     //输入两套导弹系统的坐标和导弹的数量
    memset(daodans,0,sizeof(daodans));                //初始化导弹数组
    
    for(int i=1;i<=n;i++){
        cin>>daodans[i].x>>daodans[i].y;                              //输入导弹的坐标
        //计算导弹到第一个系统的距离
        daodans[i].d1=pow(daodans[i].x-x11,2)+pow(daodans[i].y-y11,2);        
    }

    //根据所有的导弹到第一个系统的距离进行从小到大的排序
    sort(daodans+1,daodans+n+1,cmp);

    for(int i=n;i>0;i--){
        //计算导弹到第二个系统的距离
        int tmp=pow(daodans[i].x-x22,2)+pow(daodans[i].y-y22,2);
        //更新到第二个系统的距离为所有导弹到第二个系统的距离的最大值
        daodans[i].d2=max(tmp,daodans[i+1].d2);
    }

    for(int i=0;i<=n;i++){
        //计算答案
        int t=daodans[i].d1+daodans[i+1].d2;
        ans=min(ans,t);
    }
    
    cout<<ans;
    
    return 0;
}