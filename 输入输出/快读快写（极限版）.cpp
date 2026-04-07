/*
    快读快写（极限版）
    当数据量达到10^7级别，或者题目卡常数卡得非常死时，频繁调用 getchar() 也会产生较大的函数调用开销。
    这个版本直接将整个文件读入内存缓冲区，然后像指针一样在内存中移动，是目前C++中最快的IO方式。
 */

/*
    fread 是 C 标准库函数（C++ 里也可用，头文件通常是 <cstdio> 或 <stdio.h>），用于从文件流读取二进制数据块。
    语法：size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
    参数：
        ptr：读取到的数据存放地址（缓冲区指针）
        size：每个元素的字节大小
        count：要读取的元素个数
        stream：文件指针（FILE*）
    返回值：
        返回实际读取到的元素个数（不是字节数）
        若小于 count，可能到达文件末尾或发生错误（可用 feof(stream) / ferror(stream) 判断）

    fwrite 用于把内存中的数据按二进制块写入文件（C++ 可通过 <cstdio> 使用）。
    语法：size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);
    参数：
        ptr：要写入的数据地址
        size：每个元素的字节大小
        count：要写入的元素个数
        stream：目标文件指针（FILE*）
    返回值：
        返回实际成功写入的元素个数
        若返回值 < count，说明写入不完整（可能磁盘满、权限问题、流错误等）
 */
#include <cstdio>

namespace IO
{
    // 缓冲区大小一般设为 1 << 20 (约1MB) 到 1 << 22 (约4MB) 之间
    const int MAXSIZE = 1 << 21;
    char ibuf[MAXSIZE], *iS, *iT;                         // 输入缓冲区及指针
    char obuf[MAXSIZE], *oS = obuf, *oT = obuf + MAXSIZE; // 输出缓冲区及指针

    // 获取输入字符（从内存缓冲区中拿，极快）
    inline char gc()
    {
        if (iS == iT)
        {
            iT = (iS = ibuf) + fread(ibuf, 1, MAXSIZE, stdin);
            if (iS == iT)
                return EOF; // 文件读完了
        }

        return *iS++;
    }

    // 刷新输出缓冲区
    inline void flush()
    {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    // 结构体析构时自动刷新，防止忘记清空缓存区导致输出不全
    struct Flusher
    {
        ~Flusher() { flush(); }
    } _flusher;
}

// 快读
template <typename T>
inline void read(T &x)
{
    x = 0;
    bool f = 0;
    char ch = gc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = 1;
        ch = gc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = gc();
    }

    // 如果标志位为负数，则将其转化为负数
    if (f)
        x = -x;
}

// 快写
template <typename T>
inline void write(T x)
{
    static char stk[20]; // 局部栈，避免递归开销
    int top = 0;
    if (x < 0)
    {
        *oS++ = '-';
        x = -x;
    }

    if (x == 0)
    {
        *oS++ = '0';
        return;
    }

    while (x)
    {
        stk[top++] = x % 10 + '0';
        x /= 10;
    }

    while (top--)
    {
        *oS++ = stk[top]; // 写入输出缓冲区
        // 如果缓冲区满了，立刻刷出
        if (oS == oT)
            flush();
    }

    // 快速输出字符串
    inline void write(const char *s)
    {
        while (*s)
        {
            *oS++ = *s++;
            if (oS == oT)
                flush();
        }
    }

    // 快速输出字符
    inline void write(char c)
    {
        *oS++ = c;
        if (oS == oT)
            flush();
    }
}

// 使用示例
using namespace IO;

int main()
{
    int n;
    long long m;

    // 传引用读取
    read(n);
    read(m);

    write(n + m);
    write('\n'); // 换行

    // 注意：程序结束时会自动调用 ~Flusher() 刷出剩余数据
    return 0;
}