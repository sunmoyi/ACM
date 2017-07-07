#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

int e, n, m, s, t, head[maxn], nextt[maxn], cost[maxn], a[maxn], b[maxn], to[maxn], dist[maxn];
bool vis[maxn];

void addedge(int u, int v, int c, int sa, int sb)
{
	to[e] = v;
	nextt[e] = head[u];
	cost[e] = c;
	a[e] = sa;
	b[e] = sb;
	head[u] = e++;
}

int spfa(int st, int des)
{
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;
	memset(vis, 0, sizeof(vis));
	queue<int>Q;
	Q.push(st);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = nextt[i])
		{
			int v = to[i];
			int val = dist[u], s = dist[u];
			val = val % (a[i] + b[i]);
			if (val>a[i])
				s += b[i] - (val - a[i]);
			else if (a[i] - val<cost[i])
				s += b[i] + a[i] - val;
			if (s + cost[i]<dist[v])
			{
				dist[v] = s + cost[i];

				if (!vis[v])
				{
					Q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dist[des];
}

int main(void)
{
	int Case = 1;
	while (scanf("%d %d %d %d ", &n, &m, &s, &t) != EOF)
	{
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 0; i < m; i++)
		{
			int u, v, a, b, t;
			scanf("%d %d %d %d %d", &u, &v, &a, &b, &t);
			if (a >= t)
				addedge(u, v, t, a, b);
		}
		printf("Case %d: %d\n", Case++, spfa(s, t));
	}
	return 0;
}