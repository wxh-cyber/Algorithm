/**
 *    @link https://www.luogu.com.cn/problem/P5736
 */

#include<stdio.h>

int main()
{
    int n;
    long a,j;
    scanf("%d",&n);                     //输入数据总数
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&a);
        if(a<2) continue;
        for(j=2;j*j<=a;j++)
        {
            if(a%j==0) break;
        }
        if(j*j>a) {
            printf("%ld",a);
            if(i!=n-1) printf(" ");
        }
    }
    return 0;
}