#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node {
	int q, p, v;
}a[505];
int n, m;
int dp[10000];

bool cmp(node a, node b)
{
	return (a.q - a.p) < (b.q - b.p);
}

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d %d %d", &a[i].p, &a[i].q, &a[i].v);
		}
		sort(a + 1, a + 1 + n, cmp);

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			for (int j = m; j >= a[i].q; j--)
			{
				dp[j] = max(dp[j], dp[j - a[i].p] + a[i].v);
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}