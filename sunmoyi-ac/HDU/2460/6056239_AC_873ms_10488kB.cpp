#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define maxn 100000 + 10

using namespace std;

int pre[maxn], low[maxn], iscut[maxn], dfs_clock;
bool isbridge[maxn];
vector<int>G[maxn];
int cnt_bridge;
int father[maxn];
int a, b;

inline void init()
{
	memset(isbridge, false, sizeof(isbridge));
	memset(pre, 0, sizeof(pre));
	cnt_bridge = dfs_clock = 0;
	for (int i = 0; i < maxn; i++)
		G[i].clear();
}

void tarjan(int u, int fa)
{
	father[u] = fa;
	low[u] = pre[u] = ++dfs_clock;
	int son = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		if (!pre[v])
		{
			son++;
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
			if (low[v] > pre[u])
			{
				isbridge[v] = true;
				cnt_bridge++;
			}
		}
		else if (pre[v] < pre[u])
		{
			low[u] = min(pre[v], low[u]);
		}
	}
}

void LCA(int a, int b)
{
	while (pre[a] > pre[b])
	{
		if (isbridge[a])
		{
			isbridge[a] = false;
			cnt_bridge--;
		}
		a = father[a];
	}
	while (pre[b] > pre[a])
	{
		if (isbridge[b])
		{
			isbridge[b] = false;
			cnt_bridge--;
		}
		b = father[b];
	}
	if(a != b)
	{
		while (pre[a] > pre[b])
		{
			if (isbridge[a])
			{
				isbridge[a] = false;
				cnt_bridge--;
			}
			a = father[a];
		}
		while (pre[b] > pre[a])
		{
			if (isbridge[b])
			{
				isbridge[b] = false;
				cnt_bridge--;
			}
			b = father[b];
		}
	}
}

int main (void)
{
	int n, m, casee = 1;
	while (scanf_s("%d %d", &n, &m) != EOF && (n + m))
	{
		init();
		for (int i = 0; i < m; i++)
		{
			
			scanf_s("%d %d", &a, &b);
			G[a - 1].push_back(b - 1);
			G[b - 1].push_back(a - 1);
		}

		tarjan(0, -1);
		int Q;
		scanf_s("%d", &Q);
		printf("Case %d:\n", casee++);
		while (Q--)
		{
			scanf_s("%d %d", &a, &b);
			LCA(a - 1, b - 1);
			printf("%d\n", cnt_bridge);
			if (Q == 0)
				printf("\n");
		}
	}
	return 0;
}