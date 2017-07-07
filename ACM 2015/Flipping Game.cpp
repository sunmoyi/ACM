#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int n;
int num[maxn];
int one[maxn];
int zero[maxn];
int dp[maxn][maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			zero[i] = zero[i - 1];
			one[i] = one[i - 1];
			if (num[i] == 0)
				zero[i]++;
			else
				one[i]++;
		}
		if (zero[n] == 0)
		{
			printf("%d\n", n - 1);
			continue;
		}
		int maxx = 0, len = one[n];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				int ze = zero[j] - zero[i - 1];
				int on = one[j] - one[i - 1];
				dp[i][j] = ze - on;
				if (dp[i][j] > maxx)
				{
					maxx = dp[i][j];
					len = one[n] + ze - on;
				}
			}
		}
		printf("%d\n", len);
	}
	return 0;
}