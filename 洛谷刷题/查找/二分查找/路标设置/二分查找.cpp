/**
 *  @link https://www.luogu.com.cn/problem/P3853
 */

 #include <iostream>
 #include <cstdio>
 #include <cctype>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e5+5;

 int n,k;
 ll l,leftx,rightx,mid,ans;
 ll dist[MAXN];

 inline int read(){
    int x=0;
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

    return f*x;
 }

 bool check(ll x){
    int num=0;
    ll prev=0;

    //当x==0时，系统会进入死循环，因此需要进行特判
    if(x==0) return false;

    for(int i=1;i<=n+1;i++){
        if(dist[i]-prev>x){
            prev+=x;
            i--;
            num++;
        }else{
            prev=dist[i];
        }
    }

    if(num<=k){
        return true;
    }else{
        return false;
    }
 }

 int main(){
    l=read();
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        dist[i]=read();
    }
    dist[n+1]=l;

    leftx=0;
    rightx=l;
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