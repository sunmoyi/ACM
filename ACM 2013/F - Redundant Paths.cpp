#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 5010
#define maxm 20010

using namespace std;

struct Edge {
	int to, next;
	bool cut;
}edge[maxm];
int head[maxn], tot;
int low[maxn], pre[maxn], belong[maxn], stack[maxn];
int index, top;
int block;
bool instack[maxn];
int bridge;

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].cut = false;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void tarjan(int u, int fa)
{
	int v;
	low[u] = pre[u] = ++index;
	stack[top++] = u;
	instack[u] = true;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if (v == fa)
			continue;
		if (!pre[v])
		{
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
			if (low[v] > pre[u])
			{
				bridge++;
				edge[i].cut = true;
				edge[i ^ 1].cut = true;
			}

		}
		else if (instack[v] && low[u] > pre[v])
			low[u] = pre[v];
	}
	if (low[u] == pre[u])
	{
		block++;
		do {
			v = stack[--top];
			instack[v] = false;
			belong[v] = block;
		} while (v != u);
	}
}

void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

int du[maxn];

void solve(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(instack, false, sizeof(instack));
	index = top = block = 0;
	tarjan(1, 0);
	int ans = 0;
	memset(du, 0, sizeof(du));
	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j != -1; j = edge[j].next)
		{
			if (edge[j].cut)
				du[belong[i]]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (du[i] == 1)
			ans++;
	printf("%d\n", (ans + 1)/2);
}

int main(void)
{
	int n, m;
	int u, v;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		init();
		while (m--)
		{
			scanf_s("%d %d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		solve(n);
	}
	return 0;
}