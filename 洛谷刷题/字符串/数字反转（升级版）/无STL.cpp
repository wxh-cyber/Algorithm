/**
 *    @link https://www.luogu.com.cn/problem/P1553
 */
 #include<iostream>
 #include<string>
 using namespace std;

 int main(){
    string s;
    char p=0;
    int cnt=0;

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') cnt++;             //记录第一个数长度
        else {                                      //遇到符号记录，跳出
            p=s[i];                                 //记录符号
            break;
        }
    }

    int x=cnt;                                      //记录符号的下标
    cnt--;                                          //将cnt前移到第一个数的最后一位
    while(s[cnt]=='0'&&cnt>0) cnt--;                //当前字符如果为0，且不是第一个数的最后一位，cnt前移
    for(int i=cnt;i>=0;i--){
        cout<<s[i];
    }

    if(p==0) return 0;                              //无符号，返回0
    else if(p=='%') {                               //如果是百分号，直接输出百分号，返回0
        cout<<p;
        return 0;
    }
    else cout<<p;                                   //否则输出符号，再进行其他处理
    int m=s.size()-1;
    while(s[x+1]=='0'&&x<m-1) x++;                  //将x后移，直到x后面一个数不是0
    while(s[m]=='0'&&m>x+1) m--;                    //将m前移，直到m对应的数不是0
    for(int i=m;i>x;i--)
        cout<<s[i];                                 //输出第二个数
    return 0;
 }