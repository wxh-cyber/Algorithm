/**
 *  @link https://www.luogu.com.cn/problem/P3743
 */

 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cmath>
 #include <climits>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e5+5;

 int n,p;                                              //n设备数量，p充电宝单位时间内充电的单位
 double leftx,rightx,mid,ans;                          //letfx、rightx和mid分别表示左右区间和中央，ans记录最终答案
 int a[MAXN],b[MAXN];                                  //a[i]表示第i个设备消耗电量的能力，b[i]表示第i个设备初始状态下所存电量
 ll sum=0;                                             //sum统计所有设备每秒消耗的电量

 /**
  *  @brief check - 检验时长t是否符合条件
  *  @param {double} t - 时长t
  *  @return {true|false} - 是否符合条件
  */
 bool check(double t){
    double sum0=0,all=p*t;                             //sum0表示在时长t内，需要给所有设备充电的总数，all表示时长t内，充电宝充电总量
    for(int i=1;i<=n;i++){                             //依次遍历所有设备
        if(a[i]*t>b[i]){                               //如果在时长t内，第i台设备的耗电总量大于原先的初始电量，则需要充电
            sum0+=a[i]*t-b[i];                         //累加对应的充电量
        }
    }

    if(sum0<=all){
        return true;                                   //如果充电宝能充这么多电，则符合要求
    }else{
        return false;                                  //否则不符合要求
    }
 }

 int main(){
    cin>>n>>p;                                         //输入设备数和充电宝充电数
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];                               //依次输入每台设备的耗电数和初始电量
        sum+=a[i];                                     //累加所有设备耗电量
    }

    if(sum<=p) {
        printf("%d",-1);                       //如果充电宝充电数大于等于所有设备耗电量，则始终可以供电
        return 0;
    }

    leftx=0,rightx=LLONG_MAX;                          //初始化左右区间长度，注意右侧要定义为LLONG_MAX以保证精度
    while(abs(leftx-rightx)/max(1.0,rightx)>1e-4){
        mid=leftx+(rightx-leftx)/2;                    //每次取中间的数
        if(check(mid)){
            ans=mid;                                   //先更新答案
            leftx=mid;                                 //如果符合要求，可能存在比t更大的数，因此更新左侧区间
        }else{
            rightx=mid;                                //否则更新右侧区间
        }
    }

    printf("%.10lf",ans);                      //输出最终结果

    return 0;
 }