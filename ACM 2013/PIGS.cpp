#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1005
#define maxv 105
#define INF 0x3f3f3f3f

using namespace std;

int res[maxv][maxv];
int dis[maxv];
int n, source, sink, maxflow;
int pig[maxn];
int k[maxn];

int bfs()
{
	int k;
	queue<int> q;
	memset(dis, -1, sizeof(dis));
	dis[sink] = 0;

	q.push(sink);
	while (!q.empty())
	{
		k = q.front();
		q.pop();
		for (int i = 0; i <= n + 1; i++) 
		{
			if (dis[i] == -1 && res[i][k]) 
			{
				dis[i] = dis[k] + 1;
				q.push(i);
			}
		}
		if (k == source)
			return 1;
	}
	return 0;
}

int dfs(int cur, int cp)
{
	if (cur == sink)   
		return cp;

	int tmp = cp, t;
	for (int i = 0; i <= n + 1 && tmp; i++) 
	{
		if (dis[i] + 1 == dis[cur] && res[cur][i])
		{
			t = dfs(i, min(res[cur][i], tmp));
			res[cur][i] -= t;
			res[i][cur] += t;
			tmp -= t;
		}
	}
	return cp - tmp;
}

void dinic()
{
	maxflow = 0;
	while (bfs())
		maxflow += dfs(source, INF);
}

int main(void)
{
	int i, m, cnt, j, num;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		memset(k, 0, sizeof(k));
		memset(res, 0, sizeof(res));

		for (int i = 1; i <= m; i++)
			scanf("%d", &pig[i]);

		source = 0, sink = n + 1;
		for (i = 1; i <= n; i++) 
		{
			scanf("%d", &cnt);
			for (j = 1; j <= cnt; j++)
			{
				scanf("%d", &num);
				if (!k[num])
					res[source][i] += pig[num];
				else
					res[k[num]][i] = INF;

				k[num] = i;
			}
			scanf("%d", &num);
			res[i][sink] = num;
		}
		n = sink + 1;
		dinic();
		printf("%d\n", maxflow);
	}
	return 0;
}