/**
 *    @link https://www.luogu.com.cn/problem/P1304
 */

#include<iostream>
using namespace std;

//判断是否为质数
long judge(long long a2){
    for(int i=2;i*i<=a2;i++){
        if(a2%i==0) {
            return 0;
        }
    }
    return 1;
}

//对一个数进行分解，输出分解的结果
void print(long long a1){
    for(int i=2;i<=a1;i++){
        if(judge(i)==1&&judge(a1-i)==1){
            cout<<a1<<"="<<i<<"+"<<a1-i;
            return;
        }
    }
}

int main(){
    long long a1;
    cin>>a1;
    for(long long i=4;i<=a1;i+=2){
        print(i);
        cout<<'\n';
    }

    return 0;
}