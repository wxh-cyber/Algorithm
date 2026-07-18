/**
 *  @link https://www.luogu.com.cn/problem/P1228
 */

#include <cstdio>
typedef long long ll;
using namespace std;

int k;                                             // 2的k次方
ll x,y,len;                                        // 特殊点坐标(x,y)，棋盘长度len

/**
 *  @brief 计算2的k次方
 *  @param k 2的k次方
 *  @return 2的k次方
 */
ll fun(int k){
    ll sum=1;
    for(int i=1;i<=k;i++){
        sum*=2;
    }

    return sum;
}

/**
 *  @brief 分治
 *  @param x 特殊点横坐标
 *  @param y 特殊点纵坐标
 *  @param a 棋盘左上角横坐标
 *  @param b 棋盘左上角纵坐标
 *  @param l 棋盘边长
 *  @return 无
 */
void solve(ll x,ll y,ll a,ll b,ll l){
    //如果棋盘边长为1，则直接返回
    if(l==1) return;

    /**
     *  @note 
     *    由于棋盘是2的k次方，所以该棋盘一定可以被分成4个小棋盘。解题的关键就是判断特殊点在哪个小棋盘中，然后递归求解。
     */
    if(x-a<=l/2-1&&y-b<=l/2-1){
        printf("%lld %lld 1\n",a+l/2,b+l/2);

        solve(x,y,a,b,l/2);                                    //左上
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);              //右上
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);              //左下
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);         //右下
    }else if(x-a>l/2-1&&y-b<=l/2-1){
        printf("%lld %lld 3\n",a+l/2-1,b+l/2);

        solve(x,y,a+l/2,b,l/2);                            //左下
        solve(a+l/2-1,b+l/2-1,a,b,l/2);                  //左上
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);             //右上
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);        //右下
    }else if(x-a<=l/2-1&&y-b>l/2-1){
        printf("%lld %lld 2\n",a+l/2,b+l/2-1);

        solve(x,y,a,b+l/2,l/2);                             //右上
        solve(a+l/2-1,b+l/2-1,a,b,l/2);                  //左上
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);              //左下
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);          //右下
    }else {
        printf("%lld %lld 4\n",a+l/2-1,b+l/2-1);

        solve(a+l/2-1,b+l/2-1,a,b,l/2);                 //左上
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);            //右上
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);            //左下
        solve(x,y,a+l/2,b+l/2,l/2);                     //右下
    }
}

int main(){
    scanf("%d %lld %lld",&k,&x,&y);
    len=fun(k);

    solve(x,y,1,1,len);
    
    return 0;
}