/**
 *  @link https://www.luogu.com.cn/problem/P1786
 */
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cctype>
 #include <string>
 #include <map>
 #define f(i,a,b) for(int i=a;i<=b;i++)
 //注意：由于后面采用了inline ll rr()，所以typedef需要在该函数之前定义
 typedef long long ll;
  /**
  *  @brief rr
  *  @return 输入的数字
  *  @note 用于读入数字
  */
  inline ll rr(){
    ll x=0,f=1;
    char c=getchar();

    if(c=='-') {
        f=-1;
        c=getchar();
    }

    while(isdigit(c)) {
        x=x*10+c-'0';
        c=getchar();
    }

    return x*f;
}
 #define d rr()
 using namespace std;

 ll n;                                        //n存储帮内人数
 map<string,ll> top;                          //用于将职位名称转换为职位编号
 map<ll,string> bottom;                       //用于将职位编号转换为职位名称

 struct person {
    string name;                              //昵称
    ll contri;                                //帮贡
    int pos,level,num;                        //职位、等级、序号
 } members[115];

 /**
  *   @brief cmp1
  *   @param {person} a - 成员1
  *   @param {person} b - 成员2
  *   @return 成员1是否比成员2更优秀
  *   @note 用于将成员按照贡献值从大到小排序，如果贡献值相同，则按照输入序号从小到大排序
  */
 bool cmp1(person a,person b){
     if(a.contri==b.contri) return a.num<b.num;
     return a.contri>b.contri;
 }

 /**
  *  @brief cmp2
  */
 bool cmp2(person a,person b){
     if(a.pos!=b.pos) return a.pos>b.pos;
     else {
        if(a.level!=b.level) return a.level>b.level;
        else return a.num<b.num;
     }
 }

 int main(){
    n=d;

    //给每个职位对应的编号
    top["BangZhu"]=10;
    top["FuBangZhu"]=9;
    top["HuFa"]=8;
    top["ZhangLao"]=7;
    top["TangZhu"]=6;
    top["JingYing"]=5;
    top["BangZhong"]=4;

    //给每个编号对应的职位
    bottom[10]="BangZhu";
    bottom[9]="FuBangZhu";
    bottom[8]="HuFa";
    bottom[7]="ZhangLao";
    bottom[6]="TangZhu";
    bottom[5]="JingYing";
    bottom[4]="BangZhong";

    f(i,1,n){
        cin>>members[i].name;
        members[i].num=i;
        string s;
        cin>>s;
        members[i].pos=top[s];
        scanf("%lld %d",&members[i].contri,&members[i].level);
    }

    ll m=1;
    sort(members+1,members+n+1,cmp1);
    f(i,1,n){
        //如果是帮主或副帮主，则职位不变
        if(members[i].pos>8) continue;

        /**
         *  为什么这里的判断条件是m<=2？
         *      这是因为在每次循环的开始，都首先判断职位是不是帮主或副帮主，如果是，则直接跳过本次循环。
         *      因此m的值本质上记录的是非帮主或副帮主的人数。
         */
        if(m<=2) members[i].pos=8;
        else if(m<=6) members[i].pos=7;
        else if(m<=13) members[i].pos=6;
        else if(m<=38) members[i].pos=5;
        else members[i].pos=4;

        m++;
    }

    sort(members+1,members+n+1,cmp2);
    f(i,1,n){
        cout<<members[i].name<<" "<<bottom[members[i].pos]<<" "<<members[i].level<<endl;
    }
     
    return 0;
 }