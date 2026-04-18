/**
 * @brief 压缩技术
 * @link https://www.luogu.com.cn/problem/P1319
 */
#include <iostream>
using namespace std;

int n, x;          // n为矩阵的大小，x为输入的数
int ans[205][205]; // ans为答案矩阵
int a = 0, b = 0;  // a为行，b为列
bool t = false;    // t为当前填的数
int main()
{
    scanf("%d", &n); // 输入矩阵的大小

    // 注意:这里也可以写成scanf("%d",&x)!=1，具有更严格的类型限制
    while (scanf("%d", &x) != EOF)
    { // 输入压缩后的数
        while (x-- > 0)
        {
            ans[a][b] = t;
            b++;
            if (b == n)
            {
                a++;
                b = 0;
            }
        }
        t = !t;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}