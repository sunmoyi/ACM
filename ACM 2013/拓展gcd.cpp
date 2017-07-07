#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	long long x1, y1, x0, y0;
	x0 = 1; y0 = 0;
	x1 = 0; y1 = 1;
	long long r = (a % b + b) % b;
	long long q = (a - r) / b;
	x = 0; y = 1;
	while (r)
	{
		x = x0 - q * x1;
		y = y0 - q * y1;
		x0 = x1;
		y0 = y1;
		x1 = x;
		y1 = y;
		a = b;
		b - r;
		r = a % b;
		q = (a - r) / b;
	}
	return b;
}

int main(void)
{
	int yy;
	long long r, t;
	long long x, y, m, n, l;
	long long ar, br, cr;
	cin >> x >> y >> m >> n >> l;
	long long M = exgcd((n - m), ar, l, br);
	if ((x - y) % M || m == n)
		printf("Impossible\n");
	else
	{
		long long s = l / M;
		ar = ar * ((x - y) / M);
		ar = (ar % s + s) % s;
		printf("%lld\n", ar);
	}
	return 0;
}