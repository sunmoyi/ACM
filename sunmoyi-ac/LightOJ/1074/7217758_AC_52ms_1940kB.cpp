#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 210
#define INF 0x3f3f3f3f

using namespace std;

int dis[maxn];
int p[maxn];
int h[maxn];
int cnt[maxn];
bool vis[maxn], r[maxn];
int c[maxn];

struct node {
	int u, v, w, next;
}e[maxn * maxn];

void dfs(int x)
{
	r[x] = 1;
	for (int i = h[x]; i != -1; i = e[i].next)
		if (!r[e[i].v])
			dfs(e[i].v);
}

void Dijkstra(int n)
{
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	memset(r, 0, sizeof(r));
	memset(dis, INF, sizeof(dis));
	queue<int>Q;
	Q.push(1);
	dis[1] = 0;
	vis[1] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		vis[now] = false;
		Q.pop();
		for (int i = h[now]; i != -1; i = e[i].next)
		{
			int v = e[i].v;
			if (r[v])
				continue;
			if (dis[v] > dis[now] + e[i].w)
			{
				dis[v] = dis[now] + e[i].w;
				if (!vis[v])
				{
					vis[v] = 1;
					Q.push(v);
					if (++cnt[v] >= n)
						dfs(v);
				}
			}
		}
	}
	int q, k;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &k);
		if (dis[k] == INF || dis[k] < 3 || r[k])
			printf("?\n");
		else
			printf("%d\n", dis[k]);
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++)
	{
		int n, m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		scanf("%d", &m);
		memset(h, -1, sizeof(h));
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			e[i].u = a;
			e[i].v = b;
			e[i].w = (p[b] - p[a]) * (p[b] - p[a]) * (p[b] - p[a]);
			e[i].next = h[a];
			h[a] = i;
		}
		printf("Case %d:\n", Case);
		Dijkstra(n);
	}
	return 0;
}