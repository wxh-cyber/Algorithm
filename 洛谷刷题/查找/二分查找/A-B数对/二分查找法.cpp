/**
 *  @link https://www.luogu.com.cn/problem/P1102
 */

 #include <iostream>
 #include <algorithm>
 using namespace std;
 typedef long long ll;

 const int MAXN=2e5+5;

 int n;
 ll c;
 ll nums[MAXN];

 int main(){
    cin>>n>>c;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    sort(nums+1,nums+n+1);

    

    return 0;
 }