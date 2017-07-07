#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#define maxn 10000 + 10

using namespace std;

int n, m;
int ans1, ans2;
struct Edge {
	int u, v;
	Edge(int u = 0, int v = 0) :u(u), v(v) {}
}edgee[maxn * 100];
vector<int>G[maxn];//G 用来保存图
int dfs_clock, bcc_cnt, tot;
int pre[maxn], low[maxn], bcc[maxn], bccno[maxn];

struct edge {
	int u, v;
	edge(int u = 0, int v = 0) :u(u), v(v) {}
};

stack<edge>S;

void addedge(int u, int v)
{
	edgee[tot].v = v;
	edgee[tot].

}

void solve()
{
	bool vis[maxn];
	int sum = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= bcc[0]; i++)
		vis[bcc[i]] = true;
	for (int i = 1; i <= bcc[0]; i++)
	{
		int u = bcc[i];
		for (int j = 0; j<G[u].size(); j++)
			if (vis[G[u][j]]) //与u直接相连的点与u在同一个双连通分量中 那么这构成一个圈
				sum++;
	}
	sum /= 2;
	if (sum>bcc[0]) ans2 += sum;
}

void tarjan(int u, int fa)// 搜索u， 他的父节点是fa
{
	low[u] = pre[u] = ++dfs_clock;// u的最早时间和当前时间是dfs_clock
	for (int i = 0; i<G[u].size(); i++)//遍历和u相连的所有顶点
	{
		int v = G[u][i];
		if (v == fa) //如果是u的父节点直接继续
			continue;
		edge e = edge(u, v);
		if (!pre[v])//如果没有对这个点进行过搜索 那么向下深入
		{
			S.push(e);// e边压栈
			tarjan(v, u);//搜索节点v， 父节点是u
			low[u] = min(low[u], low[v]);//low[u]中保存的是与u相连的最早的节点， 每次搜索之后更新
			if (low[v] >= pre[u])
			{
				if (low[v]>pre[u]) ans1++;
				bcc_cnt++;
				bcc[0] = 0;
				while (true)
				{
					edge x = S.top(); S.pop();
					if (bccno[x.u] != bcc_cnt)//bcc_cnt双连通分量的标号
					{//bccno记录点属于哪个双连通分量
						bcc[++bcc[0]] = x.u, bccno[x.u] = bcc_cnt;
					}//bcc模拟栈 用来保存当前双连通分量中的点
					if (bccno[x.v] != bcc_cnt)
					{
						bcc[++bcc[0]] = x.v, bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v) break;
				}
				solve();
			}
		}
		else if (pre[v]< pre[u])
		{
			S.push(e);
			low[u] = min(pre[v], low[u]);
		}
	}
}

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF && (n + m))
	{
		ans1 = ans2 = bcc_cnt = dfs_clock = tot = 0;
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
