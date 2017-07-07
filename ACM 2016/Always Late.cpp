#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int mindist[maxn][maxn];
int nextt[maxn][maxn];
int n, m;
struct node {
	int v, len;
	node(int v = 0, int len = 0) : v(v), len(len){}
};
vector<node>G[maxn];

void init()
{
	memset(mindist, INF, sizeof(mindist));
	memset(nextt, INF, sizeof(nextt));
	for (int i = 0; i < maxn; i++)
	{
		G[i].clear();
		mindist[i][i] = 0;
	}
}

void floyed()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
}

void dfs(int s, int t, int u, int now)
{
	if (nextt[s][t] <= now + mindist[u][t])
		return;
	if (mindist[s][t] < now + mindist[u][t] && now + mindist[u][t] < nextt[s][t])
		nextt[s][t] = now + mindist[u][t];
	for (int i = 0; i < G[u].size(); i++)
	{
		dfs(s, t, G[u][i].v, now + G[u][i].len);
	}
}

int main(void)
{
	int Case = 1;
	int a, b, len, que;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			mindist[a][b] = mindist[b][a] = min(mindist[a][b], len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}


		floyed();


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mindist[i][j] != INF)
					dfs(i, j, i, 0);


		scanf("%d", &que);
		printf("Set #%d\n", Case++);
		while (que--)
		{
			scanf("%d %d", &a, &b);
			if (nextt[a][b] != INF)
				printf("%d\n", nextt[a][b]);
			else
				printf("?\n");
		}
	}
	return 0;
}