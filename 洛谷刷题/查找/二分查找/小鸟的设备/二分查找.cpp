/**
 *  @link https://www.luogu.com.cn/problem/P3743
 */

 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 typedef long long ll;

 const int MAXN=1e5+5;

 int n,p;
 double leftx,rightx,mid,ans;
 int a[MAXN],b[MAXN];
 ll sum=0; 

 bool check(double t){
    double sum0=0,all=p*t;
    for(int i=1;i<=n;i++){
        if(a[i]*t>b[i]){
            sum0+=a[i]*t-b[i];
        }
    }

    if(sum0<=all){
        return true;
    }else{
        return false;
    }
 }

 int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }

    if(sum<=p) {
        printf("%d",-1);
        return 0;
    }

    leftx=0,rightx=1e5;
    while(abs(leftx-rightx)/max(1.0,rightx)>1e-4){
        mid=leftx+(rightx-leftx)/2;
        if(check(mid)){
            ans=mid;
            leftx=mid;
        }else{
            rightx=mid;
        }
    }

    printf("%.10lf",ans);

    return 0;
 }