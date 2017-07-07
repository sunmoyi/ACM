#include<cstdio>

#include<cstring>
#define INF 1<<30
int map[110][110], n, m;
int vis[110], use[110][110], low[110];
int pre[110], F[110][110];
int max(int x, int y)
{
	return x>y ? x : y;
}
int prim(int s, int t)
{
	int ans = 0;
	memset(pre, -1, sizeof(pre));
	pre[s] = -1;
	memset(F, 0, sizeof(F));
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		low[i] = INF;
	}
	low[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = INF, tp = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && temp>low[j])
			{
				tp = j;
				temp = low[j];
			}
		if (tp == -1) continue;
		int k = tp;
		int v = pre[k];
		if (v != -1)
		{
			use[k][v] = use[v][k] = 2;
			for (int j = 1; j <= n; j++)
				if (vis[j])
					F[j][k] = max(F[j][v], map[v][k]);
		}
		vis[k] = 1;
		ans += low[k];
		for (int j = 1; j <= n; j++)
			if (!vis[j] && low[j]>map[k][j])
			{
				low[j] = map[k][j];
				pre[j] = k;
			}
	}
	return ans;
}
int second_mst(int x)
{
	int res = x, ans = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (use[i][j] == 1 && map[i][j] != INF&&F[i][j] != INF)
			{
				if (res + map[i][j] - F[i][j] < ans)
					ans = res + map[i][j] - F[i][j];
				//printf("%d.%d.\n",F[i][j],map[i][j]);
			}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				map[i][j] = INF;
		memset(use, 0, sizeof(use));
		int x, y, z;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			map[x][y] = map[y][x] = z;
			use[x][y] = use[y][x] = 1;
		}
		int ans = prim(1, n);
		int ans1 = second_mst(ans);
		printf("%d %d\n", ans, ans1);
	}
	return 0;
}