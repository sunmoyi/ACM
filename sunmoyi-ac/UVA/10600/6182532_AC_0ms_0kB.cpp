#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<string.h>  
#define maxn 105  
#define INF 0xfffffff

using namespace std;

int map[maxn][maxn];
int vis[maxn];
int maxx[maxn][maxn];
int used[maxn][maxn];
int dis[maxn];
int pre[maxn];
int T, N, M;
int sum1, sum2;


int prime1()
{
	sum1 = 0;
	memset(vis, 0, sizeof(vis));
	memset(maxx, 0, sizeof(maxx));
	memset(used, 0, sizeof(used));
	int k = 1;
	for (int i = 1; i <= N; i++)
	{
		dis[i] = map[1][i];
		pre[i] = 1;
	}
	pre[1] = -1;
	vis[1] = 1;
	for (int i = 1; i<N; i++)
	{
		int mmin = INF;
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
			used[pre[k]][k] = used[k][pre[k]] = true; 
			for (int j = 1; j <= N; j++)
			{
				if (vis[j])
					maxx[j][k] = max(maxx[j][pre[k]], map[pre[k]][k]);  
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
	sum2 = INF;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!used[i][j] && sum1 + map[i][j] - maxx[i][j] < sum2)
			{
				sum2 = sum1 + map[i][j] - maxx[i][j];
			}
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
		for (int i = 1; i < maxn; i++)
		{
			for (int j = 1; j < maxn; j++)
			{
				map[i][j] = INF;
			}
		}
		for (int i = 0; i<M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = c;
			map[b][a] = c;
		}
		int  Max = prime1();
		int Min = prime2();
		printf("%d %d\n", Max, Min);
	}
	return 0;
}