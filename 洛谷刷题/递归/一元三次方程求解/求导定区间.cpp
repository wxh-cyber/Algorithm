/**
 *  @link https://www.luogu.com.cn/problem/P1024
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

double a,b,c,d;                                            //注意初始时，将系数定义为double类型
double ans1,ans2,ans3;                                     //最终的三个根

/**
 *  @brief 求函数f(x)的值
 *  @param x 自变量
 *  @return 函数f(x)的值
 */
double f1(double x){
    double y=a*pow(x,3)+b*pow(x,2)+c*x+d;
    return y;
}

/**
 *  @brief 求函数f(x)的导数
 *  @param x 自变量
 *  @return 函数f(x)的导数
 */
double f2(double x){
    double y=3*a*x*x+2*b*x+c;
    return y;
}

double divide(double x1,double x2){
    //由于类型为浮点数，因此通过1e-7作为临界值来判断取端点的情况
    if(fabs(f1(x1))<1e-7) return x1;
    if(fabs(f1(x2))<1e-7) return x2;

    //通过二分法求根
    while(x2-x1>1e-7){
        double mid=x1+(x2-x1)/2.0;
        if(f1(x1)*f1(mid)<=0) x2=mid;
        else x1=mid;
    }

    return x1;
}

int main(){
    cin>>a>>b>>c>>d;
    //通过求根公式求导数的零点，作为二分法的初始区间的端点
    double x1=(-2.0*b-sqrt(4.0*b*b-4.0*3*a*c))/(2.0*3*a);
    double x2=(-2.0*b+sqrt(4.0*b*b-4.0*3*a*c))/(2.0*3*a);

    //x1不能大于x2
    if(x1>x2) swap(x1,x2);
    
    ans1=divide(-100,x1);
    ans2=divide(x1,x2);
    ans3=divide(x2,100);

    //由于类型为浮点数，因此通过1e-4作为临界值来判断是否为0
    if (fabs(ans1) < 1e-4) ans1 = 0;
    if (fabs(ans2) < 1e-4) ans2 = 0;
    if (fabs(ans3) < 1e-4) ans3 = 0;

    printf("%.2lf %.2lf %.2lf",ans1,ans2,ans3);
    
    return 0;
}