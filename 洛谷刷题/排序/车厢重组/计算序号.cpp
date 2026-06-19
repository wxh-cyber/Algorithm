/**
 *  @link https://www.luogu.com.cn/problem/P1116
 */

 #include<iostream>
using namespace std;

const int MAXN=1005;

int n,sum=0;
int num[MAXN];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[j]>num[i]){
                sum++;
            }
        }
    }

    cout<<sum;
    
    return 0;
}