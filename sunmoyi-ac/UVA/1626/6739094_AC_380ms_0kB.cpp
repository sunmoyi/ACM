#include<cstdio>  
#include<cstring>  
#include<algorithm> 
#define INF 0x3f3f3f3f

using namespace std;

int dp[111][111];
char str[110];

int match(char a, char b)
{
	if ((a == '('&&b == ')') || (a == '['&&b == ']'))return 1;
	return 0;
}


void print(int i, int j)
{
	if (i>j)
		return;
	if (i == j)
	{
		if (str[i] == '(' || str[i] == ')')printf("()");
		else printf("[]");
		return;
	}
	int ans = dp[i][j];

	if (match(str[i], str[j]) && ans == dp[i + 1][j - 1]) 
	{
		printf("%c", str[i]);
		print(i + 1, j - 1);
		printf("%c", str[j]);
		return;
	}
	for (int k = i; k<j; ++k) 
	{
		if (ans == dp[i][k] + dp[k + 1][j]) 
		{
			print(i, k);
			print(k + 1, j);
			return;
		}
	}
}
int main(void)
{
	int t, i, n, j, flag = 0;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		gets(str);
		gets(str);
		n = (int)strlen(str);

		if (!n) 
		{
			if (flag++)
				printf("\n");
			printf("\n");
			continue;
		}

		for (i = 0; i<n; i++) 
		{
			dp[i][i] = 1;
		}

		for (i = n - 2; i >= 0; i--) 
		{
			for (j = i + 1; j<n; j++)
			{
				dp[i][j] = INF;
				if (match(str[i], str[j]))
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
				for (int k = i; k<j; k++) 
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}

		if (flag++)
			printf("\n");
		print(0, n - 1);
		printf("\n");
	}
	return 0;
}