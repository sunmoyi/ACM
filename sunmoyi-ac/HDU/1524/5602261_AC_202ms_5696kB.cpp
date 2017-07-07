#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[1005][1005];
int sg[1005];
int n;

int dfs(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool g[1005] = { 0 };
	for (int i = 0; i < n; i++)
	{
		if (map[x][i] == 1)
			g[dfs(i)] = 1;
	}
	for (int i = 0; ; i++)
		if (g[i] == 0)
			return sg[x] = i;
}

int main(void)
{

	while (scanf_s("%d", &n) != EOF)
	{
		memset(map, -1, sizeof(map));
		memset(sg, -1, sizeof(sg));
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf_s("%d", &k);
			if (k == 0)
				sg[i] = 0;
			for (int j = 1; j <= k; j++)
			{
				int s;
				scanf_s("%d", &s);
				map[i][s] = 1;
			}
		}
		int ans;
		while (scanf_s("%d", &ans) != EOF && ans)
		{
			int mm = 0, t;
			for (int i = 1; i <= ans; i++)
			{
				scanf_s("%d", &t);
				if (sg[t] = -1)
					mm ^= dfs(t);
				else
					mm ^= sg[t];
			}
			if (mm == 0)
				printf("LOSE\n");
			else
				printf("WIN\n");
		}
	}
}