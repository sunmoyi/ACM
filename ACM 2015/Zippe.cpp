#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str1[500], str2[500], str3[500];
int dp[500][500];

int main(void)
{
	int len1, len2, len3, T;
	scanf("%d", &T);
	getchar();
	for (int ss = 1; ss <= T; ss++)
	{
		scanf("%s %s %s", str1 + 1, str2 + 1, str3 + 1);
		len1 = strlen(str1 + 1);
		len2 = strlen(str2 + 1);
		len3 = strlen(str3 + 1);
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= len1; i++)
		{
			if (str1[i] == str3[i])
				dp[i][0] = 1;
			else
				break;
		}
		for(int i = 1; i <= len2; i++)
		{
			if (str2[i] == str3[i])
				dp[0][i] = 1;
			else
				break;
		}
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str3[i + j] == str1[i] && dp[i - 1][j])
					dp[i][j] = 1;
				if (str3[i + j] == str2[j] && dp[i][j - 1])
					dp[i][j] = 1;
			}
		}
		if (dp[len1][len2])
			printf("Data set %d: yes\n", ss);
		else
			printf("Data set %d: no\n", ss);
	}
	return 0;
}