#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

vector<int>G[1000];
int match[1000];
bool used[1000];
int V;

void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_mathing()
{
	int res = 0;
	memset(match, 0, sizeof(match));
	for (int v = 0; v < V; v++)
	{
		if (match[v] < 0)
		{
			memset(used, 0, sizeof(used));
			if (dfs(v))
				res++;
		}
	}
	return res;
}