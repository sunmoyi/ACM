#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long maxx[100005];

long long gcd(long long a, long long b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

long long divide(long long n)
{
	memset(maxx, 0, sizeof(maxx));
	long long i, k = 0;
	for (int i = 2; i <= sqrt(double(n)); i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				maxx[k]++;
			}
			k++;
		}
	}
	if (n != 1)
	{
		maxx[k]++;
		k++;
	}
	return k;
}

int main(void)
{
	long long n;
	while (scanf_s("%lld", &n) && n != 0)
	{
		long long gc = 0, num;
		long long i;
		int flag = 0;
		if (n < 0)	
		{
			n = (-1) * n;
			flag = 1;
		}
		num = divide(n);
		for (int i = 0; i < num; i++)
			gc = gcd(gc, maxx[i]);
		if (flag)
		{
			while (gc % 2 == 0)
				gc /= 2;
		}
		printf("%lld\n", gc);
	}
	return 0;
}
