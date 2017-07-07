#include<cstdio>
#include<cstring>
//#include<algorithm>
#define INF 9999999999

using namespace std;

long long abs(long long x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

void ex_gcd(long long a, long long b, long long &x, long long &y, long long &d)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		ex_gcd(b, a % b, y, x, d);
		y -= x * (a / b);
	}
}

int main(void)
{
	long long a, b, c, sub, d;
	while (scanf("%lld %lld %lld", &a, &b, &c) != EOF && (a + b + c))
	{
		bool ifsub = false;
		if (a < b)
		{
			ifsub = true;
			sub = a;
			a = b;
			b = sub;
		}
		long long x0, y0;
		ex_gcd(a, b, x0, y0, d);
		x0 = x0 * (c / d);
		y0 = y0 * (c / d);
		long long t = (y0)* d / a;
		long long min = INF, ans, anst;
		for (long long i = t - 10; i <= t + 10; i++)
		{
			if (abs(x0 + b / d * i) + abs(y0 - a / d * i) < min)
			{
				ans = a * abs(x0 + b / d * i) + b * abs(y0 - a / d * i);
				anst = i;
				min = abs(x0 + b / d * i) + abs(y0 - a / d * i);
			}
			else if (abs(x0 + b / d * i) + abs(y0 - a / d * i) == min)
			{
				if (a * abs(x0 + b / d * i) + b * abs(y0 - a / d * i) < ans)
				{
					ans = a * abs(x0 + b / d * i) + b * abs(y0 - a / d * i);
					anst = i;
					min = abs(x0 + b / d * i) + abs(y0 - a / d * i);
				}
			}
		}
		if (!ifsub)
			printf("%lld %lld\n", abs(x0 + b / d * anst), abs(y0 - a / d * anst));
		else
			printf("%lld %lld\n", abs(y0 - a / d * anst), abs(x0 + b / d * anst));
	}
	return 0;
}