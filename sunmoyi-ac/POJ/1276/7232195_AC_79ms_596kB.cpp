#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int maxx, n, ans;
int val[100010], NUM, VAL;
int dp[110010];

int main(void)
{
	while (scanf("%d %d", &maxx, &n) != EOF)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &NUM, &VAL);
			int kk = 1;
			while (NUM >= kk)
			{
				val[ans++] = kk * VAL;
				NUM -= kk;
				kk *= 2;
			}
			val[ans++] = NUM * VAL;
		}

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i < ans; i++)
		{
			for (int j = maxx; j >= val[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
			}
		}
		printf("%d\n", dp[maxx]);

	}
	return 0;
}