/**
 * @brief 方块转换
 * @link https://www.luogu.com.cn/problem/P1320
 */
#include <iostream>
using namespace std;

int n;
char _stat[15][15], old[15][15], now[15][15], _end[15][15];
// 初始化矩阵、操作的原矩阵、操作的新矩阵和目标矩阵
// 注意，操作时是用old矩阵和now矩阵，不能改变_stat矩阵
void in()
{ // 输入函数
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> _stat[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> _end[i][j];
        }
    }
}
void f()
{ // 初始化函数
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            now[i][j] = old[i][j] = _stat[i][j];
        }
    }
}
bool check()
{ // 判断操作后的新矩阵与目标矩阵是否符合
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (now[i][j] != _end[i][j])
                return false;
    }
    return true;
}
void turn90()
{ // 顺时针旋转90°
    for (int i = 0, k = n - 1; i < n; i++, k--)
    {
        for (int j = 0; j < n; j++)
        {
            now[j][k] = old[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    { // 更新原矩阵
        for (int j = 0; j < n; j++)
        {
            old[i][j] = now[i][j];
        }
    }
}
void revers()
{ // 左右翻转
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j <= k; j++, k--)
        {
            now[i][j] = old[i][k];
            now[i][k] = old[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    { // 更新原矩阵
        for (int j = 0; j < n; j++)
        {
            old[i][j] = now[i][j];
        }
    }
}
void turn180()
{ // 顺时针旋转180°
    turn90();
    turn90();
}
void turn270()
{ // 顺时针旋转270°
    turn180();
    turn90();
}
bool comb()
{             // 组合方法
    revers(); // 先反转
    turn90(); // 选择转90°的情况
    if (check())
        return true; // 判断与目标矩阵是否符合
    f();             // 初始化

    revers();
    turn180(); // 选择转180°的情况
    if (check())
        return true;
    f();

    revers();
    turn270(); // 选择转270°的情况
    if (check())
        return true;
    f();

    return false; // 如果都不行就返回false
}
int main()
{
    cin >> n;
    in();
    f();      // 初始化
    turn90(); // 方法1是否可行
    if (check())
    {
        cout << 1;
        return 0;
    }
    f(); // 每次使用玩方法后都要初始化！一定注意！

    turn180(); // 法2可行性
    if (check())
    {
        cout << 2;
        return 0;
    }
    f();

    turn270(); // 法3可行性
    if (check())
    {
        cout << 3;
        return 0;
    }
    f();

    revers(); // 法4可行性
    if (check())
    {
        cout << 4;
        return 0;
    }
    f();

    if (comb())
    { // 法5可行性
        cout << 5;
        return 0;
    }
    f();

    if (check())
    { // 不改变原矩阵，直接check
        cout << 6;
        return 0;
    }
    cout << 7; // 前6种方法都不行就输出7
    return 0;
    // 完结撒花
}