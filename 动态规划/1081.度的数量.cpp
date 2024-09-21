/**
* ��Ŀ��
* ���������[X,Y]�������������������������������ǡ�õ���K��������ȵ�B����������֮�͡�
* ���磺��X=15��Y=20��K=2��B=2�������ҽ��������������������⣺
* 17=2^4+2^0
* 18=2^4+2^1
* 20=2^4+2^2
* 
* �����ʽ��
* ��һ�а�����������X��Y�����������а�������K��B
* 
* �����ʽ��
* ֻ����һ����������ʾ�������������ĸ���
* 
* ���ݷ�Χ��
* 1��X��Y��2^31-1
* 1��K��20
* 2��B��10
*/

/*
  ��λdp:
  1.[X,Y]=>f(Y)-f(X-1)
  2.�������ķ�ʽ���з�������
*/


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int N = 35;
int K, B;
int f[N][N];     //f[a][b]��ʾ��a����ѡb�ķ�����

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
	//�ж��������
	if (!n) return 0;   //��nΪ0ʱ�������ڶ�Ӧ����
	vector<int> nums;
	while (n)
	{
		nums.push_back(n % B);   //��nת��ΪB���Ƶ���ʽ����nums��
		n /= B;
	}

	int res = 0;
	int last = 0;    //last��ʾ֮ǰ�ж��ٸ�1
	for (int i = nums.size() - 1; i >= 0; i--) {
		int x = nums[i];
		if (x)    //����߷�֧�����ĸ���
		{
			res += f[i][K - last];
			if (x > 1) {
				if(K-last-1>=0) res += f[i][K - last - 1];
				break;
			}
			else {    //�����Ҳ��֧��last����
				last++;
				if (last > K) break;
			}
		}

		if (!i&&last==K) {    //���Ҳ��֧�ϵķ��� 
			//last==K�ж��Ҳ��֧�ϵ����Ƿ�Ϸ�
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