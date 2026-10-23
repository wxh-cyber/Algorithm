/**
 *  @link https://www.luogu.com.cn/problem/P1080
 */

#include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;

 int n;                                              //大臣数量
 int kingA,kingB;                                    //国王左右手的数

// ============ 高精度数约定 ============
// 用 vector<int> 表示大数，每个元素存一位数字(0~9)
// 低位在前，高位在后：例如数字 123 存为 [3, 2, 1]

 /**
  *  @brief mul 高精度 × 低精度：计算A × b
  *  @param {vector<int>} A - 高精度数组
  *  @param {int} b - int 范围的小整数(< 10^4)
  *  @return {vector<int>} C - 结果数组
  */
 vector<int> mul(const vector<int>& A,int b){
    vector<int> C;                                     //结果数组
    long long t=0;                                     //进位，用long long防止溢出
    for(int i=0;i<(int)A.size();i++){
        t+=(long long)A[i]*b;                          //当前位乘积 + 上一位进位
        C.push_back(t%10);                        //保留本次乘积的个位数部分
        t/=10;                                         //计算新进位
    }

    while(t){                                          //处理乘完后剩余的进位
        C.push_back(t%10);
        t/=10;
    }

    // 去除最高位多余的前导零（保留至少一位）
    while(C.size()>1&&C.back()==0){
        C.pop_back();
    }
    return C;
 }

 /**
  *  @brief div - 高精度 ÷ 低精度，计算 A ÷ b 并向下取整
  *  @param {vector<int>} A - 高精度数组
  *  @param {int} b - int 范围的小整数(< 10^4)
  *  @return {vector<int>} C - 结果数组
  */
 vector<int> div(const vector<int>& A,int b){
    vector<int> C;                                      //商的结果
    long long t=0;                                      //当前余数
    //从最高位开始做“竖式除法”
    for(int i=(int)A.size()-1;i>=0;i--){
        t=t*10+A[i];                                    //余数进一位，加上当前位
        C.push_back(t/b);                          //商的这一位
        t%=b;                                           //更新余数
    }

    //循环结束后，得到的是高位在前，翻转后低位在前
    reverse(C.begin(),C.end());
    //去除前导0
    while(C.size()>1&&C.back()==0) C.pop_back();

    return C;
 }

 /**
  *  @brief cmp - 高精度比较：若 A > B 返回 true，否则返回 false
  *  @param {vector<int>} A - 高精度数A
  *  @param {vector<int>} B - 高精度数B
  *  @return {true|false} - 最终比较结果
  */
 bool cmp(const vector<int>& A,const vector<int>& B){
    // 位数不同，位数多的一定大
    if(A.size()!=B.size()) return A.size()>B.size();
    // 位数相同，从最高位开始逐位比较
    for(int i=(int)A.size()-1;i>=0;i--){
        if(A[i]!=B[i]) {
            return A[i]>B[i];
        }
    }

    //完全相等视为"不大于"
    return false;
 }

 int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;                                                      //输入大臣数量
    cin>>kingA>>kingB;                                           //输入国王左右手的数字

    //每位大臣存成{a*b,{a,b}}，方便按照乘积排序
    vector<pair<long long,pair<int,int>>> ministers(n);
    for(int i=0;i<n;i++){
        cin>>ministers[i].second.first>>ministers[i].second.second;
        // a, b < 10^4，乘积 < 10^8，int 也能存，但用 long long 更稳
        ministers[i].first=1LL*ministers[i].second.first*ministers[i].second.second;
    }

    //贪心排序：按 a*b 升序（pair 默认按 first 升序）
    sort(ministers.begin(),ministers.end());

    //前缀乘积：初始为国王左手数字
    vector<int> prefix;
    prefix.push_back(kingA);

    //答案（最大金币数）：初始为 0
    vector<int> ans;
    ans.push_back(0);

    //依次处理每位大臣
    for(int i=0;i<n;i++){      
        // 当前大臣金币 = 前缀乘积 ÷ 他的右手数，向下取整  
        vector<int> coins=div(prefix,ministers[i].second.second);  
        // 更新最大值
        if(cmp(coins,ans)) ans=coins;
        // 前缀乘积累乘上当前大臣的左手数（注意：要在除完之后乘）
        prefix=mul(prefix,ministers[i].second.first);
    }

    // 高位数组低位在前，倒序输出即为正确数值
    for(int i=(int)ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
 }