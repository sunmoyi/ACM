#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long exgcd(long long m, long long &x, long long n, long long &y)
{
	long long x1, y1, x0, y0;
	x0 = 1; y0 = 0;
	x1 = 0; y1 = 1;
	long long r = (m % n + n) % n;
	long long q = (m - r) / n;
	x = 0; y = 1;
	while (r)
	{
		x = x0 - q*x1; y = y0 - q*y1; x0 = x1; y0 = y1;
		x1 = x; y1 = y;
		m = n; n = r; r = m % n;
		q = (m - r) / n;
	}
	return n;
}

int main(void)
{
	//sd - tn = x - y;
	int tc;
	long long n, d, x, y, g, s, t, res;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%lld %lld %lld %lld", &n, &d, &x, &y);
		x = (y - x + n) % n;//在这里将上式转化成了 sd - tn = x
		g = exgcd(d, s, n, t);
		if ((x % g) != 0)
		{
			printf("Impossible\n");
			continue;
		}
		long long k = n / g;
		s = s*(x / g);
		s = (s % k + k) % k;
		printf("%lld\n", s);
	}
	return 0;
}