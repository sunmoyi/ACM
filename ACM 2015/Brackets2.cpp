#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 210

using namespace std;

char s[maxn];
int dp[maxn][maxn];

int main(void)
{
	while (scanf("%s", s) != EOF && s[0] != 'e')
	{
		int len = strlen(s);
		memset(dp, 0, sizeof(dp));
		for (int l = 1; l < len; l++)
		{
			for (int i = 0; i + l < len; i++)
			{
				int j = i + l;
				if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
					dp[i][j] = dp[i + 1][j - 1] + 2;
				for (int k = i; k < j; k++)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
		printf("%d\n", dp[0][len - 1]);
	}
	return 0;
}