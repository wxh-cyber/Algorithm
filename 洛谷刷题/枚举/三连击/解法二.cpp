/**
 *  @link https://www.luogu.com.cn/problem/P1008
 */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAXN=9;

ll num[9];                                               //num用于存储1-9这九个数字

/**
 *  @brief get_num
 *  @param left  左边界
 *  @param right 右边界
 *  @return  返回left到right之间的数字
 */
ll get_num(ll left,ll right){
    ll temp=0;
    for(int i=left;i<right;i++){
        temp+=num[i];
        temp*=10;
    }
    temp+=num[right];

    return temp;
}

int main(){
    for(int i=0;i<9;i++){
        num[i]=i+1;
    }

    do{
        ll a=get_num(0,2);
        ll b=get_num(3,5);
        ll c=get_num(6,8);

        if (a*2==b&&a*3==c) {                                    //判断是否满足条件
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }while(next_permutation(num,num+9));             //使用next_permutation函数进行全排列
    //具体说明可参照模板部分的内容

    return 0;
}