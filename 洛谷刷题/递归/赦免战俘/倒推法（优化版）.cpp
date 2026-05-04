/**
 *    @link https://www.luogu.com.cn/problem/P5461
 */
 #include<iostream>
 using namespace std;

 int calc(int x,int y){
     while(x>0||y>0){
         if(x%2==0&&y%2==0) return 0;
         x/=2;
         y/=2;
     }
     return 1;
 }

 int main(){
    int n;
    cin>>n;
    
    int len=1<<n;

    for(int i=len-1;i>=0;i--){
        for(int j=len-1;j>=0;j--){
            cout<<calc(i,j);
            if(j) cout<<" ";
        }
        cout<<'\n';
    }

    return 0;
 }