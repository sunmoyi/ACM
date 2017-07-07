#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2505;
int edgenum, head[maxn];

struct node
{
	int from, to, val;
	int next;
}edge[maxn*maxn];

void init()
{
	edgenum = 0;
	memset(head, -1, sizeof(head));
}

void add(int a, int b, int c)
{
	node tp = { a,b,c,head[a] };
	edge[edgenum] = tp;
	head[a] = edgenum++;
}

void slove(int n, int st)
{
	int dist[maxn], vis[maxn] = { 0 }, num[maxn] = { 0 };
	memset(dist, inf, sizeof(dist));
	vis[st] = 1; num[st] = 1; dist[st] = 0;
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dist[v]>dist[u] + edge[i].val)
			{
				dist[v] = dist[u] + edge[i].val;
				if (!vis[v])
				{
					vis[v] = 1; ++num[v];
					q.push(v);
					if (num[v]>n)//负环 
					{
						printf("YES\n");
						return;
					}
				}
			}
		}
	}
	printf("NO\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, w;
		scanf("%d%d%d", &n, &m, &w);
		init();
		for (int i = 0; i<m + w; ++i)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			i<m ? add(a, b, c), add(b, a, c) : add(a, b, -c);
		}
		slove(n, 1);
	}
	return 0;
}