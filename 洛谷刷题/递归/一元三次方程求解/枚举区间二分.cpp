/**
 *  @link https://www.luogu.com.cn/problem/P1024
 */

 #include <iostream>
 #include <cstdio>
 #include <cmath>
 #include <vector>
 using namespace std;

 double a,b,c,d;

 /**
  *  @brief 求函数值
  *  @param x 自变量
  *  @return 函数值
  */
 double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
 }

 /**
  *  @brief 二分法求根
  *  @param l 左端点
  *  @param r 右端点
  *  @return 根
  */
 double divide(double l,double r){
    while(fabs(r-l)>1e-7){
        double mid=(l+r)/2.0;
        if(f(mid)*f(l)<=0) r=mid;
        else l=mid;
    }

    return (l+r)/2.0;
 }

 int main(){
    cin>>a>>b>>c>>d;

    vector<double> roots;                                      //roots 根的集合

    for(int i=-100;i<=100;i++){                                //枚举区间[-100,100)
        double x1=i,x2=i+1;                                    //每次枚举的区间长度为1
        double y1=f(x1),y2=f(x2);

        if(fabs(y1)<1e-7){                                     //如果y1=0，说明x1是根
            if(roots.empty()||fabs(roots.back()-x1)>1e-4) {    //如果根的集合为空或者根的集合中最后一个根与x1不是重根，则认为这是一个新的根
                roots.push_back(x1);
            }
        }else if(y1*y2<0){
            roots.push_back(divide(x1,x2));             //在长度为1的区间内二分查找根
        }
    }

    if(fabs(f(100))<1e-7){                                  //如果f(100)=0，说明100是根
        if(roots.empty()||fabs(roots.back()-100)>1e-4){
            roots.push_back(100);
        }
    }

    for(int i=0;i<(int)roots.size();i++){                        //输出根
        if(i) printf(" ");
        if(fabs(roots[i])<1e-4) {
            roots[i]=0;
        }

        printf("%.2lf",roots[i]);
    }

    return 0;
 }