/**
 *  @link https://www.luogu.com.cn/problem/P1182
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
typedef long long ll;

const int MAXN=1e5+5;

int n,m;                                                     //n表示输入的数的个数，m表示要求的段数
ll leftx,rightx,mid,ans;                                     //leftx、rightx和mid分别表示左右两侧区间和中央，ans存储最终结果
ll nums[MAXN];                                               //nums存储所有输入的数

/**
 *  @brief read - 快速读入
 *  @return result - 快速读入结果
 */
inline ll read(){
    ll x=0;
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

    return x*f;
}

/**
 *  @brief check - 检查x是否符合条件
 *  @param {ll} x - 被检查的数x
 *  @return {true|false} - 是否符合条件
 */
bool check(ll x){
    int num=1;                                           //num统计段数，初始状态下为一段
    ll sum=0;                                            //sum累计每一段总和

    for(int i=0;i<n;i++){                                //逐个遍历所有的数
        if(sum+nums[i]<=x){                              //如果加上当前的数后，还能满足要求，则加上当前的数
            sum+=nums[i];
        }else{
            sum=nums[i];                                 //否则不能加上当前的数，以当前的数为基准开辟新的一段
            num++;                                       //更新段的数量
        }
    }

    if(num<=m) {
        return true;                                     //如果能用更少的段达到要求，返回true
    }else{
        return false;                                    //否则不符合要求
    }
}

int main(){
    n=read();                                            //输入数的总数
    m=read();                                            //输入段的数量
    for(int i=0;i<n;i++){
        nums[i]=read();                                  //逐个输入所有的数
        leftx=max(leftx,nums[i]);            //左边界显然应该是所有输入的数的最大值
        rightx+=nums[i];                                 //右边界是所有输入的数的总和
    }

    while(leftx<=rightx){
        mid=leftx+(rightx-leftx)/2;                     //不断在区间中取中间的数
        if(check(mid)){                              //如果中间的数符合要求
            ans=mid;                                    //更新答案
            rightx=mid-1;                               //可能存在更小的数符合要求，故更新右侧rightx
        }else{
            leftx=mid+1;                                //否则更新左侧leftx
        }
    }

    cout<<ans<<endl;                                   //输出最终答案

    return 0;
}