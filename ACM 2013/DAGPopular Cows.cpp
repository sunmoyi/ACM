#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 11000
#define maxm 55000
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int dfn[maxn];
int low[maxn];
int head[maxn], e;
int stack[maxn], top;
int instack[maxn];
int cnt;
int index;
int belong[maxn];
int out[maxn];

struct Edge {
	int to;
	int next;
}edge[maxm];

void addedge(int u, int v)
{
	edge[e].to = v;
	edge[e].next = head[u];
	head[u] = e++;
}

void init()
{
	cnt = 1;
	e = 0;
	int i, j;
	int u, v;
	memset(dfn, -1, sizeof(dfn));
	memset(low, -1, sizeof(low));
	memset(head, -1, sizeof(head));
	memset(instack, 0, sizeof(instack));
	memset(out, 0, sizeof(out));
	memset(belong, 0, sizeof(belong));
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		addedge(u, v);
	}
}

void tarjan(int u)
{
	int v, i;
	dfn[u] = low[u] = cnt++;;
	instack[u] = 1;
	stack[++top] = u;
	for (i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if (dfn[v] == -1)
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}

	if (low[u] == dfn[u])
	{
		index++;
		do{
			v = stack[top--];
			instack[v] = 0;
			belong[v] = index;
		} while (top != 0 && v != u);
	}
}

void solve()
{
	int i, j;
	int v;
	int num;
	int ans;
	int temp;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init();
		num = 0;
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			if (dfn[i] == -1)
				tarjan(i);
		}

		for (int i = 1; i <= n; i++)
		{
			for (v = head[i]; v != -1; v = edge[v].next)
			{
				if(belong[i] != belong[edge[v].to])
					out[belong[i]]++;
			}
		}

		for (i = 1; i <= index; i++)
		{
			if (!out[i])
			{
				num++;
				temp = i;
			}
		}

		if (num == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (belong[i] == temp)
					ans++;
			}
			printf("%d\n", ans);
		}
		else
			printf("0\n");
	}
}

int main(void)
{
	solve();
	return 0;
}