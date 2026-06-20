/**
 *  @link https://www.luogu.com.cn/problem/P1116
 */

 #include<iostream>
using namespace std;

const int MAXN=1005;

/**
 *  由于题目仅要求求出逆序对的数量，因此可以不必实际写出排序算法。
 *  本题解只是借用了冒泡排序的思想。
 */
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