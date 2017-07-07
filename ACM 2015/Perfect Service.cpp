/*#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
const int maxn = 10010;

using namespace std;

vector<int> g[maxn];
int d[maxn][3];
int vis[maxn];

int dp(int u) 
{
	vis[u] = 1;
	d[u][0] = 1, d[u][1] = 0, d[u][2] = maxn;
	queue<int> q;
	for (int i = 0; i < g[u].size(); ++i)
	{
		if (!vis[g[u][i]])
		{
			dp(g[u][i]);
			q.push(g[u][i]);
			d[u][0] += min(d[g[u][i]][0], d[g[u][i]][1]);
			d[u][1] += d[g[u][i]][2];
		}
	}
	while (!q.empty())
	{
		d[u][2] = min(d[u][2], d[u][1] - d[q.front()][2] + d[q.front()][0]);
		q.pop();
	}
	return 0;
}
 
int main() 
{
	int n;
	while (~scanf("%d", &n) && n != -1)
	{
		if (!n) continue;
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i<n; ++i)
		{
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dp(1);
		printf("%d\n", min(d[1][0], d[1][2]));
	}
	return 0;
}*/