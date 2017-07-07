#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, v, x, y;
int par[1005];
int rankk[1005];
int a[1005];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != par[far])
		far = par[far];

	int i = x;
	while (par[i] != far)
	{
		int temp = par[i];
		par[i] = far;
		i = temp;
	}
	return far;
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rankk[x] < rankk[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rankk[y] == rankk[x])
		{
			rankk[x]++;
		}
	}
}

int main(void)
{
	while (scanf("%d", &v) != EOF)
	{
		while (v--)
		{
			scanf("%d %d", &n, &m);
			memset(rankk, 0, sizeof(rankk));
			memset(a, 0, sizeof(a));
			init(n);
			for (int i = 1; i <= m; i++)
			{
				scanf("%d %d", &x, &y);
				unite(x, y);
			}
			for (int i = 1; i <= n; i++)
			{
				a[find(i)] = 1;
			}
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1)
					ans++;
			}
			printf("%d\n", ans);

		}
	}
	return 0;
}