#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 15

using namespace std;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (!b)
	{
		x = 1, y = 0, d = a;
	}
	else
	{
		ex_gcd(b, a %b, d, y, x), y -= x * (a / b);
	}
}

long long aa[N], rr[N];

int main(void)
{
	long long n, m, a, b, c, d, x0, y0, lcm;
	int ncases, i;
	scanf_s("%d", &ncases);
	for (int k = 1; k <= ncases; k++)
	{
		scanf_s("%lld", &m);
		bool ifhave = true;
		lcm = 1;
		for (i = 1; i <= m; i++)
		{
			scanf_s("%lld", &aa[i]);
			lcm = lcm / gcd(aa[i], lcm) * aa[i];
		}
		for (i = 1; i <= m; i++)
			scanf_s("%lld", &rr[i]);
		printf("Case %d: ", k);
		for (i = 2; i <= m; i++)
		{
			a = aa[1], b = aa[i], c = rr[i] - rr[1];
			ex_gcd(a, b, d, x0, y0);
			if (c % d != 0)
			{
				ifhave = false;
				break;
			}
			long long t = b / d;
			x0 = (x0 * (c / d) % t + t) % t;
			rr[1] = aa[1] * x0 + rr[1];
			aa[1] = aa[1] * (aa[i] / d);
		}
		if (!ifhave)
		{
			printf("-1\n");
			continue;
		}
		if (rr[1] != 0)
		{
			printf("%lld\n", rr[1]);
			continue;
		}
		else
		{
			printf("%lld\n", lcm); 
		}
	}
	return 0;
}