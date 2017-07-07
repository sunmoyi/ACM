#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<string.h>  
#define maxn 105  
using namespace std;
int map[maxn][maxn];
int vis[maxn];
int iToj[maxn][maxn];
int use[maxn][maxn];
int dis[maxn];
int pre[maxn];
int T, N, M;
int sum1, sum2;

int max1(int a, int b)
{
	return a>b ? a : b;
}

int prime1()
{
	sum1 = 0;
	memset(vis, 0, sizeof(vis));
	int k = 1;
	for (int i = 1; i <= N; i++)
	{
		vis[i] = 0;
		dis[i] = map[1][i];
		pre[i] = 1;
	}
	pre[1] = -1;
	vis[1] = 1;
	for (int i = 1; i<N; i++)
	{
		int mmin = 99999999;
		for (int j = 1; j <= N; j++)
		{
			if (!vis[j] && dis[j]<mmin)
			{
				mmin = dis[j];
				k = j;
			}
		}
		if (pre[k] != -1)
		{
			use[pre[k]][k] = use[k][pre[k]] = 1; 
			for (int j = 1; j <= N; j++)
			{
				if (vis[j])
					iToj[j][k] = max1(iToj[j][pre[k]], map[pre[k]][k]);  
			}
		}
		vis[k] = 1;
		sum1 += mmin;
		for (int j = 1; j <= N; j++)
		{
			if (!vis[j] && dis[j]>map[k][j])
			{
				dis[j] = map[k][j];
				pre[j] = k;
			}
		}
	}
	return sum1;
}
int prime2()
{
	sum2 = 99999999;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (use[i][j] == 2 && sum1 + map[i][j] - iToj[i][j]<sum2)
			{
				sum2 = sum1 + map[i][j] - iToj[i][j];
			}
		}
	return sum2;
}
int main()
{

	int a, b, c;
	int Max, Min;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i<maxn; i++)
			for (int j = 1; j<maxn; j++)
			{
				vis[i] = 0;
				map[i][j] = 99999999;
				iToj[i][j] = 0;
				use[i][j] = 0;
			}
		for (int i = 0; i<M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = c;
			map[b][a] = c;
			use[a][b] = use[b][a] = 2;
		}
		int  Max = prime1();
		int Min = prime2();
		printf("%d %d\n", Max, Min);
	}
	return 0;
}