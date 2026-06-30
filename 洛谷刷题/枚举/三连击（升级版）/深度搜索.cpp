/**
 *  @link https://www.luogu.com.cn/problem/P1618
 */

#include <iostream>
using namespace std;

int a,b,c;                                                   //表示三个数的比例          
int x[10]={0};                                           //记录1-9的数字
bool ans=false;                                              //记录是否找到解
bool used[10]={0};                                       //记录1-9的数字是否被使用

/**
 *  @brief 构造一个三位数
 *  @param m 表示第m个数
 *  @return 构造的三位数
 */
int make(int m){
    int sum=0;
    for(int i=3*m-2;i<=3*m;i++){
        sum*=10;
        sum+=x[i];
    }

    return sum;
}

/**
 *  @brief 深度优先搜索
 *  @param n 表示当前搜索到第n个数
 *  @return void
 */
void solve(int n){
    //如果已经搜索到10，则判断是否满足条件
    if(n==10&&make(1)*b==make(2)*a&&make(1)*c==make(3)*a){
        //如果满足条件，则输出结果
        cout<<make(1)<<" "<<make(2)<<" "<<make(3)<<endl;
        ans=true;
        return;
    }

    //如果没有搜索到10，则继续搜索
    for(int i=1;i<=9;i++){
        if(!used[i]){
            x[n]=i;
            used[i]=1;
            solve(n+1);
            used[i]=0;
        }
    }

    return;
}

int main(){
    cin>>a>>b>>c;
    solve(1);
    if(!ans) cout<<"No!!!";

    return 0;
}