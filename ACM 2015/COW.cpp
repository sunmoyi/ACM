#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

unsigned long long dp[maxn][3];
int len;
char ch;

int main (void)
{
	while (scanf("%d", &len) != EOF)
	{
		getchar();
		dp[0][1] = dp[0][2] = 0;
		unsigned long long ans = 0;
		for (int i = 1; i <= len; i++)
		{
			scanf("%c", &ch);
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
			if (ch == 'C')
				dp[i][1]++;
			else if (ch == 'O')
				dp[i][2] += dp[i][1];
			else
				ans += dp[i][2];
		}
		printf("%llu\n", ans);
	}
	return 0;
}