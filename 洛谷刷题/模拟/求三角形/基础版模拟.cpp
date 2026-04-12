/*
    题目链接：
    https://www.luogu.com.cn/problem/P5725
 */
#include <iostream>
using namespace std;

int n, a = 0;
int t;
int main()
{
    cin >> n;
    int m = n * n;           // 第一部分：n*n方阵
    int p = (1 + n) * n / 2; // 第二部分：右对齐三角形

    for (int i = 1; i <= m; i++)
    {
        if (i < 10)
            cout << "0" << i;
        else
            cout << i;
        if (i % n == 0)
            cout << endl;
    }
    cout << endl;

    for (int j = 1; j <= n; j++) // 循环三角形的每一行
    {
        t = a + 1; // 每一行的第一个数和最后一个数
        a += j;
        for (int k = n - j; k > 0; k--)
            cout << "  ";
        for (int i = t; i <= a; i++)
        {
            if (i < 10)
                cout << "0" << i;
            else
                cout << i;
        }
        cout << endl;
    }
    return 0;
}