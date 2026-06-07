#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  @note 算法性能分析：
 *    在C++中，vector的insert在头部插入元素的时间复杂度是O（N），这将导致时间复杂度为O（N^2）
 */

/**
 *  @brief 比较两个高精度数的大小
 *  @param A 第一个高精度数（低位在前，高位在后）
 *  @param B 第二个高精度数（低位在前，高位在后）
 *  @returns 如果A>=B返回true，否则返回false
 */
bool cmp(const vector<int>& A,const vector<int>& B){
    if(A.size()!=B.size()) return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]!=B[i]) return A[i]>B[i];
    }
    return true;
}

/**
 *  @brief 高精度数减法 A-B=C
 *  @param A 被减数（低位在前，高位在后）
 *  @param B 减数（低位在前，高位在后）
 *  @returns C （低位在前，高位在后）
 *  @note A、B、C、R都是vector<int>类型
 */
vector<int> sub(const vector<int>& A,const vector<int>& B){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

/**
 *  @brief 高精度数除法 A/B=C...R
 *  @param A 被除数（低位在前，高位在后）
 *  @param B 除数（低位在前，高位在后）
 *  @param R 余数（通过引用返回）
 *  @returns C （低位在前，高位在后）
 *  @note A、B、C、R都是vector<int>类型
 */
vector<int> div_high(const vector<int>& A,const vector<int>& B,vector<int>& R){
    vector<int> C(A.size(),0);                     //商的位数最多和A的位数一样，先初始化全0
    R=A;                                           //初始余数为A

    //从最高位开始试商（i表示当前正在试的位，也代表偏移量）
    for(int i=A.size()-1;i>=0;i--){
        // 偏移量 i 表示 B 需要乘 10^i，逻辑上 B 的个位与 R 的第 i 位对齐
        
        // 核心优化：循环减法，计算当前位能商几
        // 判断条件：把 R 的低 i 位遮住不看，剩下的高位部分是否 >= B
        // 实现：把 R 从第 i 位开始截断，构造一个临时的高位前缀
        while(i<=R.size()-1){                   //确保截断后不为空
            vector<int> R_high(R.begin()+i,R.end());         //截取R的最高部分

            //如果截取的高位部分大于等于B，说明当前位至少能商1
            if(cmp(R_high,B)){
                //高位部分减去B
                vector<int> new_R_high=sub(R_high,B);

                //把减去后的高位部分拼回R中
                //先保留R的低i位不变
                R.resize(i);
                //再拼上新的高位部分
                R.insert(R.end(),new_R_high.begin(),new_R_high.end());
                
                //去除R整体可能产生的前导0
                while(R.size()>1&&R.back()==0) R.pop_back();

                //当前位商加1
                C[i]++;
            }else {
                // 如果高位部分小于 B，说明当前位已经不能再商更大的数了，跳出内层循环
                break;
            }
        }
    }

    //去除商C的前导0
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