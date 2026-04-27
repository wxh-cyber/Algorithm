/**
 *     @link https://www.luogu.com.cn/problem/P1308
 */
 #include<iostream>
 #include<cstdio>
 #include<string>
 #define MAX_LINE 1000001
 #define val(a) (a<'a'?(a-'A'+'a'):a)                //将大写字母转换为小写字母
 using namespace std;
 
 int main(){
     int i=0,j,count=0,first=-1;
     char c,w[11],s[MAX_LINE];
 
     scanf("%s",w);
     c=getchar();
     while((c=getchar())!=EOF&&i<MAX_LINE){
         if(c=='\n') break;
         s[i++]=c;
     }
     s[i]='\0';
 
     for(i=0,j=0;s[i]!='\0';i++){
         if((i==0||s[i-1]==' '||j)&&val(w[j])==val(s[i])&&++j){
             if(w[j]=='\0'&&(s[i+1]=='\0'||s[i+1]==' ')){
                 if(first==-1) first=i-j+1;
                 count++;
             }
         }else j=0;
     }
 
     if(count==0) printf("-1\n");
     else printf("%d %d",count,first);
     return 0;
 }