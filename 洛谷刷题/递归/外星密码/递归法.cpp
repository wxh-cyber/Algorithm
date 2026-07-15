/**
 *  @link https://www.luogu.com.cn/problem/P1928
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 递归求解
 * @return string
 */
string yunqian(){
    int k;                                             //压缩的次数
    char ch;                                           //输入的字符
    string s="",str="";                                //s最终答案，str是被压缩的字符串

    while(cin>>ch){                                    //输入字符
        if(ch=='['){                                   //如果是'['，则后面是压缩的字符串
            cin>>k;                                    //输入压缩的次数
            str=yunqian();                             //递归调用，获取到内层被压缩的字符串的展开形式
            while(k--){
                s+=str;                                //将str重复k次加入s中
            }
        }else if(ch==']'){                             //如果是']'，则说明内层被压缩的字符串已经结束
            return s;                                  //返回s
        }else {
            s+=ch;                                     //否则该ch没有被压缩，直接加入s中
        }
    }

    //此处需要return s，这是为了保证在输入的字符串没有被压缩的字符串的时候，也能够正确返回s
    return s;
}

int main(){
    cout<<yunqian();
    
    return 0;
}