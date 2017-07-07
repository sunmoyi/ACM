#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 240

using namespace std;

int a[maxn][maxn];
int cap[maxn][maxn];
int lev[maxn];
int n, m;
int st, en;
int K, C, M;

bool bfs()
{
	queue <int> q;
	while (!q.empty()) q.pop();
	memset(lev, -1, sizeof(lev));
	lev[st] = 0;
	q.push(st);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v = 0; v <= n + 1; ++v)
			if (lev[v] == -1 && cap[u][v] != 0)
			{
				lev[v] = lev[u] + 1;
				q.push(v);
			}
	}
	return lev[en] != -1;
}
int dfs(int u, int cur_flow)
{
	int dt = cur_flow;
	if (u == en) return dt;
	for (int v = 0; v <= n + 1; ++v)
	{
		if (cap[u][v] > 0 && lev[u] + 1 == lev[v])
		{
			int flow = dfs(v, min(dt, cap[u][v]));
			cap[u][v] -= flow;
			cap[v][u] += flow;
			dt -= flow;
		}
	}
	return cur_flow - dt;
}

int dinic()
{
	int cur_flow, ans = 0;
	while (bfs())
		while (cur_flow = dfs(st, INF))
			ans += cur_flow;
	return ans;
}

void build(int dis)
{
	memset(cap, 0, sizeof(cap));
	n = K + C;
	st = 0;
	en = n + 1;
	for (int i = 1; i <= K; ++i)
		cap[0][i] += M;
	for (int i = K + 1; i <= K + C; ++i)
		cap[i][en] += 1;
	for (int i = 1; i <= K; ++i)
		for (int j = K + 1; j <= K + C; ++j)
			if (a[i][j] <= dis)
				cap[i][j] += 1;
}


void floyed()
{
	for (int k = 1; k <= K + C; k++)
	{
		for (int i = 1; i <= K + C; i++)
		{
			for (int j = 1; j <= K + C; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

int main(void)
{
	while (scanf("%d %d %d", &K, &C, &M) != EOF)
	{
		for (int i = 1; i <= K + C; i++)
		{
			for (int j = 1; j <= K + C; j++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j] == 0)
					a[i][j] = INF;
			}
		}

		floyed();
		
		int ans = 1, low = 1, high = 99999999;
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			build(mid);
			if (dinic() == C)
			{
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}