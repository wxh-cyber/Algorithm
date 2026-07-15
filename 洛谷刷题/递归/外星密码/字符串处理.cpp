/**
 *  @link https://www.luogu.com.cn/problem/P1928
 */

 #include <iostream>
 #include <string>
 #include <cctype>
 #include <algorithm>
 using namespace std;

 /**
  *  @note
  *    string:存放string类型，以及replace函数.
  *    cctype:存放isalpha函数和isdigit函数.
  *    algorithm:存放reverse函数.
  */

 string str;                                                   // 输入的字符串

 /**
  *  @brief rep
  *  @param {string} s - 需要处理的字符串.
  *  @return {string} - 处理后的字符串.
  */
 string rep(string s){
    int t=0;                                              //t用来存储最内层字符串总共重复的次数

    for(int i=0;s[i];i++){                                //对于最内层的字符串，数字都在整个字符串左侧，因此从左往右进行处理
        if(isdigit(s[i])){                              //如果当前字符是数字
            //注意：由于+的优先级高于^，因此此处的s[i]^48需要将外层套上括号，否则会出现错误。
            t=(t<<3)+(t<<1)+(s[i]^48);                    //将先前的t*10再加上当前数字
        }else break;                                      //否则跳出循环
    }

    string x="",y="";                                     //x用来存储最内层字符串，y用来存储处理后的累加字符串
    for(int i=s.size()-1;i>=0;i--){                       //对于最内层字符串，字母都在整个字符串右侧，因此从右往左进行处理
        if(isalpha(s[i])){                             //如果当前字符是字母
            x+=s[i];                                      //将当前字符加入x中
        }else break;                                      //否则跳出循环
    }

    reverse(x.begin(),x.end());               //将x翻转，得到最内层字符串的正确顺序
    while(t--){
        y+=x;                                             //将x重复t次加入y中
    }

    return y;                                             //返回处理后的累加字符串
 }

 int main(){
    cin>>str;                                             //输入字符串

    /**
     *  @note
     *  此处循环的意义在于，对于多重压缩，能够递归地处理压缩的字符串，直到没有压缩的字符串为止。
     *
     *  对于输入的str字符串，还存在以下的特殊情况：
     *      1.str字符串中不存在压缩的字符串：
     *        在确定left下标的时候，left的值为-1，此时循环结束。
     *        从而直接跳出while循环，直接输出str字符串。
     *      2.str字符串中，对于外层压缩字符串，从左到右存在多个压缩字符串。
     *        在进行处理的时候，会优先处理最右侧的压缩的字符串，具体来说，也是从最内层到最外层递归处理。
     *        其中一个压缩的字符串处理完毕之后，再处理在其左侧的压缩的字符串。
     *
     *  @note 
     *    根据题目要求，压缩字符串形式为[DX]的形式，其中X为数字，D为字母。
     *    故不会出现类似于a[b]c这样的形式。
     */
    while(true){
        int left=-1,right=-1;                                   //left和right分别用来存储最内层字符串的左右边界，即[]
        /**
         *  @note
         *    从右往左遍历，对于单个的多重压缩字符串，可以获取到最内层的'['字符
         *    对于多个多重压缩字符串，可以获取到最右侧的多重压缩字符串的最内侧的'['字符。
         */
        for(int i=str.size()-1;i>=0;i--){                       
            if(str[i]=='['){
                left=i;
                break;
            }
        }

        //若果left==-1，说明不存在压缩的字符串，直接输出str字符串
        if(left==-1) break; 

        for(int i=left;str[i];i++){                             //同理从左往右遍历，可以获取到最内层的']'字符
            if(str[i]==']'){
                right=i;
                break;
            }
        }
        //注意：由于前面已经对不存在压缩的字符串进行了特判，故此处不再需要对right进行特判

        string ns="";                                           //ns用来存储最内层的字符串，不包括括号

        for(int i=left+1;i<right;i++){
            ns+=str[i];
        }

        /**
         *  @note
         *    string.replace(start,len,str)
         *    start:起始位置
         *    len:替换的长度
         *    str:替换的字符串
         *   
         *  @note 此处即是将最内层字符串解压缩
         */
        str=str.replace(left,right-left+1,rep(ns));

    }

    //输出str字符串
    cout<<str;

    return 0;
 }