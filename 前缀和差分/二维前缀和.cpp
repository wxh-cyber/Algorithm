/**
 * @file 二维前缀和.cpp
 * @brief 二维前缀和模板
 * @link：https://www.luogu.com.cn/problem/P1387
 */
#include <iostream>
#include <vector>
using namespace std;

int n, m;                  // 数组大小
vector<vector<int>> a, ps; //(n+1)*(m+1)

/**
 * @brief 构造前缀和数组
 */
void prefix_sum()
{
    ps = a; // 先将a中的数据转移到ps中
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]; // 计算前缀和
        }
    }
}

/**
 * @brief 查询区间[x1,y1]~[x2,y2]的和
 */
int query(int x1, int y1, int x2, int y2)
{
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1]; // 查询区间[x1,y1]~[x2,y2]的和
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    a.assign(n + 1, vector<int>(m + 1)); // 初始化a数组

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    prefix_sum();

    int ans = 0;
    for (int l = 1; l <= min(n, m); l++)
    { // 枚举正方形的边长，边长最大不能超过整个数组规模的较小值
        for (int i = l; i <= n; i++)
        {
            for (int j = l; j <= m; j++)
            {
                if (query(i - l + 1, j - l + 1, i, j) == l * l)
                {                      // 如果边长为l的正方形内的元素和等于l*l，说明这个正方形内的元素全为1
                    ans = max(ans, l); // 满足条件的正方形数量加1
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}