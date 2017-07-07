#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100

using namespace std;

double dp[maxn][maxn];
char str1[maxn], str2[maxn];

int main(void)
{
	while (scanf("%s", str1) != EOF)
	{
		scanf("%s", str2);
		memset(dp, 0, sizeof(dp));
		int len = strlen(str1);
		int pos1 = 0, pos2 = 0, pos3 = 0;
		for (int i = 0; i < len; i++)
		{
			if (str1[i] == '+')
				pos1++;
			else
				pos1--;
			if (str2[i] == '+')
				pos2++;
			else if (str2[i] == '-')
				pos2--;
			else
				pos3++;
		}

		dp[0][pos2 + 10] = 1;
		for (int i = 1; i <= pos3; i++)
		{
			for (int j = -10; j <= len; j++)
			{
				dp[i][j + 10] = dp[i - 1][j - 1 + 10] * 0.5 + dp[i - 1][j + 1 + 10] * 0.5;
			}
		}
		printf("%.12lf\n", dp[pos3][pos1 + 10]);
	}
	return 0;
}