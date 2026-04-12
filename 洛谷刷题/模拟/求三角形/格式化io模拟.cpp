/*
    题目链接：
    https://www.luogu.com.cn/problem/P5725
 */
#include <iostream>
#include <iomanip>
// iomanip头文件，全称input/output manipulators，提供格式化I/O的流操作符
/*
    setw(int n)：设置下一次输出的最小字段宽度。
    setfill(char c)：设置填充字符（默认为空格）。
    setprecision(int n)：设置输出精度（默认为6）。
    fixed/left/right：格式控制。
        fixed：以固定小数点格式输出浮点数。
        left：左对齐输出。
        right：右对齐输出。

    setw(n) — 设置字段宽度
        - 仅对紧跟的下一次输出生效（非持久），之后自动重置
        - 若实际内容比 n 短，用填充字符补齐（默认左填充）
        - 若实际内容比 n 长，不截断，正常输出

    setfill(c) — 设置填充字符
        - 持久生效，一旦设置一直有效直到被改变
        - 默认填充字符是空格 ' '
*/
using namespace std;

int main()
{
    ios::sync_with_stdio(
        false);
    cin.tie(0);

    int n;
    cin >> n;

    // 第一部分：n*n方阵
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(2) << setfill('0') << cnt++;
        }
        cout << '\n';
    }

    cout << '\n';

    // 第二部分：右对齐三角形
    cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = n - i; s > 0; s--)
            cout << "  ";
        for (int j = 1; j <= i; j++)
        {
            cout << setw(2) << setfill('0') << cnt++;
        }
        cout << '\n';
    }

    return 0;
}