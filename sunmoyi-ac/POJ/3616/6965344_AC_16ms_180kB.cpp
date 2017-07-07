#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

struct node {
	int x, y, w;
}k[maxn];
int dp[maxn];

bool cmp(node a, node b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

int main (void)
{
	int n, m, r, ans;
	while (scanf("%d %d %d", &n, &m, &r) != EOF)
	{
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &k[i].x, &k[i].y, &k[i].w);
		sort(k, k + m, cmp);
		ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m; i++)
			dp[i] = k[i].w;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (k[i].x >= k[j].y + r)
					dp[i] = max(dp[i], dp[j] + k[i].w);
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}