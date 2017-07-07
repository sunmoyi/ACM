#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n;

void exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		d = a;
		return;
	}
	else
	{
		exgcd(b, a % b, d, x, y);
		long long temp = x;
		x = y;
		y = temp - (a / b) * y;
	}
}

int solve()
{
	long long a1, r1, a2, r2, a, b, c, d, x0, y0;
	bool ifhave = true;
	scanf("%lld %lld", &a1, &r1);
	for (int i = 1; i < n; i++) 
	{
		scanf("%lld %lld", &a2, &r2);
		a = a1; b = a2; c = r2 - r1;
		exgcd(a, b, d, x0, y0);
		if (c % d != 0)
			ifhave = false;
		int t = b / d;
		x0 = (x0 * (c / d) % t + t) % t;
		r1 = a1 * x0 + r1;
		a1 = a1 * (a2 / d);
	}
	if (!ifhave)
		r1 = -1;
	return r1;
}

int main (void)
{
	cin >> n;
	solve();
}