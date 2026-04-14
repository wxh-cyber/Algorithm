/**
    题目链接：
    https://www.luogu.com.cn/problem/P2141
 */
#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n); // 将输入数据从小到大进行排序

    int count = 0;
    int l, r;
    for (int i = n - 1; i >= 2; i--)
    {
        // 每次选定一个大的数，都设定头尾两个指针
        l = 0, r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] < a[i])
            {
                l++;
            }
            else if (a[l] + a[r] > a[i])
            {
                r--;
            }
            else
            {
                count++;
                break;
            }
        }
    }

    cout << count << '\n';

    return 0;
}