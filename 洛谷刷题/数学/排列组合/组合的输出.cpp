/**
 *  @link https://www.luogu.com.cn/problem/P1157
 */

 #include <iostream>
 #include <iomanip>
 using namespace std;

 const int MAXN=30;

 int n,r;
 int num[MAXN]={0};
 
 void dfs(int k){
     // 当k>r时，说明已经找到了r个数的组合
     if(k>r){
        for(int i=1;i<=r;i++){
            cout<<setw(3)<<num[i];
        }
        cout<<endl;
        return;
     }   

     for(int i=num[k-1]+1;i<=n-(r-k);i++){
        num[k]=i;
        dfs(k+1);                            //直接进行下一次调用
     }
 }

 int main(){
    cin>>n>>r;
    dfs(1);

    return 0;
 }