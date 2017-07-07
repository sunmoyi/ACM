#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int dp[40][40];

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		dp[0][1] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)//i time      j number
			{
				int front = j - 1;
				if (front == 0)
					front += n;

				int behind = j + 1;
				if (behind > n)
					behind -= n;
				dp[i][j] = dp[i - 1][front] + dp[i - 1][behind];
			}
		}
		printf("%d\n", dp[m][1]);
	}
	return 0;
}