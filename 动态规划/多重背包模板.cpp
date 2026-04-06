/*
    多重背包模板
    相关链接：https://oi-wiki.org/dp/knapsack/#多重背包

    说明：多重背包的本质就是把一个物品可以选择k次的问题转化成了k个物品的01背包问题。
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;         // 开辟常量表示数组长度上限
int W, n;                      // 背包能容纳的最大质量或规定花费的最大时间，n为物品品种类数量
int w[N], v[N], cnt[N], dp[N]; // w数组记录每种物品的占据容量或花费时间，v数组记录每种物品的对应价值，cnt数组记录每个物品的数量，dp数组记录每个物品的最优解
int main()
{
    scanf("%d %d", &W, &n); // 输入背包容量上限和物品品种类数量
    for (int i = 1; i <= n; i++)
        scanf("%d", &cnt[i]); // 输入每个物品的数量
    for (int i = 1; i <= n; i++)
    { // 遍历每一种物品
        for (int weight = W; weight >= w[i]; weight--)
        {
            for (int k = 1; k * w[i] <= weight && k <= cnt[i]; k++)
            {                                                                   // 多遍历一层物品的数量
                dp[weight] = max(dp[weight], dp[weight - k * w[i]] + k * v[i]); // 更新当前背包容量下的最优解
            }
        }
    }
    printf("%d", dp[W]); // 输出最大价值

    return 0;
}