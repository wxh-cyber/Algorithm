/**
* 题目：
* 求给定区间[X,Y]中满足下列条件的整数个数：这个数恰好等于K个互不相等的B的整数次幂之和。
* 例如：设X=15，Y=20，K=2，B=2，则有且仅有下列三个数满足题意：
* 17=2^4+2^0
* 18=2^4+2^1
* 20=2^4+2^2
* 
* 输入格式：
* 第一行包含两个整数X和Y，接下来两行包含整数K和B
* 
* 输出格式：
* 只包含一个整数，表示满足条件的数的个数
* 
* 数据范围：
* 1≤X≤Y≤2^31-1
* 1≤K≤20
* 2≤B≤10
*/

/*
  数位dp:
  1.[X,Y]=>f(Y)-f(X-1)
  2.采用树的方式进行分类讨论
*/


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int N = 35;
int K, B;
int f[N][N];     //f[a][b]表示从a里面选b的方案数

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j) f[i][j] = 1;
			else f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
		}
	}
}

int dp(int n) 
{
	//判断特殊情况
	if (!n) return 0;   //当n为0时，不存在对应方案
	vector<int> nums;
	while (n)
	{
		nums.push_back(n % B);   //将n转化为B进制的形式存入nums中
		n /= B;
	}

	int res = 0;
	int last = 0;    //last表示之前有多少个1
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i];
		if (x)    //求左边分支中数的个数
		{
			res += f[i][K - last];
			if (x > 1) {
				if(K-last-1>=0) res += f[i][K - last - 1];
				break;
			}
			else {    //进入右侧分支，last自增
				last++;
				if (last > K) break;
			}
		}

		if (!i&&last==K) {    //最右侧分支上的方案 
			//last==K判断右侧分支上的数是否合法
			res++;
		}
	}
}

int main() {
	init();

	int l, r;
	cin >> l >> r >> K >> B;
	cout << dp(r) - dp(l - 1) << endl;
	return 0;
}