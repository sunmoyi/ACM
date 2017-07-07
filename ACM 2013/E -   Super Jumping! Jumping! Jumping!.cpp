#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, num[1005];
int dp[1005];

int main(void)
{
	while (scanf("%d", &ans) != EOF && ans)
	{
		for (int i = 1; i <= ans; i++)
		{
			scanf("%d", &num[i]);
			int temp = 0;
			int max = -1;
			bool find = false;
			for (int j = 1; j < i; j++)
			{
				if (num[j] < num[i] && dp[j] + num[i] > max)
				{
					max = dp[j] + temp;
					find = true;
				}
			}
			if (find)
				dp[i] = max;
			else
				dp[i] = num[i];
		}
		int out = -1;
		for (int i = 1; i <= ans; i++)
		{
			out = max(out, dp[i]);
		}
		printf("%d\n", out);
	}
	return 0;
}