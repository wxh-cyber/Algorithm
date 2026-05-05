/**
 *    @link https://www.luogu.com.cn/problem/P5461
 */
 #include<iostream>
 using namespace std;

 int solve(int n,int x,int y){
    if(n==0) return 1;

    int half=1<<(n-1);

    //当前矩阵分成4块，分别进行讨论递归
    if(x<half && y<half) return 0;
    if(x<half&&y>=half) return solve(n-1,x,y-half);
    if(x>=half&&y<half) return solve(n-1,x-half,y);
    return solve(n-1,x-half,y-half);

 }

 int main(){
    int n;
    cin>>n;

    int len=1<<n;

    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout<<solve(n,i,j);
            if(j!=len-1) cout<<" ";
        }
        cout<<'\n';
    }

    return 0;
 }