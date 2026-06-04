#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  @brief 比较两个高精度数的大小
 *  @param  A 第一个高精度数（低位在前，高位在后）
 *  @param  B 第二个高精度数（低位在前，高位在后）
 *  @return 如果A>=B返回true，否则返回false
 */
bool cmp(vector<int>& A,vector<int>& B){
    if(A.size()!=B.size()) return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]!=B[i]) return A[i]>B[i];
    }
    return true;
}

vector<int> sub(vector<int>& A,vector<int>& B){
    vector<int> C;
    int t=0;                                           //t表示借位
    for(int i=0;i<A.size();i++){
        t=A[i]-t;                                      //在运算前，先减去借位
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);                        //考虑到可能t<0的情况，所以需要加上10
        if(t<0) t=1;                                   //如果t<0，说明需要借位
        else t=0;                                      //否则，无需借位
    }

    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

/**
 *  @brief div_high 高精度数除以高精度数 A/b=C...r
 *  @param  A 被除数（低位在前，高位在后）
 *  @param  B 除数（低位在前，高位在后）
 *  @param  R 余数（通过引用返回）
 *  @return C （低位在前，高位在后）
 *  @note  A/B=C...R，A、B、C、R都是vector<int>类型
 */
vector<int> div_high(vector<int> A,vector<int> B,vector<int>& R){
    //商的位数最多和A的位数一样，先初始化全0
    vector<int> C(A.size(),0);
    R=A;
    
    //从最高位开始试商（i对应商的位数索引，也是移位的位数）
    //A的长度为A.size()，索引为0-A.size()-1
    for(int i=A.size()-1;i>=0;i--){
        //构造移位后的除数：相当于B*10^i
        //在B的末尾补i个0
        vector<int> B_shift(B.begin(),B.end());
        for(int j=0;j<i;j++){
            B_shift.insert(B_shift.begin(),0);        //低位补0
        }

        //如果当前余数大于等于移位后的除数，就一直减，并累计商
        while(cmp(R,B_shift)){
            R=sub(R,B_shift);
            C[i]++;                                   //商的第i位加1
        }
    }

    //去除商的前导0
    while(C.size()>1&&C.back()==0) C.pop_back();

    return C;
}

int main(){
    string a,b;
    cin>>a>>b;

    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    vector<int> R;
    vector<int> C=div_high(A,B,R);

    //输出商
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl;

    //输出余数
    for(int i=R.size()-1;i>=0;i--) cout<<R[i];
    cout<<endl;

    return 0;
}