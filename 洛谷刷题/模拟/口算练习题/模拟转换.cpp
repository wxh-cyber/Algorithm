/**
*    @name 口算练习题
*    @link https://www.luogu.com.cn/problem/P1957
*/
#include <iostream>
#include<cstring>
using namespace std;

//比较两数大小
int judge(int b,int c){
    if(c>b) {
        return 0;
    }else {
        return 1;
    }
}

//将字符串转换为数字
int transform(string a){
    int cnt=0,times=1;
    if(a=="0") return cnt;           //如果字符串为0，则直接输出0
    for(int j=a.size()-1;j>=0;j--){
        cnt+=(a[j]-48)*times;
        times*=10;
    }
    return cnt;
}

//计算a的位数
int count(int a){
    int cnt=0;
    //对a为0的情况进行特判
    if(a==0) return 1;
    while(a){
        a/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str,kind;
    int a,b,c,d,cnt=0;              
    int n;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str>>a;
        if(str!="a"&&str!="b"&&str!="c"){           //如果输入的第一个字符不是运算符，则说明输入的是数字
            if(kind=="a"){                          //如果上一个运算符是+，则计算a+b
                b=transform(str)+a;    
                cout<<transform(str)<<"+"<<a<<"="<<b<<endl;
                //计算字符串长度，2是+和=的长度
                cout<<cnt+2+count(transform(str))+count(a)+count(b)<<endl;
            }else if(kind=="b"){                   //如果上一个运算符是-，则计算a-b
                //减法情况下，要判断大小，以输出不同的结果
                if(judge(transform(str),a)==0){
                    b=a-transform(str);            //先计算两数之差的绝对值
                    cout<<transform(str)<<"-"<<a<<"=-"<<b<<endl;
                    //计算字符串长度，3是-和=以及负号的长度
                    cout<<cnt+3+count(transform(str))+count(a)+count(b)<<endl;
                }else {
                    b=transform(str)-a;
                    cout<<transform(str)<<"-"<<a<<"="<<b<<endl;
                    //计算字符串长度，2是-和=的长度
                    cout<<cnt+2+count(transform(str))+count(a)+count(b)<<endl;
                }
            }else {            //如果以上两种情况都不是，则为乘法
                b=transform(str)*a;
                cout<<transform(str)<<"*"<<a<<"="<<b<<endl;
                //计算字符串长度，2是*和=的长度
                cout<<cnt+2+count(transform(str))+count(a)+count(b)<<endl;
            }
        }else {                        //如果str中现在是运算符
            kind=str;
            cin>>d;
            if(str=="a"){
                c=a+d;
                cout<<a<<"+"<<d<<"="<<c<<endl;
                cout<<cnt+2+count(a)+count(d)+count(c)<<endl;
            }else if(str=="b"){
                //仍然要对大小进行判断
                if(judge(a,d)==0){
                    c=d-a;
                    cout<<a<<"-"<<d<<"=-"<<c<<endl;
                    cout<<cnt+3+count(a)+count(d)+count(c)<<endl;
                }else {
                    c=a-d;
                    cout<<a<<"-"<<d<<"="<<c<<endl;
                    cout<<cnt+2+count(a)+count(d)+count(c)<<endl;
                }
            }else {
                c=a*d;
                cout<<a<<"*"<<d<<"="<<c<<endl;
                cout<<cnt+2+count(a)+count(d)+count(c)<<endl;
            }
        }
    }

    return 0;
}