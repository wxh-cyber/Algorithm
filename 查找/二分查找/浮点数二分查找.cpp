#include <iostream>
#include <functional>
using namespace std;

/**
 *  @note
 *    functional:提供了std::function类模板。
 *    std::function 是一个通用的可调用对象包装器，它可以装下任何"能像函数一样调用"的东西，包括：
 *      - 普通函数 / 函数指针
 *      - Lambda 表达式（本例中就是这种）
 *      - 函数对象（重载了 operator() 的类）
 *      - bind 的结果等
 */

/**
 *  @brief search - 浮点数二分查找
 *  @param {double} left - 左侧区间
 *  @param {double} right - 右侧区间
 *  @param {function<bool(double)>} check - 检查函数
 *  @param {double} eps - 要求精度
 *  @return {double} result - 二分查找结果
 *  @note
 *    第三个形参的类型：function<bool(double)> check
 *    表明传入一个函数，这个函数接收一个double类型的形参，返回一个bool类型的结果
 */
double search(double left,double right,function<bool(double)> check,double eps){
    //当区间长度大于精度要求时继续
    while(right-left>eps){
        double mid=left+(right-left)/2;
        if(check(mid)){
            right=mid;                                 //如果mid满足条件，则解在左半区
        }else{
            left=mid;                                  //否则在右半区
        }
    }

    return left;                                       //优先返回左侧近似解
}

int main(){
    // 例：求方程 x^3 = 1000 的近似解，精度要求1e-6
    double left=0.0,right=10.0;                        // 初始区间[0, 10]，显然解在(0,10)内
    auto check=[](double x){
        return x*x*x>=1000;
    };

    double root=search(left,right,check,1e-6);
    cout << "Approximate root: " << root << endl;

    return 0;
}