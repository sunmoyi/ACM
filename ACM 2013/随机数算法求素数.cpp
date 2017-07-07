#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans * a) % m;
			b--;
		}
		b /= 2;
		a = a * a % m;
	}
	return ans;
}
bool witness(long long  a, long long n)
{
	long long m = n - 1;
	int j = 0;
	while (!(m & 1))   //����n-1 = d*(2^r)��ת��
	{
		j++;
		m >>= 1;
	}
	long long x = quick_mod(a, m, n);
	if (x == 1 || x == n - 1)
		return false;
	while (j--)
	{
		x = x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}


bool miller_rabin(__int64 n)
{
	if (n == 2)    return true;
	if (n == 1 || ((n & 1) == 0))    return false;
	for (int i = 0; i<10; i++)//������ɴ���Ϊ50�Σ��ô�����ô�������漰һЩ���ʷ����ʵ�飬�����ﲻ��չ�������������Ժ��������㷨�����������з�����
	{
		__int64 a = rand()*(n - 2) / RAND_MAX + 1; //���������a��֤a<n
		if (witness(a, n))    return false;
	}
	return true;
}
int main()
{
	long long  n, cnt;
	while (scanf_s("%lld", &n) != EOF)
	{
		cnt = 0;
		int a = 0;
		double b = 0;
		for (long long i = 1; i <= n; i++)
		{
			if (miller_rabin(i))
				cnt++;
			a++;
			if (a == 897949)
			{
				printf("%.1lf%%\n", b += 0.1);
				a = 0;
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}