#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510

using namespace std;

int sum;
int num[maxn];
int dp[maxn][maxn];

int main(void)
{
	scanf("%d", &sum);
	for (int i = 1; i <= sum; i++)
		scanf("%d", &num[i]);

	memset(dp, 0x42, sizeof(dp));
	for (int i = 1; i <= sum; i++)
		dp[i][i] = 1;

	for (int i = 1; i < sum; i++)
	{
		for (int j = 1; j + i <= sum; j++)
		{
			int l = j, r = i + j;
			for (int h = l; h < r; h++)
				dp[l][r] = min(dp[l][r], dp[l][h] + dp[h + 1][r]);
			if (num[l] == num[r])
			{
				if (i == 1)
					dp[l][r] = 1;
				else
					dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
		}
	}
	printf("%d\n", dp[1][sum]);
	return 0;
}