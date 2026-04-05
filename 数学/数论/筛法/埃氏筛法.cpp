#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> prime;
bool is_prime[N];

void Eratosthenes(int n)
{
    is_prime[0] = is_prime[1] = false; // 显然0和1都不是质数
    for (int i = 2; i <= n; i++)
        is_prime[i] = true; // 初始化所有数都是质数
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i); // 将质数加入数组
        }

        if ((long long)i * i > n)
            continue; // 防止溢出

        /*
             因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i的倍数开始，提高了运行速度
         */
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false; // 将所有i的倍数标记为合数
    }
}

int main()
{
    Eratosthenes(100);

    return 0;
}