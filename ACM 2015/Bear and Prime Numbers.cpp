#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000010

using namespace std;

int n, m, v[maxn], g[maxn], s[maxn];

void init()
{
	memset(v, 0, sizeof(v));
	memset(g, 0, sizeof(g));
	memset(s, 0, sizeof(s));

	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		g[a]++;
	}

	for (int i = 2; i < maxn; i++)
	{
		if (v[i])
			continue;
		else
		{
			for (int j = i; j < maxn; j += i)
			{
				if (g[j])
					s[i] += g[j];
				v[j] = 1;
			}
		}
	}
	for (int i = 1; i < maxn; i++)
		s[i] += s[i - 1];
}

void solve()
{
	int a, b;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (a >= maxn)
			a = maxn;
		if (b >= maxn)
			b = maxn - 1;
		printf("%d\n", s[b] - s[a - 1]);
	}
}

int main(void)
{
	init();
	solve();
	return 0;
}