#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f

using namespace std;

vector<int>E[10010];
int dp[10010][3][4];
int n, c1, c2;

int fun(int u, int f, int type, int statu)
{
	if (dp[u][type][statu] != -1)
		return dp[u][type][statu];
	int re = 0;
	if (statu == 0)
	{
		re = INF;
		int temp = 0;
		for (int i = 0; i < E[u].size(); i++)
		{
			if (E[u][i] == f)
				continue;
			temp += min(min(fun(E[u][i], u, 0, 1), 
				fun(E[u][i], u, 1, 2)), 
				fun(E[u][i], u, 2, 3));
		}
		for (int i = 0; i < E[u].size(); i++)
		{
			if (E[u][i] == f)
				continue;
			re = min(re, temp - min(min(fun(E[u][i], u, 0, 1),
				fun(E[u][i], u, 1, 2)), 
				fun(E[u][i], u, 2, 3)) + fun(E[u][i], u, 2, 3));
		}
	}
	else
	{
		for (int i = 0; i<E[u].size(); i++) 
		{
			if (E[u][i] == f)
				continue;
			re += min(min(fun(E[u][i], u, 0, statu - 1),
				fun(E[u][i], u, 1, 2)),
				fun(E[u][i], u, 2, 3));
		}

		int tmp = 0;
		for (int i = 0; i<E[u].size(); i++)
		{
			if (E[u][i] == f)
				continue;
			tmp += min(min(fun(E[u][i], u, 0, 1),
				fun(E[u][i], u, 1, 2)),
				fun(E[u][i], u, 2, 3));
		}
		for (int i = 0; i<E[u].size(); i++) 
		{
			if (E[u][i] == f)
				continue;
			re = min(re, tmp - min(min(fun(E[u][i], u, 0, 1),
				fun(E[u][i], u, 1, 2)),
				fun(E[u][i], u, 2, 3)) + fun(E[u][i], u, 2, 3));
		}
	}
	if (type == 1)
		re += c1;
	if (type == 2)
		re += c2;
	dp[u][type][statu] = re;
	return re;
}

int main(void)
{
	while (scanf("%d %d %d", &n, &c1, &c2) != EOF && (n + c1 + c2))
	{
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++)
			E[i].clear();
		int u, v;
		for (int i = 1; i < n; i++)
		{
			scanf("%d %d", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		int ans = min(fun(1, -1, 0, 1), min(fun(1, -1, 1, 2), fun(1, -1, 2, 3)));
		printf("%d\n", ans);
	}
	return 0;
}