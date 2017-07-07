#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100100

using namespace std;

int node[maxn];
vector<int>G[maxn];

void init(int m)
{
	memset(node, 0, sizeof(node));
	for (int i = 0; i <= m + 1; i++)
		G[i].clear();
}

bool dfs(int i)
{
	if (G[i].size() == 0)
		return true;
	if (node[i] == 1 || node[i] == 0)
	{
		node[i] = 1;
		for (int j = 0; j < G[i].size(); j++)
		{
			if (node[G[i][j]] == 1)
				return false;
			else if (node[G[i][j]] == 2)
				continue;
			else
			{
				node[G[i][j]] = 2;
				if (!dfs(G[i][j]))
					return false;
			}
		}
	}
	if (node[i] == 2)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			if (node[G[i][j]] == 2)
				return false;
			else if (node[G[i][j]] == 1)
				continue;
			else
			{
				node[G[i][j]] = 1;
				if (!dfs(G[i][j]))
					return false;
			}
		}
	}
	return true;
}

int main(void)
{
	int n, m, a, b;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init(n + 1);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool flag = true;
		for (int i = 1; i <= n && flag; i++)
		{
			if (node[i] == 0)
				flag = dfs(i);
		}
		if (!flag)
		{
			printf("-1\n");
			continue;
		}
		int num1 = 0, num2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (node[i] == 1)
				num1++;
			else if (node[i] == 2)
				num2++;
		}
		if (num1 > num2)
		{
			int j = 1;
			printf("%d\n", num2);
			for (int i = 1; i <= n; i++)
			{
				if (node[i] == 2 && j < num2)
				{
					printf("%d ", i);
					j++;
				}
				else if (node[i] == 2 && j == num2)
				{
					printf("%d\n", i);
					j++;
				}
			}
			j = 0;
			printf("%d\n", num1);
			for (int i = 1; i <= n; i++)
			{
				if (node[i] == 1 && j < num1)
				{
					printf("%d ", i);
					j++;
				}
				else if (node[i] == 1 && j == num1)
				{
					printf("%d\n", i);
					j++;
				}
			}
		}
		else
		{
			int j = 1;
			printf("%d\n", num1);
			for (int i = 1; i <= n; i++)
			{
				if (node[i] == 1 && j < num1)
				{
					printf("%d ", i);
					j++;
				}
				else if (node[i] == 1 && j == num1)
				{
					printf("%d\n", i);
					j++;
				}
			}
			j = 0;
			printf("%d\n", num2);
			for (int i = 1; i <= n; i++)
			{
				if (node[i] == 2 && j < num2)
				{
					printf("%d ", i);
					j++;
				}
				else if (node[i] == 2 && j == num2)
				{
					printf("%d\n", i);
					j++;
				}
			}
		}
	}
	return 0;
}