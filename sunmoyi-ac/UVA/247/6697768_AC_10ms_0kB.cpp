#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

#define maxn 55

using namespace std;

vector<string>name;
int e[maxn][maxn];
bool vis[maxn];
int m, n;

int change(string s)
{
	for (int i = 0; i < name.size(); i++)
		if (name[i] == s)
			return i;
	name.push_back(s);
	return name.size() - 1;
}

void dfs(int u)
{
	vis[u] = true;
	for (int v = 0; v < n; v++)
	{
		if (!vis[v] && e[u][v] && e[v][u])
		{
			cout << ", " << name[v];
			dfs(v);
		}
	}
	return;
}

int main(void)
{
	int icase = 1;
	while(scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		memset(e, 0, sizeof(e));
		name.clear();
		while (m--)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int t1 = change(s1);
			int t2 = change(s2);
			e[t1][t2] = 1;
		}
		for (int i = 0; i < n; i++)
			e[i][i] = 1;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					e[i][j] = e[i][j] || (e[i][k] && e[k][j]);
				}
			}
		}
		if (icase)
			printf("\n");
		printf("Calling circles for data set %d:\n", icase++);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == 0)
			{
				cout << name[i];
				dfs(i);
				printf("\n");
			}
		}
	}
	return 0;
}