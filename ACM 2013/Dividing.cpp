#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[7];
int f[10000000];
int v, k;

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

void MultiplePack(int cost, int weight, int amount)
{
	if (cost*amount >= v) CompletePack(cost, weight);
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
	int ans = 1;
	while (1)
	{
		int total = 0;
		for (int i = 1; i <= 6; i++)
		{
			scanf("%d", &a[i]);
			total += a[i] * i;
		}

		if (total == 0)
			break;
		else if (total % 2 == 1)
			printf("Collection #%d:\nCan't be divided.\n\n", ans++);
		else
		{
			v = total / 2;
			memset(f, 0, sizeof(f));
			for (int i = 1; i <= 6; i++)
			{
				MultiplePack(i, i, a[i]);
				if (f[v] = v)
					printf("Collection #%d:\nCan be divided.\n\n", ans++);
				else
					printf("Collection #%d:\nCan't be divided.\n\n", ans++);
			}
		}
	}
	return 0;
}