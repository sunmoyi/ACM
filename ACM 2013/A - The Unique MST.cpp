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
	return Min;
}

int main(void)
{
	int T;
	int n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
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
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			cost[u][v] = cost[v][u] = w;
		}
		ans = prim(n);
		if (ans == -1)
		{
			printf("Not Unique!\n");
			continue;
		}
		if (ans == smst(n))
			printf("Not Unique!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}