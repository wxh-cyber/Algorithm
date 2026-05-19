/**
 *    @link https://www.luogu.com.cn/problem/P1009
 */
 #include<iostream>
 #include<string>
 #define MAXN 55
 typedef long long ll;
 using namespace std;

 ll n;
 string frac[MAXN];               //存储阶乘计算过后再相加的结果
 bool visit[MAXN];                //是否访问过的数组

 /**
  *  @brief 高精度加法
  *  @param a 加数
  *  @param b 被加数
  *  @return ret 相加后的结果
  */
/**
  *  思考：字符串版本的高精度加法和数组版本的高精度加法有什么区别？
  *  1.排版方式：
  *      字符串版本：低位下标在后，高位下标在前
  *      数组版本：低位下标在前，高位下标在后
  *  2.初始化：
  *      字符串版本：先以两数中长度比较长的作为长度，然后再将较短的数前面补0
  *      数组版本：两数均从后往前遍历，以数组中最低位作为下标0
  *  3.进位处理：
  *      字符串版本：从后往前遍历字符串，对每一位进行详细处理时，需要先将当前位的值加上上一位的进位，然后再进行进位更新
  *      数组版本：从前往后遍历数组，对每一位进行详细处理时，需要先将当前位的值加上上一位的进位，然后再进行进位更新
  *  
  *  字符串版本和数组版本之所以处理方式不同，是因为在对待高位进位时，字符串版本可以通过字符串拼接的形式，实现整体的后移。
  *  而数组版本如果采用字符串版本的方式，将高位排在前，则会面临高位进位时，其余位需要整体后移的困境。因此两者排版方式存在差异。
  */
  
 string add(string a,string b){
     string ret;                                  //返回值
     string zeros;                                //前导零
     ll lenga=a.length(),lengb=b.length();        //分别记录以字符串形式存在的两个数的长度

     if(lenga>lengb) {                            //如果a的长度大于b的长度
         for(ll i=1;i<=lenga-lengb;i++)
             zeros+='0';
        b=zeros+b;
     }else if(lenga<lengb) {                      //如果b的长度大于a的长度
         for(ll i=1;i<=lengb-lenga;i++)
             zeros+='0';
        a=zeros+a;
     }

     bool flag=false;                             //是否进位的标志
     for(ll i=max(lenga,lengb)-1;i>=0;i--){
        int x=(a[i]-'0')+(b[i]-'0');
        if(flag) {
            flag=false;
            //对于加法而言，进位最多只能是1
            x++;
        }
        //注意：先判断上一位的进位，再判断这一位的进位
        if(x>=10) {
            //如果得到的当前位的值大于等于10那么需要进位，打上进位标记，再将当前位减去10
            flag=true;
            x-=10;
        }
        char c=x+'0';                             //将当前位的值转换为字符型
        ret=c+ret;                                //将当前位的值加到返回值的前面
     }
     if(flag) ret="1"+ret;                        //如果最高位有进位，那么在最高位前加上1
     return ret;
 }

 /**
  *  @brief 半高精度乘法
  *  @param str 被乘数
  *  @param m 乘数
  *  @return 相乘后的结果
  */

 string mul(string str,ll m){
     string ret;                                 //返回值
     ll lengstr=str.length();                    //高精度数的长度
     if(m<10) {                                  //如果低精度数<10，那么一重循环即可完成计算
         ll x=0;                                 //当前位的值
         ll flag=0;                              //进位标志，乘法可能进位更多
         for(ll i=lengstr-1;i>=0;i--){
            x=(str[i]-'0')*m;
            //先加上上一位的进位，再更新当前的数位和进位
            x+=flag;
            flag=x/10;
            x%=10;

            char c=x+'0';                         //将当前位的值转换为字符型
            ret=c+ret;                            //将当前位的值加到返回值的前面
         }

         return ret;                              //返回
     }
     else if(m==10) return str+'0';               //如果正好是10，直接在后面补0
     else {
        ll u=m/10,v=m%10;                           //将高精度数拆分为两部分
        return add(mul(mul(str,u),10),mul(str,v));  //计算最终结果 
     }
 }

 /**
  *  @brief 记忆化搜索
  *  @param x 阶乘的数
  *  @return 阶乘的结果
  */
 string memory(ll x){
     if(visit[x]) return frac[x];                   //如果已经有值，返回上次保存的那个值
     if(x==1) return "1";                           //1！=1
     if(x==2) return "3";                           //1！+2！=3

     string ret="1";                                //返回值
     visit[x]=true;                                 //先打上标记，下次访问可以直接用这个值
     for(int i=1;i<=x;i++){
        //计算阶乘
        ret=mul(ret,i);
     }
     ret=add(ret,memory(x-1));                     //ret得到的x的阶乘需要与x-1得到的结果相加
     frac[x]=ret;                                  //返回值保存
     return ret;                                   //返回最终结果
 }

 int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin>>n;
    cout<<memory(n)<<endl;                         //输出结果
    return 0;
 }