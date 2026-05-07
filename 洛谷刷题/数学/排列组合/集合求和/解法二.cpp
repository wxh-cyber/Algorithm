/**
 *    @link https://www.luogu.com.cn/problem/P2415
 */
 #include<iostream>
 using namespace std;

 int x,t;
 int main(){
    int n;
    while(cin>>n) x+=n,t++;
    cout<<x*(long long)pow(2,t-1);

    return 0;
 }