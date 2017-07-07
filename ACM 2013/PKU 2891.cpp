#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (!b)
	{
		x = 1; y = 0; d = a;
	}
	else
	{
		ex_gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

int main(void)
{
	long long i, n, a1, r1, a2, r2, ans, a, b, c, d, x0, y0;
	while (scanf("%lld", &n) != EOF)
	{
		bool ifhave = true;
		scanf("%lld%lld", &a2, &r2);
		a = a1, b = a2, c = r1 - r2;
		ex_gcd(a, b, d, x0, y0);
		if (c % d != 0)
			ifhave = false;
		int t = b / d;
		x0 = (x0 * (c / d) % t + t) % t;
		r1 = a1 * x0 + r1;
		a1 = a1 * (a2 / d);
		if (!ifhave)
			printf("-1\n");
		else
			printf("%lld\n", r1);
	}
	return 0;
}