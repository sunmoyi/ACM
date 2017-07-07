#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long mo;
long long p[100][2];
int k;

long long gcd(long long a, long long b)
{
	if (b > a)
	{
		long long temp = a;
		a = b;
		b = temp;
	}
	return b == 0 ? a : gcd(b, a%b);
}

long long mul(long long a, long long b)
{
	long long n = 0;
	while (b)
	{
		if (b & 1)
			n = (n + a) % mo;
		a = a * 2 % mo;
		b >>= 1;
	}
	return n;
}

long long mul(long long x)
{
	long long n = 1, m = 10;
	while (x > 0)
	{
		if (x & 1)
			n = mul(n, m);
		m = mul(m, m);
		x >>= 1;
	}
	return n;
}

long long phi(long long n)
{
	long long rea = n;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			rea = rea - rea / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		rea = rea - rea / n;
	return rea;
}

void fen(long long n)
{
	k = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			p[k][0] = i;
			p[k][1] = 0;
			while (n % i == 0)
			{
				p[k][1]++;
				n /= i;
			}
			k++;
		}
	}
	if (n > 1)
	{
		p[k][0] = n;
		p[k][1] = 1;
		k++;
	}
}

int main(void)
{
	int ncase = 0;
	while (scanf("%lld", &mo) != EOF && mo)
	{
		printf("Case %d:", ++ncase);
		mo = mo * 9 / gcd(mo, 8);
		//printf("%lld\n", mo);
		if (gcd(mo, 10) != 1)
		{
			printf(" 0\n");
			continue;
		}
		long long kk = phi(mo);
		fen(kk);
		for (int i = 0; i < k; i++)
		{
			for (int j = 1; j <= p[i][1]; j++)
			{
				if (mul(kk / p[i][0]) == 1)
					kk /= p[i][0];
			}
		}
		printf(" %lld\n", kk);
	}
	return 0;
}