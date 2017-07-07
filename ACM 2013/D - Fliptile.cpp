#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define INF 0xfffffff
#define ll long long
#define N 20

int n, m;
int res;
int mpt[N][N];  //原始状态
int ans[N][N];  //保存答案
int tmp[N][N];  //翻转模拟数组
int vis[N][N];  //记录是否翻转

void flip(int i, int j)
{
	tmp[i][j] ^= 1;
	if (i - 1 >= 0) 
		tmp[i - 1][j] ^= 1;
	if (i + 1 < n) 
		tmp[i + 1][j] ^= 1;
	if (j - 1 >= 0) 
		tmp[i][j - 1] ^= 1;
	if (j + 1 < m) 
		tmp[i][j + 1] ^= 1;
}

int solve()
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i - 1][j])
			{
				flip(i, j);
				vis[i][j] = 1;
			}
		}
	}
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			time += vis[i][j];
			if (tmp[i][j]) 
				return INF;
		}
	}
	return time;
}
int main()
{
	int i, j, k;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		res = INF;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf_s("%d", &mpt[i][j]);
			}
		}
		int MAX = 1 << m;
		for (k = 0; k < MAX; k++)  //枚举第一行的状态
		{
			memset(vis, 0, sizeof(vis));
			memcpy(tmp, mpt, sizeof(mpt));
			for (j = 0; j < m; j++)
			{
				if (k & (1 << j))
				{
					flip(0, j);
					vis[0][j] = 1;
				}
			}
			int time = solve();
			if (time < res)
			{
				res = time;
				memcpy(ans, vis, sizeof(vis));
			}
		}
		if (res == INF) cout << "IMPOSSIBLE\n";
		else
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (j) 
						cout << ' ';
					cout << ans[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}