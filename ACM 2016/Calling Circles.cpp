#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#define maxn 35

using namespace std;

int n;
bool r[maxn][maxn], vis[maxn];
char s1[110], s2[110];
vector<string>names;

int ID(const string&s)
{
	for (int i = 0; i < names.size(); i++)
		if (names[i] == s)
			return i;
	names.push_back(s);
	return names.size() - 1;

}

void dfs(int u)
{
	vis[u] = true;
	for (int v = 0; v < n; v++)
	{
		if (!vis[v] && r[u][v] && r[v][u])
		{
			printf(", %s", names[v].c_str());
			dfs(v);
		}
	}
}

int main(void)
{
	int Case = 0, m;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		names.clear();
		memset(r, false, sizeof(r));
		if (Case)
			printf("\n");
		printf("Calling circles for data set %d:\n", ++Case);
		for (int i = 0; i < n; i++)
			r[i][i] = true;
		for (int i = 0; i < m; i++)
		{
			scanf("%s %s", s1, s2);
			r[ID(s1)][ID(s2)] = true;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				printf("%s", names[i].c_str());
				dfs(i);
				printf("\n");
			}
		}
	}
	return 0;
}