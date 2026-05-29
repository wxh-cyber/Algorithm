/**
 *  @link https://www.luogu.com.cn/problem/P1786
 */
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <string>
 using namespace std;

 int n;                                           //n存储帮内人数
 struct node {
     string name,prepos,pos;                      //昵称、过去职位、现在职位
     long long contri;                            //帮贡
     int level,num;                               //等级、输入序号
 } members[115];

 /**
  *  @brief change
  *  @param {string} a - 职位名称
  *  @return 职位编号
  *  @note 用于将职位名称转换为职位编号
  */
 int change(string a) {
    if(a=="BangZhu") return 0;
    if(a=="FuBangZhu") return 1;
    if(a=="HuFa") return 2;
    if(a=="ZhangLao") return 3;
    if(a=="TangZhu") return 4;
    if(a=="JingYing") return 5;
    if(a=="BangZhong") return 6;
 }

 /**
  *  @brief cmp1
  *  @param {members} x - 成员1
  *  @param {members} y - 成员2
  *  @return 成员1是否比成员2更优秀
  *  @note 用于将成员按照贡献值从大到小排序，如果贡献值相同，则按照输入序号从小到大排序
  */
 int cmp1(members x,members y){
     if(x.contri==y.contri) return x.num<y.num;
     return x.contri>y.contri;
 }

 /**
  *  @brief cmp2
  *  @param {members} x - 成员1
  *  @param {members} y - 成员2
  *  @return 成员1是否比成员2更优秀
  *  @note 用于将成员按照职位等级从高到低排序，如果职位等级相同，则按照输入序号从小到大排序
  */
 int cmp2(members x,members y){
     if(change(x.pos)==change(y.pos)){
         if(x.level==y.level) return x.num<y.num;
         return x.level>y.level;
     }

     return change(x.pos)<change(y.pos);
 }

 int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>members[i].name>>members[i].prepos>>members[i].contri>>members[i].level;
        members[i].num=i;
    }

    sort(members+4,members+n+1,cmp1);

    for(int i=1;i<=n;i++){
        if(i==1) members[i].pos="BangZhu";
        else if(i==2||i==3) members[i].pos="FuBangZhu";
        else if(i==4||i==5) members[i].pos="HuFa";
        else if(i>=6&&i<=9) members[i].pos="ZhangLao";
        else if(i>=10&&i<=16) members[i].pos="TangZhu";
        else if(i>=17&&i<=41) members[i].pos="JingYing";
        else members[i].pos="BangZhong";
    }
   
    //职位相同的情况下，还要比较其他属性，因此第二轮排序包括了帮主和副帮主
    sort(members+1,members+n+1,cmp2);
    for(int i=1;i<=n;i++){
        cout<<members[i].name<<" "<<members[i].pos<<" "<<members[i].level<<endl; 
    }

    return 0;
 }