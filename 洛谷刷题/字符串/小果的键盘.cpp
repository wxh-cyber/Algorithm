/**
 *     @link https://www.luogu.com.cn/problem/P3741
 */
 #include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;

 char a[102];
 int main(){
    cin>>a>>a;
    /**
     *    gets(a);
     *    gets(a);
     *    注意：由于在C++11标准中，gets()已经被正式废除，所以在C++中不建议使用gets()函数。
     */
    /**
     *    在本题背景下，可以使用cin>>a>>a;
     *
     *    假设输入是：
     *    1
     *    VKVVVK
     *
     *    第一个 cin >> a：
     *    cin 的默认行为是：遇到空格、制表符或换行符 \n 就停止读取，并且把这些空白符留在缓冲区里（不吃掉）。
     *    - 它读取了 '1'，遇到 '\n' 停下。
     *    - 此时 a 的内容是 "1"。缓冲区剩下：'\n', 'V', 'K', 'V', 'V', 'V', 'K', '\n'。
     *    第二个 cin >> a：
     *    cin 的另一个默认行为是：在开始读取前，会自动跳过（忽略）前面所有的空白符。
     *    - 它一眼看到缓冲区开头有个换行符 '\n'，直接无视它、跳过它。
     *    - 接着它读取了 'V', 'K'… 直到遇到末尾的 '\n' 停下。
     *    - 新读取的内容直接覆盖了原来的 "1"。
     *    - 此时 a 的内容变成了 "VKVVVK"。
     */
    int ans=0;                            //记录答案
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='V'&&a[i+1]=='K'){
            ans++;
            a[i]='X';                     //将两个字符替换为X，防止重复计算
            a[i+1]='X';
        }
    }
    for(int i=0;i<strlen(a);i++){
        if(a[i]!='X'&&a[i]==a[i+1]){
            ans++;
            break;                        //由于至多只能修改一次，所以找到一个就可以跳出循环了
        } 
    }
    printf("%d",ans);
    return 0;
 }