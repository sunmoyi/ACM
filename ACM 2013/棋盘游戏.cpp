#include <iostream>
#include <cstdio>
using namespace std;
int M[105][105], k, m, n, match[505], vis[505], a[105], b[105];
int find(int s)
{
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i] && M[s][i + n + m])
		{
			vis[i] = 1;
			if (match[i] == -1 || find(match[i]))
			{
				match[i] = s;
				return 1;
			}
		}
	}
	return 0;
}
int max_match()
{
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		ans += find(i);
	}
	return ans;
}
void read_graph()
{
	for (int i = 0; i<k; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		M[a[i]][b[i] + m + n] = 1;
	}
}
int main()
{
	int cas = 1;
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		memset(M, 0, sizeof(M));
		read_graph();
		int ans = max_match();
		int cnt = 0;
		for (int i = 0; i<k; i++)
		{
			M[a[i]][b[i] + m + n] = 0;
			int res = max_match();
			M[a[i]][b[i] + m + n] = 1;
			if (ans>res)cnt++;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", cas++, cnt, ans);
	}
	return 0;
}