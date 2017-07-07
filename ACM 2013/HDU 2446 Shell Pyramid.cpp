#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long t, n, m, s, x;
long long sum[1000005];
long long sumi[1000005];

int find1(long long k)
{
	int l = 0, u = 1000000;
	while (l + 1< u)
	{
		int mid = (l + u) / 2;
		if (sum[mid] >= k)
			u = mid;
		else
			l = mid;
	}
	return u;
}

int find2(long long x)
{
	int l = 0, u = 1000000;
	while (l + 1< u)
	{
		int mid = (l + u) / 2;
		if (sumi[mid] >= x)
			u = mid;
		else
			l = mid;
	}
	return u;
}
int main(void)
{
	for (int i = 1; i <= 1000000; i++)
		sumi[i] = sumi[i - 1] + i;
	for (int i = 1; i <= 1000000; i++)
		sum[i] = sum[i - 1] + sumi[i];
	while (scanf_s("%lld", &t) != EOF)
	{
		while (t--)
		{
			scanf_s("%lld", &x);
			n = find1(x);
			x -= sum[n - 1];
			m = find2(x);
			x -= sumi[m - 1];
			printf("%lld %lld %lld\n", n, m, x);
		}
	}
	return 0;
}