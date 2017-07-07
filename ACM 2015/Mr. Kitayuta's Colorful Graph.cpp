#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 110

using namespace std;

struct node {
	int d, v;
	node(int d = 0, int v = 0) :d(d), v(v){}
};
vector<node>G[maxn];
int V, E;
int a, b, c;
int start, endd;
int vis[maxn];
int used[maxn];

void init()
{
	for (int i = 0; i <= E; i++)
		G[i].clear();
	memset(vis, false, sizeof(vis));
	memset(used, false, sizeof(used));
}

bool dfs(int x, int way)
{
	if (x == endd)
		return true;
	vis[x] = true;
	for (int i = 0; i < G[x].size(); i++)
	{
		if (G[x][i].v != way || vis[G[x][i].d])
			continue;
		if (dfs(G[x][i].d, way))
			return true;
	}
	return false;
}

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init();
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(node(b, c));
			G[b].push_back(node(a, c));
			used[c] = true;
		}
		int qu;
		scanf("%d", &qu);
		while (qu--)
		{
			scanf("%d %d", &start, &endd);
			int ans = 0;
			for (int i = 1; i <= E; i++)
			{
				memset(vis, false, sizeof(vis));
				if (used[i] && dfs(start, i))
					ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}