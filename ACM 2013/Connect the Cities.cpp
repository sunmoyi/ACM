#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;

int map[505][505];
int n, m, k, l, num, now, ans, minn;
bool flag[505];
int d[505];

void prim()
{
	for (int i = 1; i <= n; i++)
	{
		flag[i] = false;
		d[i] = INF;
	}
	d[1] = 0;
	flag[1] = true;
	now = 1;
	ans = 0;
	for (int i = 1; i < n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (!flag[q] && map[now][q] < d[q])
				d[q] = map[now][q];
		}
		minn = INF;
		for (int p = 1; p <= n; p++)
		{
			if (!flag[p] && d[p] < minn)
			{
				minn = d[p];
				now = p;
			}
		}
		flag[now] = true;
		ans += minn;
	}
}

int main(void)
{
	int a, b, c, d;
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
		{
			map[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
				map[i][j] = map[j][i] = INF;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (c < map[a][b])
				map[a][b] = map[b][a] = c;
		}
		int num[505];
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &a);
			for (int j = 1; j <= a; j++)
				scanf("%d", &num[j]);
			for (int s = 1; s <= a; s++)
				for (int ss = s + 1; ss <= a; ss++)
					map[num[s]][num[ss]] = map[num[ss]][num[s]] = 0;
		}
		prim();
		if (ans >= INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}