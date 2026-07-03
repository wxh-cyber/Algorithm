/**
 *  @link https://www.luogu.com.cn/problem/P1088
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=1e5+5;

int n,m;                                             //n表示总共参与排列的个数，m表示要加上的数
int a[MAXN]={0};                                 //a用于存放输入的数
bool used[MAXN]={false};                         //used用于标记某个数是否已经被使用过

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];                                   //依次输出所有参与排列的数
        int x=a[i];

        //核心：计算当前在未使用的数中，比a[i]小的数有多少个
        for(int j=1;j<=a[i];j++){
            x-=used[j];                              // 如果 j 已经被用过了，那它不能算作"比 a[i] 小的可用数"，所以 x 减 1
        }

        used[a[i]]=true;                             //标记当前这个数已经被使用过了
        a[i]=x-1;                                    // 将 a[i] 更新为康托展开的系数（即：在剩余数中它是第几小的，从0开始）
    }

    a[n]+=m;                                         // 将 m 加到最后一位（代表 0! 的位）

    for(int i=n;i>0;i--){
        /**
         * 逻辑：康托展开本质上是把排列看作一个混合进制的数。第𝑖位的进制是 𝑛−𝑖+1（即第一位除以 𝑛，第二位除以 𝑛−1…）。
         */
        a[i-1]=a[i]/(n-i+1);                         // 当前位的值超过进制，向高位进位
        a[i]%=(n-i+1);                               // 当前位保留余数
    }
    
    // 逆康托展开
    memset(used,0,sizeof(used));      // 清空 used 数组，用于记录新排列中哪些数被用过了

    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++){
            if(used[j]){                            // 如果 j 已经被用了，说明我们要找的目标数要往后挪一位
                a[i]++;
            }
        }

        cout<<a[i]+1<<" ";                          // 输出结果（因为是从0开始计数的，输出要+1）
        used[a[i]]=1;                               // 标记当前这个数已经被使用过了

    }

    return 0;
}