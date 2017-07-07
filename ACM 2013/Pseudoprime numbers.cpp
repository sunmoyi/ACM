#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

bool isprime(long long n)
{
	long long i;
	bool iffind = false;
	if (n == 2 || n == 1)
		return true;
	else
	{
		for (i = 2; i <= sqrt(n + 0.0); i++)
		{
			if (n % i == 0)
			{
				iffind = 1;
				break;
			}
		}
		if (iffind)
			return false;
		else
			return true;
	}
}

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

int main(void)
{
	long long n, a, p, b;
	while (scanf("%lld %lld", &p, &a) != EOF && (p + a))
	{
		if (isprime(p))
			printf("no\n");
		else
		{
			long long ans = 1;
			ans = quick_mod(a, p, p);
			if (ans == a)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}