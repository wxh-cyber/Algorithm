/**
 *  @link https://www.luogu.com.cn/problem/P1706
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=15;

int n;
int num[MAXN];
bool used[MAXN];

/**
 *  @brief print
 *  @return void
 */
void print(){
    for(int i=1;i<=n;i++){
        printf("%5d",num[i]);
    }
    cout<<endl;
}

/**
 *  @brief dfs
 *  @param k  表示当前已经放置了k个数
 *  @return void
 */
void dfs(int k){
    if(k==n){
        print();
        return;
    }

    for(int i=1;i<=n;i++){                   //枚举每一个数
        if(!used[i]){                        //如果这个数没有被使用过
            used[i]=true;                    //标记这个数已经被使用过
            num[k+1]=i;                      //将这个数放入num数组中
            dfs(k+1);                      //继续搜索下一个数
            used[i]=false;                   //回溯
        }
    }
}

int main(){
    cin>>n;
    dfs(0);

    return 0;
}