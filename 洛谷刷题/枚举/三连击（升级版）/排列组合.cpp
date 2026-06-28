/**
 *  @link https://www.luogu.com.cn/problem/P1618
 */

 /**
  *  说明：P1008的排列组合解法同样适用于本题。
  */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAXN=9;

int k1,k2,k3;
int ans;
ll num[9];

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
    cin>>k1>>k2>>k3;                                   //输入三个比例
    
    //初始化数组
    for(int i=0;i<9;i++){
        num[i]=i+1;
    }

    do {
        //构造出三个数
        ll a=get_num(0,2);
        ll b=get_num(3,5);
        ll c=get_num(6,8);

        //根据比例关系进行判断
        if(a*k2==b*k1&&a*k3==c*k1){
            cout<<a<<" "<<b<<" "<<c<<endl;
            ans++;
        }
    }while(next_permutation(num,num+9));

    //判断无解情况
    if(!ans) {
        cout<<"No!!!";
    }
    
    return 0;
}