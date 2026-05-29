/**
 *  @link https://www.luogu.com.cn/problem/P1065
 */
#include <iostream>
#include <cstdio>
using namespace std;

int m,n;                                       //m台机器(同时也对应一个工件总共需要m步)，n个工件
int list[501];                                 //list用于存储工件的加工顺序
struct Information {
    int id;                                    //在第id台机器上加工
    int cost;                                  //花费cost时间
} a[21][21];                                   //a[第几个工件][第几步]

int mac[21][100001]={0};                       //mac[机器编号][时间]
int step[21]={0};                              //每个工件加工到了第几步
int las_time[21]={0};                          //每个工件最后加工的时间

int main() {
    scanf("%d%d",&m,&n);
    // 输入加工顺序                       
    for(int i=1;i<=m*n;i++){
        scanf("%d",list+i);
    }

    //输入单个工件每个步骤应该在哪台机器上加工，以及花费的时间
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j].id);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j].cost);
        }
    }

    for(int i=1;i<=m*n;i++){
        int now=list[i];                          //当前工件编号
        step[now]++;                              //当前工件加工到了第几步
        int id=a[now][step[now]].id;              //加工当前工件的机器编号
        int cost=a[now][step[now]].cost;          //当前工件在当前机器上加工花费的时间

        int s=0;                                  //s记录连续空闲的时间段长度
        for(int j=las_time[now]+1;;j++) {
            if(mac[id][j]==0) {
                s++;                              //如果机器id在j时刻空闲，则时间加1
            }else {
                s=0;                              //一旦遇到占用，连续空闲长度清零，重新找
            }

            //找到了足够长的连续空闲时间
            if(s==cost) {
                //将这段时间在机器上标记为占用
                /**
                 * Q:为什么从j-cost+1开始标记？
                 * A：事实上，j代表的是这段空闲时间末尾的最后一个时间点，因此在计算的时候，j下标是包含在内的，需要对起始下标减一
                 */
                for(int k=j-cost+1;k<=j;k++){
                    mac[id][k]=1;
                }

                //更新全局最晚结束时间
                if(j>ans) ans=j;
                //更新这个工件的最后加工完成时间
                las_time[now]=j;
                break;                           //处理完当前加工任务，跳出循环
            }
        }
    }

    printf("%d",ans);

    return 0;
}