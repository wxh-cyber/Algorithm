/**
 *  @link https://www.luogu.com.cn/problem/P1706
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 *  algorithm:包含了next_permutation函数
 *  iomanip:包含了setw函数
 */

const int MAXN=15;

int n;
int num[MAXN]={0};

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        num[i]=i;
    }

    do{
        for(int i=1;i<=n;i++){
            cout<<setw(5)<<num[i];
        }
        cout<<endl;
        //直接使用next_permutation函数进行全排列
    }while(next_permutation(num+1,num+n+1));
    
    return 0;
}