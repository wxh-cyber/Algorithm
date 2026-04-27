/**
 *     @link https://www.luogu.com.cn/problem/P1308
 */
 #include <iostream>
 #include<string>
 #include<cstdio>
using namespace std;

string dan,ci,s;
int cur=-1,ans;
int main(){
    cin>>ci;                  //输入单词
    for(int i=0;i<ci.size();i++) ci[i]=tolower(ci[i]);
    getchar();                //去除缓冲区中的换行符
    getline(cin,s);           //输入字符串
    s+=' ';                   //确保最后一个单词也会被处理
    for(int i=0;i<s.size();i++) s[i]=tolower(s[i]);
    for(int i=0;i<s.size();i++) {
        if(s[i]==' '){                    //如果是空格，说明字符串中的一个单词已经结束
            if(dan==ci) {                 //如果单词相等，说明找到了一个单词
                ans++;
                if(cur==-1) cur=i-ci.size();
            }
            dan="";
        }else dan+=s[i];                  //如果不是空格，说明单词还没有结束，继续添加字符
    }
    if(ans==0) printf("-1");
    else printf("%d %d",ans,cur);

    return 0;
}