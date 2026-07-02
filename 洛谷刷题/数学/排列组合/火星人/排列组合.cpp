/**
 *  @link https://www.luogu.com.cn/problem/P1088
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x;
int n,m;
vector<int> num;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }

    int j=0;
    //注意：在对vector进行排序时，需要使用begin()和end()表示地址
    while(next_permutation(num.begin(),num.end())){
        j++;
        if(j==m) {
            break;
        }
    }

    for(int a:num){
        cout<<a<<" ";
    }
    
    return 0;
}