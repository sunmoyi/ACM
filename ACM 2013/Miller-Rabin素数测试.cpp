#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<time.h>

#define N 5

using namespace std;

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
		b >> 1;
		a = (a << 1) % m;
	}
	return ret;
}

long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = multi(ans, a, m);
			b--;
		}
		b >> 1;
		a = multi(a, a, m);
	}
}

bool Miller_ranbin(long long n)
{
	for (long i = 1; i <= n; i++)
	{
		long long a = random(n - 2) + 1;
		if (quick_mod(a, a - 1, n) != 1)
			return false;
	}
	return true;
}

int main(void)
{
	long long fin;
	while (scanf("%lld", &fin) != EOF)
	{
		if (Miller_ranbin(fin))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}