#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxm 20020
#define INF 0x3f3f3f3f

using namespace std;

int head[maxn];
int vis[maxn];
int cnt[maxn];
int que[maxn];
int dist[maxn];

struct edge {
	int to, v, next;
}edge[maxm];

int tol;

void addedge(int a, int b, int v)
{
	edge[tol].to = b;
	edge[tol].v = v;
	edge[tol].next = head[a];
	head[a] = tol++;
}

bool SPFA(int start, int n)
{
	int front = 0, rear = 0;
	for (int v = 1; v <= n; v++)
	{
		if (v == start)
		{
			que[rear++] = v;
			vis[v] = true;
			cnt[v] = 1;
			dist[v] = 0;
		}
		else
		{
			vis[v] = false;
			cnt[v] = 0;
			dist[v] = INF;
		}
	}
	while (front != rear)
	{
		int u = que[front++];
		vis[u] = false;
		if (front >= maxn)
			front = 0;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dist[v] > dist[u] + edge[i].v)
			{
				dist[v] = dist[u] + edge[i].v;
				if (!vis[v])
				{
					vis[v] = true;
					que[rear++] = v;
					if (rear >= maxn)
						rear = 0;
					if (++cnt[v] > n)
						return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	int n;
	int ml, md;
	int a, b, c;
	while (scanf("%d %d %d", &n, &ml, &md) != EOF)
	{
		tol = 0;
		memset(head, -1, sizeof(head));
		while (ml--)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a > b)
				swap(a, b);
			addedge(a, b, c);
		}
		while (md--)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a < b)
				swap(a, b);
			addedge(a, b, -c);
		}
		if (!SPFA(1, n))
			printf("-1\n");
		else if (dist[n] == INF)
			printf("-2\n");
		else
			printf("%d\n", dist[n]);
	}
	return 0;
}
