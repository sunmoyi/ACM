#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<time.h>

using namespace std;

long long random(long long n)
{
	return (long long)((double)rand() / RAND_MAX * n + 0.5);
}

long long mutil(long long a, long long b, long long m)
{
	long long ret = 0;
	while(b > 0)
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
	while(b > 0)
	{
		if (b & 1)
		{
			b--;
			ans = mutil(ans, a, m);
		}
		b /= 2;
		a = mutil(a, a, m);
	}
	return ans;
}

bool witness(long long a, long long n)
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
	while(j--)
	{
		x = x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}

bool Miller_Rabin(long long n)
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
		if (witness(a, n))
			return false;
	}
	return true;
}

int main(void)
{
	long long a;
	while (scanf("%lld", &a) != EOF)
	{	
		srand(time(NULL));
		long long ans = 0;
		for (long long i = 2; i <= a; i++)
		{
			if (Miller_Rabin(i))
				ans++;
			if (i % 10000 == 0)
				printf("%lld\n", i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}