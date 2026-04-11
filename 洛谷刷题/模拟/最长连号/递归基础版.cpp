/*
    题目链接：
    https://www.luogu.com.cn/problem/P1420
 */
#include <iostream>
using namespace std;

int sz[100000];
int zc(int i) // 从sz[i]开始，求连号的长度
{
    if (sz[i] == sz[i + 1] - 1)
        return 1 + zc(i + 1);
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sl, ans = 0, i;
    cin >> sl;
    for (i = 0; i < sl; i++) // 读入数据
        cin >> sz[i];
    for (i = 0; i < sl - 1; i++)
    {
        if (zc(i) > ans)
            ans = zc(i);
    }
    cout << ans;
    return 0;
}