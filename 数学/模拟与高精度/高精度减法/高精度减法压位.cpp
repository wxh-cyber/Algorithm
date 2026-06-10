#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int BASE=100000000;                //压8位，基数为1e8
const int WIDTH=8;
const int MAXN=300;

struct BigNum {
    int len;
    int d[MAXN];                         //d[1]是最低位（个位），d[len]是最高位

    BigNum():len(1){
        memset(d,0,sizeof(d));
    }

    BigNum(int num):len(0){
        memset(d,0,sizeof(d));
        //对0进行特判
        if(num==0) {
            len=1;
            return;
        }
        while(num>0){
            d[++len]=num%BASE;
            num/=BASE;
        }
    }

    BigNum(string s):len(0){
        memset(d,0,sizeof(d));
        int slen=s.length();
        //从字符串末尾（低位）开始，每次截取8位
        for(int i=slen-1;i>=0;i-=WIDTH){
            int start=max(0,i-WIDTH+1);               //截取起点，防止越界
            int part_len=i-start+1;
            //将截取的8位子串转为整数存入数组
            int num=0;
            for(int j=start;j<start+part_len;j++){
                num=num*10+(s[j]-'0');
            }

            //将特定8位的整数存入数组
            d[++len]=num;
        }
    }
}

/**
 *  @brief 重载<运算符，实现两个BigNum类型的比较
 *  @param a 待比较的数字
 *  @param b 待比较的数字
 *  @return 如果a<b，返回true；否则返回false
 */
bool operator < (const BigNum& a,const BigNum& b){
    if(a.len!=b.len) return a.len<b.len;
    for(int i=a.len;i>=1;i--){
        if(a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
    }

    return false;                           
}

BigNum operator - (const BigNum& a,const BigNum& b){
    BigNum c;
    int borrow=0;                              //借位标志

    for(int i=1;i<=a.len;i++){
        //当前位的差=A的当前位-B的当前位-借位
        int diff=a.d[i]-b.d[i]-borrow;

        if(diff<0){
            //不够减，需要向高位借位
            borrow=1;                          //标记借位，下一轮高位要减1
            diff+=BASE;                        //借1当1亿，加上BASE
            c.d[i]=diff;
        }else{
            //够减，无需借位
            borrow=0;                          //借位清零
            c.d[i]=diff;
        }
    }

    //计算最终有效长度
    c.len=a.len;
    //去除最高位多余的0(例如 100000000 - 99999999 = 1，高位全变0了)
    while(c.len>1&&c.d[len]==0){
        c.len--;
    }

    return c;
}

void print(const BigNum& a){
    printf("%d",a.d[a.len]);                     //最高位直接输出
    for(int i=a.len-1;i>=1;i--){
        printf("%08d",a.d[i]);                   //其余位补足8位前导0
    }
    print("\n");
}

int main(){
    string sa,sb;
    cin>>sa>>sb;                                 //读入两个大数

    BigNum a(sa),b(sb);

    //判断大小，处理负数情况
    if(a<b){
        //A<B，结果是负数
        printf("-");                             //输出负号
        BigNum c=b-a;                            //算出B-A
        print(c);
    }else {
        //A>=B，结果是正数
        BigNum c=a-b;                            //算出A-B
        print(c);
    }

    return 0;
}