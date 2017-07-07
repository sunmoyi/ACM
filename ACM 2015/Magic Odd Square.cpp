#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num;
int dp[50][50];

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		int temp = 1, j = num / 2 + 1, k = 0;
		for (int i = 1; i <= num / 2 + 1; i++)
		{
			for (int s = j - k; s <= j + k; s++)
			{
				dp[i][s] = temp;
				temp += 2;
			}
			k++;
		}
		k -= 2;
		for (int i = num / 2 + 2; i <= num; i++)
		{
			for (int s = j - k; s <= j + k; s++)
			{
				dp[i][s] = temp;
				temp += 2;
			}
			k--;
		}
		temp = 2;
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (dp[i][j] == -1)
				{
					dp[i][j] = temp;
					temp += 2;
				}
			}
		}

		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j < num; j++)
			{
				printf("%d ", dp[i][j]);
			}
			printf("%d\n", dp[i][num]);
		}
	}
	return 0;
}