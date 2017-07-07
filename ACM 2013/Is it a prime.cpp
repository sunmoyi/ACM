#include<cstdio>
#include<cstring>
#include<algorithm>
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
		b /= 2;
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
		b /= 2;
		a = multi(a, a, m);
	}
	return ans;
}

bool Miller_rabin(long long n)
{
	for (long i = 1; i <= N; i++)
	{
		long long a = random(n - 2) + 1;
		if (quick_mod(a, n - 1, n) != 1)
			return false;
	}
	return true;
}

int main(void)
{
	srand(time(NULL));
	long long n;
	while (scanf("%lld", &n) != EOF)
	{
		if (Miller_rabin(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}