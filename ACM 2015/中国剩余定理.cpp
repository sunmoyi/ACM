#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100

using namespace std;

int a[maxn], m[maxn], n;

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

int china(int r)
{
	long long M = 1;
	long long i, Mi, x0, y0, d, ans = 0;
	for (int i = 1; i <= r; i++)
		M *= m[i];
	for(int i = 1; i <= r; i++)
	{
		Mi = M / m[i];
		exgcd(Mi, m[i], d, x0, y0);
		ans = (ans + Mi * x0 * a[i]) % M;
	}
	while (ans <= 0)
		ans += M;
	return ans;
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &a[i], &m[i]);
		china(n);
	}
}