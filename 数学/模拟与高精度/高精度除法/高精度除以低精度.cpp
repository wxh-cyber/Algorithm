#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/**
 *  @brief 高精度数除以低精度数 A/b=C...r
 *  @param  A 被除数（低位在前，高位在后）
 *  @param  b 除数（普通整数）
 *  @param  r 余数（通过引用返回）
 *  @return C （低位在前，高位在后）
 */
vector<int> div(vector<int>& A,int b,int& r){
    vector<int> C;
    r=0;                                    //余数初始化为0

    //除法从最高位开始算（即vector末尾）
    for(int i=A.size()-1;i>=0;i--){
        //当前被除数=上一位的余数*10+当前位的数字
        r=r*10+A[i];
        //商的当前位=被除数/除数
        C.push_back(r/b);
        //新余数=被除数%除数
        r%=b;
    }

    //因为是从高位开始push的，此时C里面是[高位...低位]
    //为了与其他高精度运算统一（低位在前，高位在后），需要翻转C
    reverse(C.begin(),C.end());

    // 去除前导零（翻转后，前导零在数组的末尾）
    while(C.size()>1&&C.back()==0){
        C.pop_back();
    }

    return C;
}

int main(){
    string a;
    int b;
    cin>>a>>b;

    vector<int> A;

    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }

    int r;                                 //余数
    vector<int> C=div(A,b,r);

    //输出商（逆序输出）
    for(int i=C.size()-1;i>=0;i--){
        cout<<C[i];
    }

    //输出余数
    cout<<endl<<r<<endl;

    return 0;
}