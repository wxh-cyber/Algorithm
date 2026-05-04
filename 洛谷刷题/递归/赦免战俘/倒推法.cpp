/**
 *    @link https://www.luogu.com.cn/problem/P5461
 */
 #include<iostream>
using namespace std;

int a[1200][1200];
int main(){
    int n,s=1;
    cin>>n;
    a[0][0]=1;

    /**
     *  思路：
     *  本解法的思路是从相反的角度出发，从小到大，可以认为大的正方形是由小的正方形组成的，且特定区域存在相同的小正方形。
     *  因此由小到大进行反推，再倒序输出，即可得到结果。
     */
    for(int i=0;i<n;i++,s*=2){
        for(int j=0;j<s;j++){
            for(int k=0;k<s;k++){
                a[j][k+s]=a[j+s][k]=a[j][k];
            }
        }
    }

    for(int i=s-1;i>=0;i--){
        for(int j=s-1;j>=0;j--){
            cout<<a[i][j];
            if(j!=0) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}