#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

long long x, y, n, m, L, M, ar, br;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long x1, y1;
	long long gcd = exgcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}

int main(void)
{
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L);
	M = exgcd((n - m), L, ar, br);
	if ((x - y) % M || n == m)
		printf("impossible\n");
	else
	{
		long long s = L / M;
		ar = ar * ((x - y) / M);
		ar = ((ar % s) + s) % s;
		printf("%lld\n", ar);
	}
	return 0;
}