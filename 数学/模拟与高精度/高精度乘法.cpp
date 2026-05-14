/**
 *    @link https://www.luogu.com.cn/problem/P1303
 */
 #include<iostream>
 #include<cstring>
 using namespace std;

 char a1[10001],b1[10001];
 int a[10001],b[10001],c[10001];
 int lena,lenb,lenc;
 int main(){
    cin>>a1>>b1;                        //以字符串的形式输入两个大整数

    lena=strlen(a1);                    //求出两个大整数的位数
    lenb=strlen(b1);
    
    for(int i=1;i<=lena;i++) 
        a[i]=a1[lena-i]-'0';            //将两个大整数存入数组中
    for(int i=1;i<=lenb;i++)
        b[i]=b1[lenb-i]-'0';
    
    for(int i=1;i<=lenb;i++){
        for(int j=1;j<=lena;j++){
            c[i+j-1]+=a[j]*b[i];        //模拟竖式乘法
        }
    }

    for(int i=1;i<lena+lenb;i++){
        if(c[i]>9){                     //处理进位
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }

    lenc=lena+lenb;
    while(c[lenc]==0&&lenc>1) lenc--;   //去掉前导0

    for(int i=lenc;i>=1;i--)
        cout<<c[i];                    //输出结果

    return 0;
 }