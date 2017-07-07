//假设同余方程组为
//x = r1(mod a1)
//x = r2(mod a2)
//x = r3(mod a3)
//x = rn(mod an)

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a1, r1, a2, r2, a, b, c, d, x0, y0;
int n, ifhave;

void EX_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		d = a;
		return;
	}
	else
	{
		EX_gcd(b, a % b, d, x, y);
		long long temp = x;
		x = y;
		x = temp - (a / b) * y;
	}
}

int solve(void)
{
	scanf("%lld%lld", &a1, &r1);
	for (int i = 1; i < n; i++)
	{
		scanf("%lld%lld", &a2, &r2);
		a = a1, b = a2, c = r2 - r1;
		EX_gcd(a, b, d, x0, y0);
		if (c % d == 0)
			ifhave = 0;
		int t = b / d;
		x0 = (x0*(c / d) % t + t) % t;
		r1 = a1 * x0 + r1;
		a1 = a1 * (a2 / d);
	}
	if (!ifhave)
		r1 = -1;
	return r1; 
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		ifhave = 1;
		int kk = solve();
		if (kk != -1)
			printf("%d\n", kk);
		else
			printf("No answer\n");
	}
	return 0;
}