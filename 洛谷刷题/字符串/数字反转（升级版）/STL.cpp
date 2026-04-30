/**
 *    @link https://www.luogu.com.cn/problem/P1553
 */
 #include<iostream>
 #include<string>
 #include<algorithm>
 using namespace std;

 // 反转字符串
string reverse(string s){
    int zeroCount=0;
    reverse(s.begin(),s.end());          //反转
    for(auto i:s){
        if(i==48) zeroCount++;           //统计翻转后，前导0的数量
        else break;
    }
    s.erase(s.begin(),s.begin()+zeroCount);         //释放前导0占据的空间
    return (s!=""?s:"0");                          //对于0进行特判
}

//去除后导0
string deleteTail(string s){
    int zeroCount=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==48) zeroCount++;
        else break;
    }
    s.erase(s.end()-zeroCount,s.end());
    return (s!=""?s:"0");
}

 int main(){
    string s;
    cin>>s;
    if(s.back()=='%'){
        cout<<reverse(s.substr(0,s.size()-1))<<"%"<<endl;
        return 0;
    }
    for(auto i:s){
        string left,right;
        if(i=='/'){                        //如果该字符串为分数
            left=s.substr(0,s.find("/"));
            right=s.substr(s.find("/")+1);
            cout<<reverse(left)<<"/"<<reverse(right)<<endl;
            return 0;
        }
        if(i=='.'){
            left=s.substr(0,s.find('.'));
            right=s.substr(s.find('.')+1);
            cout<<reverse(left)<<"."<<deleteTail(reverse(right))<<endl;
            return 0;
        }
    }
    //最后剩下为整数的情况
    cout<<reverse(s)<<endl;
    return 0;
 }