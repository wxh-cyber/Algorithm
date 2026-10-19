/**
 *  @link https://www.luogu.com.cn/problem/P1449
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=55;

int i=0;                                               //i表示栈顶指针，初始下标为0
char op;                                               //op暂存每次输入的字符
long long now=0;                                       //now用于累加单个数
long long stk[MAXN];                                   //stk存放所有操作数

int main(){
    while((op=getchar())!='@'){                        //当输入的字符不是'@'时，表示还没有结束
        if(op>='0'&&op<='9'){                          //如果当前输入的是0-9的字符形式，将字符类型转化为整型后累加到now
            now*=10;
            now+=op-'0';
        }else if(op=='.'){                             //当输入的字符是'.'时，表示当前的累加已结束
            stk[++i]=now;                              //将当前数入栈，注意stk的最小下标为1
            now=0;                                     //重置累加数
        }else if(op=='+'){                             //根据栈的定义，对+-*/四种运算进行分别运算
            stk[i-1]+=stk[i];
            stk[i]=0;                                  //运算结果保存在stk[i-1]中，此处对stk[i]=0，相当于出栈
            i--;
        }else if(op=='-'){
            stk[i-1]-=stk[i];
            stk[i]=0;
            i--;
        }else if(op=='*'){
            stk[i-1]*=stk[i];
            stk[i]=0;
            i--;
        }else if(op=='/'){
            stk[i-1]/=stk[i];
            stk[i]=0;
            i--;
        }
    }

    cout<<stk[1];                                      //输出最终结果
    
    return 0;
}