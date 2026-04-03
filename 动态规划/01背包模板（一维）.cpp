/*
    01背包模板
    题目链接：https://www.luogu.com.cn/problem/P1048
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int w[105], val[105]; // w[i]表示第i件物品花费时间，val[i]表示第i件物品的价值
int dp[1005];         // dp[i]表示在时间i内可以得到的最大价值
int main()
{
    int t, m, res = -1;
    scanf("%d %d", &t, &m); // 输入总时间和草药总数

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &w[i], &val[i]); // 输入第i件物品花费的时间和价值
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= 0; j--)
        { // 一维时，从后往前遍历，避免覆盖已计算的结果
            if (j >= w[i])
            {
                dp[j] = max(dp[j - w[i]] + val[i], dp[j]);
            }
        }
    }
    printf("%d", dp[t]);

    return 0;
}