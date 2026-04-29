/**
 *    @link https://www.luogu.com.cn/problem/P1765
 */
 #include<iostream>
 #include<cstdio>
 using namespace std;

 int sum,i,n;
 //x用于存储当前输入的字符，a用于存储按键次数发生变化的断点位置
 //在该字母表中，从0开始计数，处于偶数位置的最多按3次，处于奇数位置的最多按4次
 char x,a[]={'a','p','t','w','z'+1};
 int main(){
    while(scanf("%c",&x)!=EOF){             
        if(x>='a'){
            for(i=0;i<4&&x>=a[i+1];i++){
                /**
                 * 逻辑分析：
                 * x-a[i]表示当前处于字母表中的第几个字母
                 * i&1表示i的奇偶性，i为偶数时，i&1=0，i为奇数时，i&1=1
                 * +1表示从1开始计数
                 */
                sum+=(x-a[i])%((i&1)+3)+1;
            }
        }else if(x==" "){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
 }