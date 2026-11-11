/**
 *  @link https://www.luogu.com.cn/problem/P1019
 */

 #include <iostream>
 #include <string>
 #include <algorithm>
 using namespace std;

 const int MAXN=25;

 int n;
 char ch;
 int ans=0;
 int vis[MAXN]={0};
 string s[MAXN];

 void dfs(const string &tmp){
     ans=max(ans,int(tmp.size()));
     for(int i=0;i<n;i++){
         if(vis[i]>=2) continue;
         for(int j=1;j<=min(tmp.size(),s[i].size());j++){
            if(tmp.substr(tmp.size()-j)==s[i].substr(0,j)){
               vis[i]++;
               dfs(tmp+s[i].substr(j));
               vis[i]--;
            }
         }
     }
 }

 int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>ch;

    for(int i=0;i<n;i++){
      if(s[i][0]==ch){
         vis[i]++;
         dfs(s[i]);
         vis[i]--;
      }
    }

    cout<<ans<<endl;

    return 0;
 }