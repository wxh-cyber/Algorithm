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
int dp[105][105];     // dp[i][j]表示前i件物品中选择重量不超过j的最大价值
int main()
{
    int t, m, res = -1;
    scanf("%d %d", &t, &m); // 输入给定时间和草药总数

    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &w[i], &val[i]); // 输入草药的花费时间和相应价值
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i - 1][j - w[i]] + val[i], dp[i - 1][j]); // 如果当前时间j大于等于第i件物品的花费时间w[i]，则可以选择放入背包或者不放入背包，取两者的最大值
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // 如果当前时间j小于第i件物品的花费时间w[i]，则不能放入背包，取前i-1件物品的最大价值
            }
        }
    }
    printf("%d", dp[m][t]);

    return 0;
}