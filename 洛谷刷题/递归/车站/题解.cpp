/**
 *  @link https://www.luogu.com.cn/problem/P1011
 */

#include <cstdio>
using namespace std;

int a,n,m,x;                                       //a表示第一站上车人数，n车站数，m最后一站下车人数，x指定站点的序号

int main(){
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x==n) printf("0");
    else if(n<=5){
        if(n==2||n==3) printf("%d",a);
        else if(n==4){
            if(x==1||x==2) printf("%d",a);
            else printf("%d",2*a);
        }else {
            if(x==1||x==2) printf("%d",a);
            else if(x==3) printf("%d",2*a);
            else printf("%d",m);
        }
    }else {
        
    }

    return 0;
}