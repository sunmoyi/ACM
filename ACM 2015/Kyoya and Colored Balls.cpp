#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define mod 1000000007

using namespace std;

long long num[maxn];
long long fac[maxn * maxn];
long long n;

long long poww(long long a, long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

long long work(long long m, long long i)
{
	return ((fac[m] % mod) * (poww((fac[i] * fac[m - i]) % mod, mod - 2) % mod)) % mod;
}

int main(void)
{
	fac[0] = 1;
	for (int i = 1; i < maxn * maxn; i++)
		fac[i] = (fac[i - 1] * i) % mod;
	long long ans = 1, sum = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &num[i]);
		sum += num[i];
	}
	for (int i = n; i >= 1; i--)
	{
		ans *= work(sum - 1, num[i] - 1);
		ans %= mod;
		sum -= num[i];
	}
	printf("%lld\n", ans);
	return 0;
}