/**
 *    @link https://www.luogu.com.cn/problem/P1765
 */
 #include<iostream>
 #include<string>
 #include<cstdio>
 using namespace std;

 int ans=0;
 string a;
 int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};        //26个字母打表需要按几次 
 int main(){
    getline(cin,a);
    for(int i=0;i<a.length();i++){
        if(a[i]>='a'&&a[i]<='z') ans+=num[a[i]-'a'];
        if(a[i]==' ') ans++;                      //不能写else因为也有'\n'和'\r'，这就是这个题的坑点
    }
    printf("%d",ans);
    return 0; 
 }