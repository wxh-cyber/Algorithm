/**
 *  @link https://www.luogu.com.cn/problem/P1098
 */
 #include <iostream>
 #include <algorithm>
 #include <cctype>
 #include <string>

 using namespace std;

 /**
  *  algorithm：包含了reverse()
  *  cctype:包含了toupper()、tolower()
  */
 int p1,p2,p3;
 string a,b="",c;
 char x,y;                                         //x和y记录'-'左右两侧的字符
 char ch;
 
 /**
  *  @brief 判断是否为小写字母
  *  @param x 待判断的字符
  *  @return 是小写字母返回true，否则返回false
  */
 bool isLower(char x){
    return x>='a'&&x<='z';
 }

 /**
  *  @brief 判断是否为数字
  *  @param x 待判断的字符
  *  @return 是数字返回true，否则返回false
  */
 bool isDigit(char x){
    return x>='0'&&x<='9';
 }
 
 /**
  *  @brief 判断是否为相同类型的字符
  *  @param x 待判断的字符
  *  @param y 待判断的字符
  *  @return 是相同类型的字符返回true，否则返回false
  */
 bool isSame(char x,char y){
    if(isLower(x)&&isLower(y)) return true;
    if(isDigit(x)&&isDigit(y)) return true;
    return false;
 }

 int main(){
    cin>>p1>>p2>>p3;
    cin>>a;

    //获取字符串长度
    int len=a.size();

    for(int i=0;i<len;i++){
        //用ch记录当前字符
        ch=a[i];
        if(ch!='-'){                                   //如果当前字符不是'-'，则直接加入b
            b+=ch;
            continue;
        }
        
        //判断下标是否越界
        if(i==0||i==len-1) {                           //如果'-'位于字符串开头或结尾，则直接加入，不进行进一步处理
            b+=ch;
            continue;
        }

        x=a[i-1];
        y=a[i+1];
        if(!isSame(x,y)){
            /**
             *  如果x和y不是相同类型的字符，则直接加入，不进行进一步处理
             *  具体来说，有以下几种情况：
             *      1.x和y其中一个是小写字母，另一个是数字，如a-1
             *      2.x和y其中一个是小写字母，另一个是大小写字母和数字以外的其他形式，如a--
             *      3.x和y其中一个是数字，另一个是大小写字母和数字以外的其他形式，如1--
             *
             *   解决方式：在isSame中，只有当x和y都是小写字母或数字时，才返回true，否则返回false
             */
            b+='-';
            continue;
        }

        if(x>=y) {
            //当x和y相同，或x比y大时，同样不进行进一步处理
            b+='-';
            continue;
        }

        c="";
        for(char j=x+1;j<y;j++){
            for(int k=0;k<p2;k++){
                //如果中间替代字符不是'*'，则进行分类讨论
                if(p1!=3){
                    //如果两侧为数字
                    if(x>='0'&&x<='9'){                        //由于前面已经通过isSame判断了x和y的类型，所以这里直接通过x进行分类谈论     
                        c+=j;
                    }else if(p1==1) {                          //接下来只有可能是字母，再对大小写进行分类讨论
                        c+=tolower(j);
                    }else {
                        c+=toupper(j);
                    }
               }else {
                    //如果中间替代字符是'*'，则直接加入
                    c+='*';
               }
            }
        }
        //如果需要翻转字符串
        if(p3==2) reverse(c.begin(),c.end());
        b+=c;
    }
    cout<<b<<endl;

    return 0;
 }