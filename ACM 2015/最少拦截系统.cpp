#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[1010];
int n;

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		dp[1] = 0;
		int m = 0, x;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			bool flag = false;
			for (int j = 1; j <= m; j++)
			{
				if (x <= dp[j])
				{
					dp[j] = x;
					flag = true;
					break;
				}
			}
			if (!flag)
				dp[++m] = x;
		}
		printf("%d\n", m);
	}
	return 0;
}