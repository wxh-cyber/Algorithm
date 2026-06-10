#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 *  @brief 判断两个大整数的大小
 *  @param A 大整数A（vector形式，低位在前）
 *  @param B 大整数B（vector形式，低位在前）
 *  @return 如果A>B，返回true；否则返回false
 */
bool cmp(vector<int>& A,vector<int>& B){
    //位数不同，长度长的更大
    if(A.size()!=B.size()) return A.size()>B.size();

    //位数相同，从高位到低位比较
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]!=B[i]) {
            return A[i]>B[i];
        }
    }

    //完全相等
    return true;
}

/**
 *  @brief 高精度减法 C=A-B
 *  @param A 被减数（vector形式，低位在前）
 *  @param B 减数（vector形式，低位在前）
 *  @return 差（vector形式，低位在前）
 */
vector<int> sub(vector<int>& A,vector<int>& B){
    vector<int> C;
    int t=0;                                       //借位标记

    for(int i=0;i<A.size();i++){
        t=A[i]-t;                                  //减去上一位的借位
        if(i<B.size()) t-=B[i];                    //减去当前位B的值

        /** 
         *  (t+10)%10的核心逻辑：
         *    如果t>=0，说明本位够减，直接存t
         *    如果t<0，说明不够减，需要借位，t+10即为结果
         */
        C.push_back((t+10)%10);                    //计算本位的结果，存入C中

        if(t<0) t=1;                               //如果不够减，需要借位，标记t为1
        else t=0;                                   //否则，标记t为0
    }

    //去除前导0（例如1000-999=1，而不是0001）
    //注意要保留最后一位，除非结果是0
    while(C.size()>1&&C.back()==0) {
        C.pop_back();
    }

    return C;
}

int main(){
    string a,b;
    vector<int> A,B;

    //输入两个字符串形式的数字
    cin>>a>>b;

    //将字符串存入vector，为了方便计算【低位在前，高位在后】
    //例如"123"，存为[3,2,1]
    for(int i=a.size()-1;i>=0;i--) {
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }

    vector<int> C;
    
    //判断A和B的大小关系
    if(cmp(A,B)){
        C=sub(A,B);
    }else {
        //如果A<B，则结果为负数，计算B-A并输出负号
        C=sub(B,A);
        cout<<"-";
    }

    //输出结果（vector是低位在前，所以要倒序输出）
    for(int i=C.size()-1;i>=0;i--){
        cout<<C[i];
    }
    cout<<endl;

    return 0;
}