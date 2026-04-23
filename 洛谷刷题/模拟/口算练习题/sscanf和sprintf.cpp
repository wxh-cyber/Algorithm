/**
*    @name 口算练习题
*    @link https://www.luogu.com.cn/problem/P1957
*/
#include<iostream>            //cin & cout用iostream
#include<cstring>             //memset & strlen用cstring
#include<cstdio>              //sscanf & sprintf用cstdio
using namespace std;

int main(){
    char a;                   //a用于存储运算符
    int n,c,d;                //n存储题目数量，c、d为两个数字
    char s[100],b[10];        //s存储最终的字符串，b为临时变量

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;               //输入一串字符，有可能是运算符，也有可能是数字
        if(b[0]>='a'&&b[0]<='z'){
            a=b[0];           //如果是运算符，就存入a，然后输入数字
            cin>>c>>d;
        }else {
            sscanf(b,"%d",&c);          //如果是数字，就转换b为int存储到第一个数字
            cin>>d;
        }

        memset(s,0,sizeof(s));          //清空原有的字符串，防止长度判断错误

        if(a=='a'){        //用sprintf将数字转换为字符串
            sprintf(s,"%d+%d=%d",c,d,c+d);  
        }else if(a=='b'){
            sprintf(s,"%d-%d=%d",c,d,c-d);
        }else if(a=='c'){
            sprintf(s,"%d*%d=%d",c,d,c*d)
        }
 
        cout<<s<<endl<<strlen(s)<<endl;         //输出字符串和字符串长度
    }

    return 0;
}