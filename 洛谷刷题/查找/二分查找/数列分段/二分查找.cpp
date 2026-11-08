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

int n,m;
ll leftx,rightx,mid,ans;
ll nums[MAXN];

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

bool check(ll x){
    int num=1;
    ll sum=0;

    for(int i=0;i<n;i++){
        if(sum+nums[i]<=x){
            sum+=nums[i];
        }else{
            sum=nums[i];
            num++;
        }
    }

    if(num<=m) {
        return true;
    }else{
        return false;
    }
}

int main(){
    n=read();
    m=read();
    for(int i=0;i<n;i++){
        nums[i]=read();
        leftx=max(leftx,nums[i]);
        rightx+=nums[i];
    }

    while(leftx<=rightx){
        mid=leftx+(rightx-leftx)/2;
        if(check(mid)){
            ans=mid;
            rightx=mid-1;
        }else{
            leftx=mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
}