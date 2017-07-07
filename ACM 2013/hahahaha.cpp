#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0xfffffff

using namespace std;

bool vis[maxn];//
int lowc[maxn];
int pre[maxn];
int maxx[maxn][maxn];
bool used[maxn][maxn];
int cost[maxn][maxn];
int kk;

int prim(int n)
{
	int ans = 0;
	memset(vis, false, sizeof(vis));
	memset(used, false, sizeof(used));
	memset(maxx, 0, sizeof(maxx));
	for (int i = 1; i <= n; i++)
	{
		lowc[i] = cost[1][i];
		pre[i] = 1;
	}
	vis[1] = true;
	pre[1] = -1;
	for (int i = 1; i < n; i++)
	{
		int minc = INF;
		int p = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && minc > lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		}
		//if (minc == INF)
			//return -1;
		if (pre[p] != -1)
		{
			used[pre[p]][p] = used[p][pre[p]] = true;
			for (int j = 1; j <= n; j++)
			{
				if (vis[j])
					maxx[j][p] = max(maxx[j][pre[p]], cost[pre[p]][p]);
			}
		}
		vis[p] = true;
		ans += minc;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && lowc[j] > cost[p][j])
			{
				lowc[j] = cost[p][j];
				pre[j] = p;
			}
		}
	}
	return kk = ans;
}

int smst(int n)
{
	int Min = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (!used[i][j])
			{
				Min = min(Min, kk + cost[i][j] - maxx[i][j]);
			}
		}
	}
	return Min;
}

int main(void)
{
	int a, b, c, n, m;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				cost[i][j] = INF;
			}
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			cost[a][b] = c;
			cost[b][a] = c;
		}
		int ans1 = prim(n);
		int ans2 = smst(n);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}