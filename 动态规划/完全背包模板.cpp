/*
    完全背包模板：
    题目链接：https://www.luogu.com.cn/problem/P1616
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e4 + 5, M = 1e7 + 5;
int n, m, w[N], v[N], f[M];

int main()
{
    scanf("%lld %lld", &m, &n); // 输入总时间和物品种类数量
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &w[i], &v[i]); // 分别输入不同物品的花费时间和对应价值
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = w[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]); // 完全背包和01背包的区别在于对时间大小的枚举顺序不同
        }
    }
    printf("%lld", f[m]); // 输出最大价值
    return 0;
}