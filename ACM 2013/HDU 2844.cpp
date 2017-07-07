#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int v, f[100010], num[105], V[105];
int sum;

void ZeroOnePack(int cost, int weight)//cost 为费用， weight 为价值 
{
	for (int i = v; i >= cost; i--)
		if (f[i - cost] + weight>f[i]) f[i] = f[i - cost] + weight;
}

void CompletePack(int cost, int weight)
{
	for (int i = cost; i <= v; i++)
		if (f[i - cost] + weight>f[i]) f[i] = f[i - cost] + weight;
}

void MultiplePack(int cost, int weight, int amount) // 花费   价值  数量
{
	if (cost*amount >= v) 
		CompletePack(cost, weight);
	else
	{
		for (int k = 1; k<amount;)
		{
			ZeroOnePack(k*cost, k*weight);
			amount -= k;
			k <<= 1;
		}
		ZeroOnePack(amount*cost, amount*weight);
	}
}

int main(void)
{
	while (scanf_s("%d %d", &sum, &v) != EOF && (sum + v))
	{
		for (int i = 0; i < sum; i++)
			scanf_s("%d", &V[i]);
		for (int i = 0; i < sum; i++)
			scanf_s("%d", &num[i]);

		memset(f, 0, sizeof(f));

		for (int i = 0; i < sum; i++)
		{
			MultiplePack(V[i], V[i], num[i]);
		}

		int ans = 0;
		for (int i = 1; i <= v; i++)
			if (f[i] == i)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}