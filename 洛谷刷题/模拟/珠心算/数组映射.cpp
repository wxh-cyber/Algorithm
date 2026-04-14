/*
    题目链接：
    https://www.luogu.com.cn/problem/P2141
 */
#include <iostream>
using namespace std;

const int N = 105, M = 2e4 + 5;

int a[N];
bool f[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = true;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = a[i] + a[j];
            if (f[sum])
            {
                ans++;
                f[sum] = false;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}