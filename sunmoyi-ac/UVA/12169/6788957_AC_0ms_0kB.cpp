#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 10001

using namespace std;

long long f[mod];

void exgcd(long long  a, long long  b, long long  &d, long long  &x, long long  &y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
		return;
	}
	else
	{
		exgcd(b, a % b, d, y, x);
		y -= x * (a / b);
		return;
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= 2 * t; i += 2)
		scanf("%lld", &f[i]);
	for (int a = 0; a < 10001; a++)
	{
		long long k, b, d;
		long long  c = (f[3] - a * a * f[1]);
		exgcd(mod, a + 1, d, k, b);
		if (c % d)
			continue;
		b = b * c / d;
		int flag;
		for (int i = 2; i <= 2 * t; i++)
		{
			flag = 1;
			int tmp = (a*f[i - 1] + b) % mod;
			if (i % 2)
			{
				if (tmp != f[i])
				{
					flag = 0;
					break;
				}
			}
			else
				f[i] = tmp;
		}
		if (flag)
			break;

	}
	for (int i = 2; i <= 2 * t; i += 2)
		printf("%lld\n", f[i]);
	return 0;
}