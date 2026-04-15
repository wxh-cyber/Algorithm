/*
    一维前缀和
    相关链接：https://oi-wiki.org/basic/prefix-sum/#一维前缀和
 */
#include <iostream>
#include <vector>
using namespace std;

int n;             // 数组大小
vector<int> a, ps; // a为数组，ps为前缀和数组

// 构造前缀和数组
void prefix_sum()
{
    ps = a; // 将a中的所有数据先转移到ps中
    // 也可以写成partial_sum(a.begin(),a.end(),ps.begin());
    for (int i = 1; i <= n; i++)
    {
        ps[i] += ps[i - 1]; // 计算前缀和
    }
}

// 查询区间[l,r]的和
int query(int l, int r)
{
    return ps[r] - ps[l - 1]; // 查询区间[l,r]的和
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    prefix_sum();
    cout << query(1, 3) << endl;

    return 0;
}