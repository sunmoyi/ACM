#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define maxn 50050
#define INF 0xfffffff

using namespace std;

int n, m;
double l, r;
struct node {
	int v, w;
	int next;
}edge[2333333];
bool vis[maxn];
int mindist[maxn];
int cnt[maxn];
int head[maxn], tot;
int u, v, w, minn = INF, maxx = -INF;

void addedge(int u, int v, int w)
{
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool Dijkstra()
{
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for (int i = minn - 1; i <= maxx + 1; i++)
		mindist[i] = -INF;
	mindist[minn] = 0;
	vis[minn] = true;
	cnt[minn]++;
	queue<int>Q;
	Q.push(minn);
	while (!Q.empty())
	{
		int u = Q.front();
		vis[u] = false;
		Q.pop();
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			int w = edge[i].w;
			if (mindist[v] < mindist[u] + w)
			{
				mindist[v] = mindist[u] + w;
				if (!vis[v])
				{
					vis[v] = true;
					Q.push(v);
					if (++cnt[v] >= sqrt((n + m) * 1.0))
						return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	minn = INF, maxx = -INF;
	while (scanf("%d", &n) != EOF)
	{
		tot = 0;
		memset(head, -1, sizeof(head));
		while (n--)
		{
			scanf("%d %d %d", &u, &v, &w);
			addedge(u, v + 1, w);
			minn = min(minn, u);
			maxx = max(maxx, v + 1);
		}
		for (int i = minn; i <= maxx; i++)
		{
			addedge(i, i + 1, 0);
			addedge(i + 1, i, -1);
		}
		Dijkstra();
		printf("%d\n", mindist[maxx]);
	}
	return 0;
}