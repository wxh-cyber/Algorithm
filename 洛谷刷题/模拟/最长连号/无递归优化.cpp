/*
    题目链接：
    https://www.luogu.com.cn/problem/P1420
 */
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sl; // 定义要输入的数据长度
    cin >> sl;
    if (sl == 0)
    {
        cout << 0; // 如果输入长度为0，直接输出0并结束程序
        return 0;
    }

    int prev, cur; // 定义两个变量，prev用来记录前一个数，cur用来记录当前数
    cin >> prev;   // 输入第一个数，作为初始的前一个数

    int len = 1, ans = 1;
    for (int i = 1; i < sl; i++)
    {
        cin >> cur; // 输入当前数
        if (cur == prev + 1)
            len++; // 如果当前数与前一个数连续，长度加1
        else
            len = 1;
        if (len > ans)
            ans = len; // 如果当前长度大于答案，更新答案
        prev = cur;    // 更新前一个数为当前数
    }
    cout << ans; // 输出答案

    return 0;
}