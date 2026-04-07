/*
    快读快写（基础版）
 */
#include <cstdio>
#include <cctype> //用于isdigit和isgraph

// 快读模板
template <typename T>
inline T read()
{
    T x = 0;
    bool f = 1;          // 符号位，1为正，-1为负
    char ch = getchar(); // 读取第一个字符

    // 1.跳过非数字字符（包括空格、换行、回车等）
    // isgraph(ch)判断是否为可打印且非空格的字符，用于处理负号'-'
    while (!isdigit(ch) && !isgraph(ch))
        ch = getchar();

    // 2.处理负数
    if (ch == '-')
    {
        f = -1;
        ch = getchar(); // 跳过负号，读取下一个字符，必须是数字
    }

    // 3.读取数字主体
    while (isdigit(ch))
    {
        // (x << 1) + (x << 3) 等价于 x * 10，但位运算速度更快
        // (ch ^ 48) 等价于 (ch - '0')，位运算速度更快
        x = (x << 1) + (x << 3) + (ch ^ '0');
        ch = getchar(); // 读取下一个字符
    }

    return x * f;
}

// 为了使用方便，提供不同类型的重载
inline int read_int()
{
    return read<int>();
}

inline long long read_ll()
{
    return read<long long>();
}

// 快写模板
template <typename T>
inline void write(T x)
{
    // 优化：如果输出的数字很小，直接用putchar输出字符，避免调用栈
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }

    if (x > 9)
    {
        write(x / 10); // 递归输出高位
    }

    putchar((x % 10) + '0'); // 输出当前最低位
}

int main()
{
    // 快读示例：读取两个整数
    int n = read_int();
    long long m = read_ll();

    // 快写示例：输出结果
    write(n + m);
    putchar('\n'); // 输出换行符

    return 0;
}