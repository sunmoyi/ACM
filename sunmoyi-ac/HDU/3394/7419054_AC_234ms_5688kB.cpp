//
// Created by 孙启龙 on 2016/11/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define maxn 10010

using namespace std;

int n, m;
int ans1, ans2;
vector<int>G[maxn];
int dfs_clock, bcc_cnt;
int pre[maxn], low[maxn], bcc[maxn], bccno[maxn];

struct edge{
	int u, v;
	edge(int u = 0, int v = 0): u(u), v(v){}
};
stack<edge>S;

void solve()
{
	bool vis[maxn];
	int sum = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= bcc[0]; i++)
		vis[bcc[i]] = true;
	for(int i = 1; i <= bcc[0]; i++)
	{
		int u = bcc[i];
		for(int j = 0; j < G[u].size(); j++)
			if(vis[G[u][j]])
				sum++;
	}
	sum /= 2;
	if(sum > bcc[0])
		ans2 += sum;
}

void tarjan(int u, int fa)
{
	low[u] = pre[u] = ++dfs_clock;
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(v == fa)
			continue;
		edge e = edge(u, v);
		if(!pre[v])
		{
			S.push(e);
			tarjan(v, u);
			low[u] = min(low[v], low[u]);
			if(low[v] >= pre[u])
			{
				if(low[v] > pre[u])
					ans1++;
				bcc_cnt++;
				bcc[0] = 0;
				while(true)
				{
					edge x = S.top();S.pop();
					if(bccno[x.u] != bcc_cnt)
						bcc[++bcc[0]] = x.u, bccno[x.u] = bcc_cnt;
					if(bccno[x.v] != bcc_cnt)
						bcc[++bcc[0]] = x.v, bccno[x.v] =bcc_cnt;
					if(x.u == u && x.v == v)
						break;
				}
				solve();
			}
		}
		else if (pre[v] < pre[u])
		{
			S.push(e);
			low[u] = min(pre[v], low[u]);
		}
	}
}

int main (void)
{
	while(scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		ans1 = ans2 = bcc_cnt = dfs_clock = 0;
		memset(pre, 0, sizeof(pre));
		memset(bccno, 0, sizeof(bccno));
		for(int i = 0; i < n; i++)
			G[i].clear();
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 0; i < n; i++)
			if(!pre[i])
				tarjan(i, -1);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}