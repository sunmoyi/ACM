#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int experience, ren, num, maxx;
int dp[105][105];
int exper[105], re[105];

int main(void)
{
	while (scanf_s("%d %d %d %d", &experience, &ren, &num, &maxx) != EOF)
	{
		for (int i = 1; i <= num; i++)
			scanf_s("%d %d", &exper[i], &re[i]);

		memset(dp, 0, sizeof(dp));

		int i;
		for (i = 1; i <= ren; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				for (int k = 1; k <= maxx; k++)
				{
					int ans = 1;
					while (ans <= k && ans * re[j] <= i)
					{
						dp[i][k] = max(dp[i][k],
							dp[i - re[j] * ans][k - ans] + exper[j] * ans);
						ans++;
					}
				}
			}
			if (dp[i][maxx] >= experience)
				break;
		}
		if (i > ren)
			printf("-1\n");
		else
			printf("%d\n", ren - i);
	}
	return 0;
}
