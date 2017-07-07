#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long LL;

using namespace std;

LL e_gcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL ans = e_gcd(b, a%b, x, y);
	LL temp = x;
	x = y;
	y = temp - a / b*y;
	return ans;
}

LL cal(LL a, LL b, LL c)
{
	LL x, y;
	LL gcd = e_gcd(a, b, x, y);
	if (c%gcd != 0) return -1;
	x *= c / gcd;
	b /= gcd;
	if (b<0) b = -b;
	LL ans = x%b;
	if (ans <= 0) ans += b;
	return ans;
}

int main(void)
{
	int ans, n, d, x, y;
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d %d %d", &n, &d, &x, &y);
			LL kk = cal(d, n, (y - x + n) % n);
			if (kk == -1)
				printf("NO\n");
			else
				printf("%lld\n", kk);
		}
	}
	return 0;
}