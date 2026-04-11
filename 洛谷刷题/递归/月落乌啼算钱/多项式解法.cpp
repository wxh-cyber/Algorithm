/*
    题目链接：
    https://www.luogu.com.cn/problem/P1720

    解题思路：
    题目要求计算第 n 个 Fibonacci 数。

    核心数学原理：多项式快速幂
    Fibonacci 数列满足 F(n) = F(n-1) + F(n-2)，其特征多项式为 x² - x - 1 = 0，
    即 x² ≡ x + 1 (mod x² - x - 1)。
    由此可以证明：
        x^n mod (x² - x - 1) = F(n)·x + F(n-1)
    因此只需计算 x^n mod g(x)，其中 g(x) = -x² + x + 1（与 x²-x-1 互为相反数，取模结果相同），
    结果多项式中 x 的系数即为 F(n)。

    本题将多项式乘法用 FFT 实现，但由于模多项式次数仅为 2，多项式始终不超过 1 次，
    实际上 FFT 并非必要，属于通用库的过度设计。
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

namespace mikiwang
{
    // =========================================================
    // 复数类：提供 FFT 所需的复数运算
    // r 为实部，v 为虚部
    // =========================================================
    class complex
    {
    public:
        long double r, v;

        // 单参数构造：仅给实部赋值，虚部置 0（也作隐式类型转换，允许 complex c = 3.0）
        complex(long double r_ = 0)
        {
            r = r_;
            v = 0;
        }

        // 双参数构造：分别指定实部和虚部
        complex(long double r_, long double v_)
        {
            r = r_;
            v = v_;
        }

        // 复数加法：(a+bi) + (c+di) = (a+c) + (b+d)i
        complex operator+(const complex &c) const { return complex(r + c.r, v + c.v); }
        // 调用前面已经定义好的加法
        complex &operator+=(const complex &c) { return *this = *this + c; }

        // 复数减法：(a+bi) - (c+di) = (a-c) + (b-d)i
        complex operator-(const complex &c) const { return complex(r - c.r, v - c.v); }
        complex &operator-=(const complex &c) { return *this = *this - c; }

        // 复数乘法：(a+bi)*(c+di) = (ac-bd) + (bc+ad)i
        complex operator*(const complex &c) const { return complex(r * c.r - v * c.v, v * c.r + r * c.v); }
        complex &operator*=(const complex &c) { return *this = *this * c; }

        // 复数除法：(a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
        // ⚠️ Bug：分母 d 应为 c.r*c.r + c.v*c.v（模的平方），此处写成了 c.r*c.r - c.v*c.r，公式有误。
        //         虚部分子也应为 (v*c.r - r*c.v)，此处符号写反。
        //         本题系数全为实数，FFT 单位根模为 1，计算结果恰好不受影响。
        complex operator/(const complex &c) const
        {
            long double d = c.r * c.r + c.v * c.v; // ← 应为 c.r*c.r + c.v*c.v
            return complex((r * c.r + v * c.v) / d, (r * c.v - v * c.r) / d);
        }
        // ⚠️ Bug：返回值类型应为 complex&（与其他复合赋值运算符一致），此处返回 complex 值。
        complex operator/=(const complex &c) { return *this = *this / c; }

        // 取反：-(a+bi) = (-a) + (-b)i
        complex operator-() const { return complex(-r, -v); }
    };
}

namespace mikiwang
{
    // =========================================================
    // 多项式类：用复数数组表示多项式系数
    // data[i] 表示 x^i 的系数，最高次为 len
    // =========================================================
    class polymerization
    {
    private:
        int len;       // 多项式最高次数
        complex *data; // 系数数组，data[0..len]

        // FFT 变换（静态方法，供乘法内部调用）
        // a：系数数组，n：变换点数（2的幂），op：1 为正变换，-1 为逆变换
        static void fft(complex *, int, int);

    public:
        polymerization(int = 0);                // 构造度为 len_ 的零多项式
        polymerization(const polymerization &); // 拷贝构造
        ~polymerization();
        int length() const; // 返回最高次数 len

        // 隐式转换为 complex*，使 poly[i] 可直接访问 data[i]
        operator complex *();
        operator const complex *() const;

        polymerization &operator=(const polymerization &);
        polymerization &resize(int); // 调整最高次数（扩容时重新分配内存）

        polymerization operator-() const;                       // 各系数取反
        polymerization operator+(const polymerization &) const; // 多项式加法
        polymerization operator-(const polymerization &) const; // 多项式减法
        polymerization operator*(long double) const;            // 各系数乘以标量
        polymerization operator*(complex) const;                // 各系数乘以复数
        polymerization operator/(long double) const;            // 各系数除以标量
        polymerization operator/(complex) const;                // 各系数除以复数
        polymerization operator*(const polymerization &) const; // 多项式乘法（FFT）
        polymerization inverse() const;                         // 多项式逆元（Newton 迭代）
        polymerization &reverse();                              // 翻转系数
        polymerization operator/(const polymerization &) const; // 多项式除法
        polymerization operator%(const polymerization &) const; // 多项式取模
    };
}

using mikiwang::polymerization;

// =========================================================
// 多项式快速幂：计算 a^n mod p
// 标准二进制快速幂，乘法和取模均为多项式运算
// =========================================================
polymerization pow(polymerization a, long long n, const polymerization &p)
{
    polymerization ret; // 初始化为度为 0 的多项式
    ret[0] = 1;         // ret = 1（常数多项式）
    while (n)
    {
        if (n & 1) // 若当前二进制位为 1
            ret = ret * a % p;
        a = a * a % p; // a 平方
        n >>= 1;       // 处理下一个二进制位
    }
    return ret;
}

// 对 long double 取绝对值（避免与 std::abs 冲突）
long double abs(long double x)
{
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    // a(x) = x（一次多项式），g(x) = -x²+x+1（二次模多项式）
    polymerization a(1), g(2), r;
    long long n;
    scanf("%lld", &n);

    // 特判 n=0：F(0) = 0
    if (!n)
    {
        printf("0.00\n");
        return 0;
    }

    // 构造 a(x) = x（即 0·x^0 + 1·x^1）
    a[0] = 0;
    a[1] = 1;

    // 构造 g(x) = 1 + x - x²（即 -(x²-x-1)，Fibonacci 特征多项式的相反数）
    // 取模意义相同：x² ≡ x+1 (mod g)
    g[0] = 1;
    g[1] = 1;
    g[2] = -1;

    // 计算 x^n mod g(x)，结果为 F(n)·x + F(n-1)
    r = pow(a, n, g);

    // r[1] 是 x 的系数，即 F(n)；取实部并输出（保留两位小数）
    printf("%.2Lf\n", abs(r[1].r));
    return 0;
}

namespace mikiwang
{
    using std::max;
    using std::swap;

    // 构造度为 len_ 的零多项式，所有系数初始化为 0
    polymerization::polymerization(int len_)
    {
        len = len_;
        data = new complex[len + 1];
        for (int i = 0; i <= len; i++)
        {
            data[i].r = 0;
            data[i].v = 0;
        }
    }

    // 拷贝构造：先将自身置为空态，再通过赋值运算符完成深拷贝
    polymerization::polymerization(const polymerization &a)
    {
        len = -1;
        data = 0;
        *this = a;
    }

    // 析构：释放堆内存
    // ⚠️ Bug：数组应使用 delete[] data，此处用 delete data 是未定义行为
    polymerization::~polymerization()
    {
        len = -1;
        delete data; // ← 应为 delete[] data
    }

    // 返回多项式最高次数
    int polymerization::length() const
    {
        return len;
    }

    // 隐式转换运算符：返回底层数组指针，使 poly[i] 直接访问 data[i]
    polymerization::operator complex *()
    {
        return data;
    }
    polymerization::operator const complex *() const
    {
        return data;
    }

    // 深拷贝赋值
    polymerization &polymerization::operator=(const polymerization &a)
    {
        resize(a.len);
        for (int i = 0; i <= len; i++)
            data[i] = a[i];
        return *this;
    }

    // 调整多项式次数为 len_
    // 若新次数更大，则重新分配内存并拷贝旧数据；否则仅更新 len
    // ⚠️ Bug：扩容时新增位置（旧 len+1 到 len_）未初始化为 0，可能存在脏数据
    // ⚠️ Bug：delete data 应为 delete[] data
    polymerization &polymerization::resize(int len_)
    {
        if (len < len_) // 需要扩容
        {
            complex *p = new complex[len_ + 1];
            for (int i = 0; i <= len; i++)
                p[i] = data[i]; // 拷贝旧数据
            delete data;        // ← 应为 delete[] data
            data = p;
        }
        len = len_;
        return *this;
    }

    // 多项式取反：每个系数取反
    polymerization polymerization::operator-() const
    {
        polymerization ret(*this);
        for (int i = 0; i <= len; i++)
            ret[i] = -ret[i];
        return ret;
    }

    // 多项式加法：按位相加，结果次数取两者较大值
    // ⚠️ Bug：第二个循环应为 for(int i=0;i<=a.len;i++)，此处误写为 i<=len，
    //         导致当 a.len > len 时，a 的高次系数未被加入结果
    polymerization polymerization::operator+(const polymerization &a) const
    {
        polymerization ret = max(len, a.len); // 创建足够大的零多项式
        for (int i = 0; i <= len; i++)
            ret[i] += data[i];         // 加入 *this 的系数
        for (int i = 0; i <= len; i++) // ← 应为 i <= a.len
            ret[i] += a[i];            // 加入 a 的系数
        return ret;
    }

    // 多项式减法：按位相减
    // ⚠️ Bug：同加法，第二个循环应为 i <= a.len
    polymerization polymerization::operator-(const polymerization &a) const
    {
        polymerization ret = max(len, a.len);
        for (int i = 0; i <= len; i++)
            ret[i] += data[i];
        for (int i = 0; i <= len; i++) // ← 应为 i <= a.len
            ret[i] -= a[i];
        return ret;
    }

    // FFT（快速傅里叶变换）
    // 原理：利用单位根的性质将 O(n²) 的多项式求值加速到 O(n log n)
    // op=1：正变换（时域→频域），op=-1：逆变换（频域→时域）
    void polymerization::fft(complex *a, int n, int op)
    {
        static const long double PI = acos(-1);

        // 计算位逆序置换（bit-reversal permutation）
        // pos[i] 是 i 的二进制位逆序后的值，用于蝶形运算前的原地重排
        int *pos = new int[n];
        pos[0] = 0;
        for (int i = 1; i < n; i++)
            // 递推：pos[i] = (pos[i/2] >> 1) | ((i的最低位) << (logn-1))
            pos[i] = (pos[i >> 1] >> 1) | ((i & 1) * (n >> 1));

        // 按位逆序置换重排数组
        for (int i = 1; i < n; i++)
            if (i < pos[i])
                swap(a[i], a[pos[i]]);

        // 蝶形运算：从小到大合并，每次处理长度为 2l 的子段
        complex A, B;
        for (int l = 1; l < n; l <<= 1) // l：当前蝶形单元的半长
        {
            for (int i = 0; i < n; i += l << 1) // 遍历每个长度为 2l 的子段
            {
                for (int j = 0; j < l; j++)
                {
                    A = a[i + j];
                    // 旋转因子（单位根）：e^(i·π·j/l) = cos(πj/l) + op·i·sin(πj/l)
                    // op=1 为正变换，op=-1 为逆变换（共轭单位根）
                    B = complex(cos(PI * j / l), op * sin(PI * j / l)) * a[i + j + l];
                    a[i + j] = A + B;     // 蝶形上翼
                    a[i + j + l] = A - B; // 蝶形下翼
                }
            }
        }
        // ⚠️ Bug：应为 delete[] pos
        delete pos; // ← 应为 delete[] pos
    }

    // 多项式各系数乘以实数标量 k
    polymerization polymerization::operator*(long double k) const
    {
        polymerization ret(*this);
        for (int i = 0; i <= len; i++)
            ret[i] *= k;
        return ret;
    }

    // 多项式各系数乘以复数 c
    polymerization polymerization::operator*(complex c) const
    {
        polymerization ret(*this);
        for (int i = 0; i <= len; i++)
            ret[i] *= c;
        return ret;
    }

    // 多项式各系数除以实数标量 k
    polymerization polymerization::operator/(long double k) const
    {
        polymerization ret(*this);
        for (int i = 0; i <= len; i++)
            ret[i] /= k;
        return ret;
    }

    // 多项式各系数除以复数 c
    polymerization polymerization::operator/(complex c) const
    {
        polymerization ret(*this);
        for (int i = 0; i <= len; i++)
            ret[i] /= c;
        return ret;
    }

    // 多项式乘法（FFT 加速）：O(n log n)
    // 结果次数 = len + a_.len
    // 步骤：1. 补零到 2 的幂次  2. 正 FFT  3. 点值乘法  4. 逆 FFT  5. 除以 n 还原
    polymerization polymerization::operator*(const polymerization &a_) const
    {
        complex *a, *b;
        polymerization ret(len + a_.len); // 结果多项式的次数

        // 找到大于 ret.len 的最小 2 的幂，作为 FFT 的变换长度
        int l = 1;
        while (l <= ret.len)
            l <<= 1;

        // 分配临时数组（长度为 l，多余位置自动为 0）
        a = new complex[l];
        b = new complex[l];

        // 拷贝系数到临时数组（未赋值部分默认为 0，new complex[l] 中使用默认构造）
        for (int i = 0; i <= len; i++)
            a[i] = data[i];
        for (int i = 0; i <= a_.len; i++)
            b[i] = a_[i];

        fft(a, l, 1); // 正变换：时域→点值
        fft(b, l, 1);
        for (int i = 0; i < l; i++)
            a[i] *= b[i]; // 点值对应相乘
        fft(a, l, -1);    // 逆变换：点值→时域

        // 逆 FFT 结果需除以变换长度 l 才能还原真实系数
        for (int i = 0; i <= ret.len; i++)
            ret[i] = a[i] / l;

        // ⚠️ Bug：应为 delete[] a; delete[] b;
        delete a;
        delete b;
        return ret;
    }

    // 多项式逆元：在模 x^(len+1) 意义下计算 g ≡ (*this)^(-1)
    // 使用 Newton 迭代法：g_new = 2·g - f·g²，每次迭代精度翻倍
    // 初始条件：g[0] = 1/f[0]，g[1] = -g[0]²·f[1]（手动处理前两项）
    polymerization polymerization::inverse() const
    {
        polymerization g(1), g1;
        g[0] = 1;
        g[0] /= data[0];               // g[0] = 1 / f[0]
        g[1] = -g[0] * g[0] * data[1]; // g[1] = -g[0]² · f[1]
        while (g.len <= len)           // 迭代直到精度覆盖原多项式次数
        {
            g1 = g * g;                                  // g²
            g = g * 2 - (*this * g1).resize(g.len << 1); // g = 2g - f·g²，截断到 2·len
        }
        return g.resize(len); // 截断到所需精度
    }

    // 翻转多项式系数：将 a_0 + a_1·x + ... + a_n·x^n 变为 a_n + a_{n-1}·x + ... + a_0·x^n
    // 用于多项式除法的转化（将高位对齐到低位方便求逆）
    polymerization &polymerization::reverse()
    {
        std::reverse(data, data + len + 1);
        return *this;
    }

    // 多项式除法：计算 *this / a（多项式整除，结果次数为 len - a.len）
    // 利用翻转技巧将除法转化为乘以逆元：
    //   设 f = q·a + r，翻转后低次项对应商，高次项对应余数
    //   翻转 f 和 a，在模 x^(deg_q+1) 意义下求逆，即得翻转后的商，再翻转回来
    polymerization polymerization::operator/(const polymerization &a) const
    {
        if (len < a.len) // 被除式次数更低，商为 0（此处直接返回 *this 不完全正确，应返回 0）
            return *this;
        polymerization k, ra(*this), rb(a);
        ra.reverse().resize(len - a.len);       // 翻转被除式并截断到商的次数
        rb.reverse().resize(len - a.len);       // 翻转除式并截断到商的次数
        k = ra * rb.inverse();                  // 翻转后的商 = 翻转 f × 翻转 a 的逆元
        return k.resize(len - a.len).reverse(); // 截断并翻转回得到真正的商
    }

    // 多项式取模：计算 *this mod a（余式次数 < a.len）
    // 利用 *this = (*this / a) * a + (*this % a) 反推余式
    polymerization polymerization::operator%(const polymerization &a) const
    {
        if (len < a.len) // 被除式次数更低，余式就是自身
            return *this;
        if (!a.len) // 除式为常数多项式（次数为 0）
        {
            // 常数多项式取模：余式为 0，此处返回商（疑似逻辑错误，余式应为 0）
            polymerization ret(0);
            ret[0] = data[0] / a[0];
            return ret;
        }
        // 余式 = f - (f/a)*a，截断到 a.len-1 次
        return (*this - *this / a * a).resize(a.len - 1);
    }
}
