/**
 *  @link https://www.luogu.com.cn/problem/P1012
 */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 using namespace std;

 const int MAXN=25;

 int n;                                                                //字符串总数n

 int main(){
    cin>>n;
    vector<string> nums(n);                                     //定义存放所有字符串的vector
    for(auto& s:nums){
        cin>>s;                                                       //依次输入
    }

    //排序
    sort(nums.begin(),nums.end(),[](const string& a,const string &b){
        return a+b>b+a;
    });

    //输出结果
    for(int i=0;i<n;i++){
        cout<<nums[i];
    }

    return 0;
 }