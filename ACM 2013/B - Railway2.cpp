#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define maxn 100000 + 10

using namespace std;

int n, m;
int ans1, ans2;
vector<int>G[maxn];
int dfs_cnt, bcc_cnt;
int pre[maxn], low[maxn], bcc[maxn], bccno[maxn];

struct edge {
	int u, v;
	edge(int u = 0, int v = 0) :u(u), v(v) {}
};
stack<edge>S;

void solve()
{
	bool vis[maxn];
	int sum = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= bcc[0]; i++)
		vis[bcc[i]] = true;
	for (int i = 1; i <= bcc[0]; i++)
	{
		int u = bcc[i];
		for (int j = 0; j < G[u].size(); j++)
			if (!vis[G[i][j]])
				sum++;
	}
	sum /= 2;
	if (sum > bcc[0])
		ans2 += sum;
}

void tarjan(int u, int fa)
{

}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		ans1 = ans2 = bcc_cnt = dfs_cnt = 0;
		memset(pre, 0, sizeof(pre));
		memset(bccno, 0, sizeof(bccno));
		for (int i = 0; i < n; i++)
			G[i].clear();
		while (m--)
		{
			int u, v;
			scanf_s("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 0; i < n; i++)
			if (!pre[i])
				tarjan(i, -1);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}