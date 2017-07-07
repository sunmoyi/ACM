#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define maxm 200010

using namespace std;

struct node {
	int u, v;
}edge[maxm];
int indegree[maxn];
int V, E;
int dp[maxn];

bool cmp(node a, node b)
{
	if (a.u != b.u)
		return a.u < b.u;
	else
		return a.v < b.v;
}

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &edge[i].u, &edge[i].v);
			if (edge[i].u > edge[i].v)
				swap(edge[i].u, edge[i].v);
			indegree[edge[i].u]++;
			indegree[edge[i].v]++;
		}
		sort(edge + 1, edge + 1 + E, cmp);

		for (int i = 1; i <= E; i++)
			dp[edge[i].v] = max(dp[edge[i].v], dp[edge[i].u] + 1);

		long long ans = 0;
		for (int i = 1; i <= V; i++)
			ans = max(ans, (dp[i] + 1) * (long long)indegree[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
