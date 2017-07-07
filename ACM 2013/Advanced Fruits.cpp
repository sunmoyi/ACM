#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str1[105], str2[105];
int dp[105][105];
int len1, len2;
struct node {
	int x;
	int y;
	char z;
}a[105];

int main(void)
{
	while (scanf_s("%s", str1 + 1, 104) != EOF)
	{
		getchar();
		scanf_s("%s", str2 + 1, 104);
		len1 = strlen(str1 + 1);
		len2 = strlen(str2 + 1);

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i] == str2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		if (dp[len1][len2] == 0)
			printf("%s%s", str1, str2);
		else
		{
			int i = len1, j = len2, ans = 0;
			while (i >= 1 && j >= 1)
			{
				if ((dp[i][j] == dp[i - 1][j - 1] + 1) && str1[i] == str2[j])
				{
					a[ans].x = i;
					a[ans].y = j;
					a[ans++].z = str1[i];
				}
				else if (dp[i - 1][j] > dp[i][j - 1])
					i--;
				else
					j--;
			}

			i = j = 1;
			for (int k = ans - 1; k >= 0; k--)
			{
				while (i != a[k].x)
				{
					printf("%c", str1[i]);
					i++;
				}
				while (j != a[k].y)
				{
					printf("%c", str2[j]);
					j++;
				}
				printf("%c", a[k].z);
				i++, j++;
			}
			printf("%s%s\n", str1 + 1 + a[0].x, str2 + 1 + a[0].y);
		}
	}
	return 0;
}