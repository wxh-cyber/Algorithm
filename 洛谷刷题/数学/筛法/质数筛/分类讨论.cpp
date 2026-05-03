/**
 *    @link https://www.luogu.com.cn/problem/P5736
 */
 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 判断是不是质数，如果是，存入brr，并返回新count
int judge(int num, int brr[], int count)
{
    // 情况1：小于等于1，不是质数
    if (num <= 1) {
        return count; // 不存，直接返回原count
    }
    // 情况2：等于2，是质数
    if (num == 2) {
        brr[count] = num;
        return count + 1;
    }
    // 情况3：偶数，不是质数
    if (num % 2 == 0) {
        return count;
    }
    // 情况4：判断奇数
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return count; // 能整除，不是质数
        }
    }

    // 能走到这里，说明是质数！
    brr[count] = num;
    return count + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    int* brr = (int*)malloc(n * sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        count = judge(arr[i], brr, count);
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", brr[i]);
    }

    free(arr);
    free(brr);
    return 0;
}