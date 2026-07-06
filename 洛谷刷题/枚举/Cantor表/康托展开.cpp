/**
 *  @link https://www.luogu.com.cn/problem/P1014
 */

 /**
  *  分析：这题本质上是“康托展开表”的对角线编号问题，没必要真的一格一格走。
  *  规律是：
  *     - 第 1 条对角线有 1 个数
  *     - 第 2 条对角线有 2 个数
  *     - 第 3 条对角线有 3 个数
  *     - ...
  *  所以先找到 n 落在第几条对角线，再看它是这条对角线里的第几个。
  */

  /**
   *  @note
   *    不用开二维数组
   *    不用模拟走格子
   *    时间复杂度 O(sqrt(n))
   *    空间复杂度 O(1)
   */

#include <iostream>
using namespace std;


int main() {
    long long n;
    cin >> n;

    long long diag = 1;   // 当前是第几条对角线
    long long sum = 1;    // 前 diag 条对角线一共有多少项

    while (sum < n) {
        diag++;
        sum += diag;
    }

    long long prev = sum - diag;   // 前 diag-1 条对角线总项数
    long long pos = n - prev;      // n 是当前对角线的第 pos 项

    long long x, y;
    if (diag % 2 == 0) {
        x = pos;
        y = diag - pos + 1;
    } else {
        x = diag - pos + 1;
        y = pos;
    }

    cout << x << "/" << y;
    return 0;
}