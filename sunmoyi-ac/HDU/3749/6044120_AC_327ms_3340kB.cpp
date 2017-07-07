#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define maxn 5050

using namespace std;

int n, m, q;
vector<int>G[maxn], bcc[maxn];
int dfs_clock, bcc_cnt;
int pre[maxn], low[maxn], bccno[maxn];
vector<int>belong[maxn];// the number of the bcc that node i belongs to;
int fa[maxn];

struct Edge {
	int u, v;
	Edge(int u, int v) :u(u), v(v) {}
};
stack<Edge>S;

void dfs(int u, int fa)
{
	low[u] = pre[u] = ++dfs_clock;
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		Edge e = Edge(u, v);
		if (!pre[v])
		{
			S.push(e);
			dfs(v, u);
			low[u] = min(low[v], low[u]);
			if (low[v] >= pre[u])
			{
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while (true)
				{
					Edge x = S.top(); S.pop();
					if (bccno[x.u] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u), bccno[x.u] = bcc_cnt;
						belong[x.u].push_back(bcc_cnt);
					}
					if (bccno[x.v] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v), bccno[x.v] = bcc_cnt;
						belong[x.v].push_back(bcc_cnt);
					}
					if (x.u == u && x.v == v)
						break;
				}
			}
		}
		else if (pre[v] < pre[u])
		{
			S.push(e);
			low[u] = min(low[u], pre[v]);
		}
	}
}

int find(int i)
{
	if (fa[i] == -1)
		return i;
	return fa[i] = find(fa[i]);
}

int main(void)
{
	int casee = 0;
	while (scanf_s("%d %d %d", &n, &m, &q) != EOF && n)
	{
		bcc_cnt = dfs_clock = 0;
		memset(pre, 0, sizeof(pre));
		memset(bccno, 0, sizeof(bccno));
		memset(fa, -1, sizeof(fa));
		for (int i = 0; i < n; i++)
			G[i].clear(), belong[i].clear();
		while (m--)
		{
			int u, v;
			scanf_s("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
			u = find(u), v = find(v);
			if (u != v)
				fa[u] = v;
		}
		for (int i = 0; i < n; i++)
			if (!pre[i])
				dfs(i, -1);
		printf("Case %d:\n", ++casee);
		while (q--)
		{
			int u, v;
			scanf_s("%d %d", &u, &v);
			if (find(u) != find(v))
				printf("zero\n");
			else
			{
				bool flag = false;
				for (int i = 0; i < belong[u].size() && !flag; i++)
				{
					for (int j = 0; j < belong[v].size() && !flag; j++)
					{
						if (belong[u][i] == belong[v][j])
						{
							int num = belong[u][i];
							if (bcc[num].size() > 2)
								printf("two or more\n"), flag = true;
						}
					}
				}
				if (!flag)
					printf("one\n");
			}
		}
	}
	return 0;
}