#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int cost[maxn];
int V, E;
long long sum;

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF)
	{
		for (int i = 1; i <= V; i++)
			scanf("%d", &cost[i]);
		
		sum = 0;
		int a, b;
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &a, &b);
			sum += min(cost[a], cost[b]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}