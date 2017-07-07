#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<time.h>
#include<cstdlib>
#define C 201
#define N 550

using namespace std;

unsigned long long  a, b, mini;
int ct;
long long jl[N];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long random(long long n)
{
	return (long long)((double)rand() / RAND_MAX * n + 0.5);
}

long long multi(long long a, long long b, long long m)
{
	long long ret = 0;
	while (b > 0)
	{
		if (b & 1)
			ret = (ret + a) % m;
		b >>= 1;
		a = (a << 1) % m;
	}
	return ret;
}

long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
		{
			ans = multi(ans, a, m);
			b--;
		}
		b /= 2;
		a = multi(a, a, m);
	}
	return ans;
}

bool Witness(long long a, long long n)
{
	long long m = n - 1;
	int j = 0;
	while (!(m & 1))
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

bool miller_rabin(long long n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (!(n & 1))
		return false;
	for (int i = 1; i <= 15; i++)
	{
		long long a = random(n - 2) + 1;
		if (Witness(a, n))
			return false;
	}
	return true;
}

long long pollard_rho(long long n, int c)
{
	long long x, y, d, i = 1, k = 2;
	x = random(n - 1) + 1;
	y = x;
	while (1)
	{
		i++;
		x = (multi(x, x, n) + c) % n;
		d = gcd(y - x, n);
		if (1 < d && d < n)
			return d;
		if (y == x)
			return n;
		if (i == k)
		{
			y = x;
			k <<= 1;
		}
	}
}

void find(long long n, int k)
{
	if (n == 1)
		return;
	if (miller_rabin(n))
	{
		jl[++ct] = n;
		return;
	}
	long long p = n;
	while (p >= n)
		p = pollard_rho(p, k--);
	find(p, k);
	find(n / p, k);
}

int main(void)
{
	long long s;
	while (scanf("%lld", &s) != EOF)
	{
		srand(time(NULL));
		ct = 0;
		find(s, C);
		printf("%lld\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("%lld ", jl[i]);
		printf("\n");
	}
	return 0;
}