/**
 *  @link https://www.luogu.com.cn/problem/P1024
 */

 #include <iostream>
 #include <cstdio>
 #include <cmath>
 using namespace std;

 double a,b,c,d;

 double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
 }

 double divide(double l,double r){
    while(fabs(r-l)>1e-7){
        double mid=(l+r)/2.0;
        if(f(mid)*f(l)<=0) r=mid;
        else l=mid;
    }

    return l;
 }

 int main(){
    cin>>a>>b>>c>>d;

    int cnt=0;
    for(int i=-100;i<=100;i++){
        double x1=i,x2=i+1;
        double y1=f(x1),y2=f(x2);

        if(fabs(y1)<1e-7){
            printf("%.2lf",x1);
            cnt++;
        }else if(y1*y2<0){
            printf("%.2lf",divide(x1, x2));
            cnt++;
        }

        if(cnt==3) break;
    }

    return 0;
 }