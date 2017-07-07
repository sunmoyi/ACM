#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1500010

using namespace std;

int num[maxn];
int dp[maxn];
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		for (int i = 1; i <= m; i++)
			dp[1] += num[i];

		int minn = dp[1], ans = 1;
		for (int i = 2; i + m - 1<= n; i++)
		{
			dp[i] = dp[i - 1] - num[i - 1] + num[i + m - 1];
			if (dp[i] < minn)
			{
				minn = dp[i];
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}