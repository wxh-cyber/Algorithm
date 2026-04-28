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
 
     scanf("%s",w);                               //先输入一个单词
     c=getchar();                                 //去除缓冲区中的换行符
     while((c=getchar())!=EOF&&i<MAX_LINE){       //每当输入一个字符，则进入循环
         if(c=='\n') break;                       //如果输入的是换行符，则跳出循环
         s[i++]=c;                                //如果输入的不是换行符，则将字符存入数组中
     }
     s[i]='\0';                                   //将数组的最后一个元素置为'\0'，表示字符串的结束
 
     for(i=0,j=0;s[i]!='\0';i++){                 //外层循环遍历字符串中的每个字符
         // 内层循环遍历单词中的每个字符
         /**
          *    判断条件分析：
          *    i==0||s[i-1]==' '：当i==0或s[i-1]=='  '时，表明i此时正在字符串中一个单词的开头。
          *    j>=0：表明已经至少匹配了单词中的一个字符。
          *    val(w[j])==val(s[i])：判断当前字符是否与单词中的字符匹配。
          *    ++j：如果当前字符与单词中的字符匹配，则将j加1，继续匹配下一个字符。
          */
         if((i==0||s[i-1]==' '||j)&&val(w[j])==val(s[i])&&++j){
             if(w[j]=='\0'&&(s[i+1]=='\0'||s[i+1]==' ')){          //由于在上一轮判断中，已经将j加1了，所以此时i+1而j不变

                 if(first==-1) first=i-j+1;
                 count++;
             }
         }else j=0;
     }
 
     if(count==0) printf("-1\n");
     else printf("%d %d",count,first);
     return 0;
 }