#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 【关键变化】乘法通常压4位，基数为 1e4
const int BASE=10000;
const int WIDTH=4;
const MAXN=300;

struct BigNum {
    int len;
    int d[MAXN];                                  //d[1]是最低位，d[len]是最高位

    BigNum():len(1) {
        memset(d,0,sizeof(d));
    }

    BigNum(int num):len(0) {
        memset(d,0,sizeof(d));

        if(num==0) {
            len=1;
            return;
        }

        while(num>0){
            d[++len]=num%BASE;
            num/=BASE;
        }
    }

    BigNum(string s):len(0) {
        memset(d,0,sizeof(d));
        int slen=s.length();

        for(int i=slen-1;i>=0;i-=WIDTH){
            int start=max(0,i-WIDTH+1);
            int part_len=i-start+1;
            int num=0;
            for(int j=start;j<start+part_len;j++){
                num=num*10+(s[j]-'0');
            }

            d[++len]=num;
        }
    }
};

/**
 *  @brief 重载*运算符，实现两个BigNum类型的相乘
 *  @param a 乘数
 *  @param b 乘数
 *  @return 相乘的结果
    @note 高精度 * 高精度 (压4位 + 统一进位优化)
 */
BigNum operator * (const BigNum& a,const BigNum& b){
    BigNum c;
    //乘积的最大长度不超过两者长度之和
    c.len=a.len+b.len;
    
    // 【核心优化1：无进位累加】
    // 因为压4位，最大值 9999*9999 = 99,980,001，累加几次也不会爆 int
    // 所以放心大胆地先往里加，不取模！
    for(int i=1;i<=a.len;i++){
        for(int j=1;j<=b.len;j++){
            c.d[i+j-1]+=a.d[i]*b.d[j]
        }
    }

    // 【核心优化2：统一进位】
    // 把除法和取模操作集中到一次循环里，大幅提升速度
    int carry=0;
    for(int i=1;i<=c.len;i++){
        int sum=c.d[i]+carry;
        c.d[i]=sum%BASE;
        carry=sum/BASE;
    }

    // 处理最后可能残留的进位（虽然上面循环限制了c.len，但进位可能超出）
    while(carry>0) {
        c.d[++c.len]=carry%BASE;
        carry/=BASE;
    }

    // 去除最高位多余的 0 (比如 100 * 10 = 1000，但数组长度可能预留了4位)
    while(c.len>0&&c.d[c.len]==0){
        c.len--;
    }

    return c;
}

/**
 * @brief 输出BigNum类型的数字
 * @param a 待输出的数字
 * @return void
 * @note 注意输出格式
 */
void print(const BigNum& a) {
    printf("%d",a.d[a.len]);
    for(int i=a.len-1;i>=1;i--){
        printf("%04d",a.d[i]);                  //压4位，补4个0
    }
    
    printf("\n");
}

int main(){
    string sa,sb;
    cin>>sa>>sb;

    BigNum a(sa);
    BigNum b(sb);
    BigNum c=a*b;

    print(c);

    return 0;
}