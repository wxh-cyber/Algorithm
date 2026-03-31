/*
     题目链接：https://www.luogu.com.cn/problem/P1601
 */
#include <iostream>
#include <string>
#define int long long
using namespace std;

string add(string a, string b)
{
    int len = max(a.size(), b.size()); // 记录a，b的长度的最大值
    int jw = 0;
    string c = "";
    while (a.size() < len)
        a = '0' + a;
    while (b.size() < len)
        b = '0' + b;
    for (int i = len - 1; i >= 0; i--)
    {
        int t1 = a[i] - '0', t2 = b[i] - '0';
        int t = t1 + t2 + jw; // 计算每一位的和
        jw = t / 10;          // 记录进位
        t %= 10;              // 记录当前位的数字
        char ch = t + '0';    // 将当前位的数字转换为字符
        c = ch + c;           // 将当前位的字符拼接在结果字符串的前面
    }
    if (jw != 0)
        return '1' + c;
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2);
    return 0;
}