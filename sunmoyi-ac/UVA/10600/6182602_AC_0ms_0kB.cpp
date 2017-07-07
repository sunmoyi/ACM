#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<string.h>  
#define maxn 105  
#define INF 0xfffffff

using namespace std;

int cost[maxn][maxn];
bool vis[maxn];
int maxx[maxn][maxn];
bool used[maxn][maxn];
int lowc[maxn];
int pre[maxn];
int T, N, M;
int sum1, sum2;


int prime1()
{
	sum1 = 0;
	memset(vis, false, sizeof(vis));
	memset(maxx, 0, sizeof(maxx));
	memset(used, false, sizeof(used));
	int p = 1;
	for (int i = 1; i <= N; i++)
	{
		lowc[i] = cost[1][i];
		pre[i] = 1;
	}
	pre[1] = -1;
	vis[1] = true;
	for (int i = 1; i<N; i++)
	{
		int minc = INF;
		for (int j = 1; j <= N; j++)
		{
			if (!vis[j] && lowc[j]<minc)
			{
				minc = lowc[j];
				p = j;
			}
		}
		if (pre[p] != -1)
		{
			used[pre[p]][p] = used[p][pre[p]] = true; 
			for (int j = 1; j <= N; j++)
			{
				if (vis[j])
					maxx[j][p] = max(maxx[j][pre[p]], cost[pre[p]][p]);  
			}
		}
		vis[p] = true;
		sum1 += minc;
		for (int j = 1; j <= N; j++)
		{
			if (!vis[j] && lowc[j]>cost[p][j])
			{
				lowc[j] = cost[p][j];
				pre[j] = p;
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
			if (!used[i][j])
			{
				sum2 = min(sum1 + cost[i][j] - maxx[i][j], sum2);
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
				cost[i][j] = INF;
			}
		}
		for (int i = 0; i<M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			cost[a][b] = c;
			cost[b][a] = c;
		}
		int  Max = prime1();
		int Min = prime2();
		printf("%d %d\n", Max, Min);
	}
	return 0;
}