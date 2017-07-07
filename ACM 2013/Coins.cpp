#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
using namespace std;

const int MAX = 100000;
int dp[MAX];
int c[MAX], w[MAX];
int v;

void ZeroOnePack(int cost, int wei)//01  
{
	int i;
	for (i = v; i >= cost; i--)
	{
		dp[i] = max(dp[i], dp[i - cost] + wei);
	}
}

void CompletePack(int cost, int wei)//完全  
{
	int i;
	for (i = cost; i <= v; i++)
	{
		dp[i] = max(dp[i], dp[i - cost] + wei);
	}
}

void MultiplePack(int cost, int wei, int cnt)//多重  
{
	if (v <= cnt*cost)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包  
	{
		CompletePack(cost, wei);
		return;
	}
	else//否则就将多重背包转化为01背包  
	{
		int k = 1;
		while (k <= cnt)
		{
			ZeroOnePack(k*cost, k*wei);
			cnt = cnt - k;
			k = 2 * k;
		}
		ZeroOnePack(cnt*cost, cnt*wei);
	}
}

int main()
{
	int n;
	while (~scanf("%d%d", &n, &v), n + v)
	{
		int i;
		for (i = 0; i<n; i++)
			scanf("%d", &c[i]);
		for (i = 0; i<n; i++)
			scanf("%d", &w[i]);
		memset(dp, 0, sizeof(dp));
		for (i = 0; i<n; i++)
		{
			MultiplePack(c[i], c[i], w[i]);
		}
		int sum = 0;
		for (i = 1; i <= v; i++)
		{
			if (dp[i] == i)
			{
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}