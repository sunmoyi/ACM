//_CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1010
#define INF 0xfffffff
#define maxm 220000

using namespace std;

struct node {
	int v, w, next;
}edge[maxm];

int cnt[maxn];
int mindist[maxn];
bool vis[maxn];
int head[maxn], tot;
int n, m;

void addedge(int u, int v, int w)
{
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool spfa()
{
	queue<int>Q;
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i <= n; i++)
		mindist[i] = INF;
	mindist[0] = 0;
	Q.push(0);
	vis[0] = true;
	cnt[0]++;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			int w = edge[i].w;
			if (mindist[v] > mindist[u] + w)
			{
				mindist[v] = mindist[u] + w;
				if (!vis[v])
				{
					Q.push(v);
					vis[v] = true;
					cnt[v]++;
					if (cnt[v] > n)
						return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	char str; int u, v, w;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		tot = 0;
		memset(head, -1, sizeof(head));
		for (int i = 1; i <= m; i++)
		{
			getchar();
			scanf("%c", &str);
			if (str == 'P')
			{
				scanf("%d %d %d", &u, &v, &w);
				addedge(v, u, w);
				addedge(u, v, -w);
			}
			else
			{
				scanf("%d %d", &u, &v);
				addedge(u, v, -1);
			}
		}
		for (int i = 0; i <= n; i++)
		{
			addedge(0, i, 0);
		}
		if (!spfa())
			printf("Unreliable\n");
		else
			printf("Reliable\n");
	}
	return 0;
}