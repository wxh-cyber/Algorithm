#include <iostream>
#include <cstdio>
using namespace std;

const int BASE=100000000;                   //压8位，基数为1e8
const int WIDTH=8;
const int MAXN=250;                         //数组长度，预留足够空间
/**
 *  思考：为什么高精度压位加法最多只能压到1e8？
 *  
 */

struct BigNum {
    int len;
    int d[MAXN+10];                         //规定：d[1]是最低位（个位），d[len]是最高位

    BigNum():len(1) {                       //初始化时，如果不传参，则默认长度为1，值为0
        memset(d,0,sizeof(d));
    }

    BigNum(int num):len(0) {
        memset(d,0,sizeof(d));
        if(num==0){                         //如果传入参数为0，则长度设定为1，值为0
            len=1;
            return;
        }

        while(num>0){                       //如果传入参数非0，则对其进行加工处理
            d[++len]=num%BASE;              //个位放在d[1]
            num/=BASE;
        }
    }
};

/**
 * @brief 重载+运算符，实现两个BigNum类型的相加
 * @param a 加数
 * @param b 加数
 * @return 相加的结果
 */
BigNum operator + (const BigNum& a,const BigNum& b){
    BigNum c;
    int carry=0;
    //取两者最大长度作为起始点，但循环条件是：只要还有进位，就继续往高位算
    //不需要单独判断a.len和b.len，因为d数组初始化位0，0+0+carry也能正确计算
    int i=1;
    while(i<=a.len||i<=b.len||carry){
        int sum=a.d[i]+b.d[i]+carry;                  //短的数字d[i]自然是0，完美对齐
        c.d[i]=sum%BASE;
        carry=sum/BASE;
        i++;
    }

    c.len=i-1;                                        //循环结束时，i多加了1
    return c;
}

/**
 * @brief 输出BigNum类型的数字
 * @param a 待输出的数字
 * @return void
 */
void print(const BigNum& a){
    //最高位（大索引）直接输出，不需要补前导0
    printf("%d",a.d[a.len]);

    //从次高位向最低位（小索引）输出，必须补足8位前导0
    for(int i=a.len-1;i>=1;i--){
        printf("%08d",a.d[i]);
    }

    printf("\n");
}

int main(){
    int n;                                              //n表示最终数列的下标
    scanf("%d",&n);

    if(n==0) {                                          //对0,1,2的特殊情况进行特判
        puts("0");
        return 0;
    }
    if(n==1||n==2) {
        puts("1");
        return 0;
    }

    BigNum a(1),b(2),c;                                 //规定F（1）=1，F（2）=2
    
    for(int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    
    print(b);                                           //输出结果
    return 0;
}