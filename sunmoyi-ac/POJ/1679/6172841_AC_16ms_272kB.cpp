#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0xfffffff

using namespace std;

bool vis[maxn];
int lowc[maxn];
int pre[maxn];
int maxx[maxn][maxn];
bool used[maxn][maxn];
int ans;
int cost[maxn][maxn];

int prim(int n)
{
	int ans = 0;
	memset(vis, false, sizeof(vis));
	memset(maxx, 0, sizeof(maxx));
	memset(used, false, sizeof(used));
	vis[0] = true;
	pre[0] = -1;
	for (int i = 1; i<n; i++)
	{
		lowc[i] = cost[0][i];
		pre[i] = 0;
	}
	lowc[0] = 0;
	for (int i = 1; i<n; i++)
	{
		int minc = INF;
		int p = -1;
		for (int j = 0; j<n; j++)
			if (!vis[j] && minc>lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		if (minc == INF)return -1;
		ans += minc;
		vis[p] = true;
		used[p][pre[p]] = used[pre[p]][p] = true;
		for (int j = 0; j<n; j++)
		{
			if (vis[j])maxx[j][p] = maxx[p][j] = max(maxx[j][pre[p]], lowc[p]);
			if (!vis[j] && lowc[j]>cost[p][j])
			{
				lowc[j] = cost[p][j];
				pre[j] = p;
			}
		}
	}
	return ans;
}

int smst(int n)
{
	int Min = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cost[i][j] != INF && !used[i][j])
			{
				Min = min(Min, ans + cost[i][j] - maxx[i][j]);
			}
		}
	}
	if (Min == INF)
		return -1;
	else
		return Min;
}

int main(void)
{
	int T;
	int n, m;
	scanf_s("%d", &T);
	while (T--)
	{
		scanf_s("%d %d", &n, &m);
		int u, v, w;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					cost[i][j] = 0;
				else
					cost[i][j] = INF;
			}
		}
		while (m--)
		{
			scanf_s("%d %d %d", &u, &v, &w);
			u--, v--;
			cost[u][v] = cost[v][u] = w;
		}
		ans = prim(n);
		if (ans == -1)
			printf("Not Unique!\n");
		else if (ans == smst(n))
			printf("Not Unique!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}