#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 2010

using namespace std;

vector<int>G[maxn];
int num, maxx;
bool vis[maxn];

void init()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= num; i++)
		G[i].clear();
}

void dfs(int x, int de)
{
	if (de > maxx)
		maxx = de;
	for (int i = 0; i < G[x].size(); i++)
		dfs(G[x][i], de + 1);
}

int main(void)
{
	int a;
	while (scanf("%d", &num) != EOF)
	{
		init();
		for (int i = 1; i <= num; i++)
		{
			scanf("%d", &a);
			if (a == -1)
				vis[i] = true;
			else
				G[a].push_back(i);
		}
		maxx = 1;
		for (int i = 1; i <= num; i++)
			if (vis[i])
				dfs(i, 1);
		printf("%d\n", maxx);
	}
	return 0;
}