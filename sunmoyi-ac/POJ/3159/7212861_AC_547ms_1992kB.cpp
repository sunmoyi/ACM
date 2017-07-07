#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30010
#define maxm 150010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, len, next;
}edge[maxm];
int head[maxn];
int vis[maxn];
int Q[maxn];
int mindist[maxn];
int top, total;
int n, m;

void addedge(int u, int v, int len)
{
	edge[total].v = v;
	edge[total].len = len;
	edge[total].next = head[u];
	head[u] = total++;
}

void SPFA(int start, int endd)
{
	top = 0;
	for (int v = 1; v <= n; v++)
	{
		if (v == start)
		{
			Q[top++] = v;
			vis[v] = true;
			mindist[v] = 0;
		}
		else
		{
			vis[v] = false;
			mindist[v] = INF;
		}
	}
	while (top != 0)
	{
		int u = Q[--top];
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (mindist[v] > mindist[u] + edge[i].len)
			{
				mindist[v] = mindist[u] + edge[i].len;
				if (!vis[v])
				{
					vis[v] = true;
					Q[top++] = v;
				}
			}
		}
	}
}

int main(void)
{
	int a, b, c;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		total = 0;
		memset(head, -1, sizeof(head));
		while (m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
		}
		SPFA(1, n);
		printf("%d\n", mindist[n]);
	}
	return 0;
}