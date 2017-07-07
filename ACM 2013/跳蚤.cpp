#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 64

using namespace std;

int bo[N], t;
long long ans, temp;
int a[N], m, n;

void divide(int m)
{
	int i;
	t = 0;
	for (i = 2; i * i <= m; i++)
	{
		if (m % i == 0)
		{
			t++;
			bo[t] = i;
			while (m % i == 0)
				m /= i;
		}
	}
	if (m != 1)
	{
		t++;
		bo[t] = m;
	}
}

long long quick_multi(long long a, long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

void dfs(int b, int ct, int c)
{
	int i, x;
	if (ct == c)
	{
		x = m;
		for (int i = 1; i <= c; i++)
			x /= a[i];
		temp += quick_multi(x, n);
		return;
	}
	else
	{
		for (i = b + 1; i <= t; i++)
		{
			a[ct + 1] = bo[i];
			dfs(i, ct + 1, c);
		}
	}
}

int main(void)
{
	int i;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		t = 0;
		divide(m);
		ans = quick_multi(m, n);
		for (i = 1; i <= t; i++)
		{
			temp = 0;
			dfs(0, 0, i);
			if (i & 1)
				ans -= temp;
			else
				ans += temp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}