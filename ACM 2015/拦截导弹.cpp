#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int map[30];
int dp[30];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &map[i]);
		dp[i] = 1;
	}


	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (map[j] >= map[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	printf("%d\n", dp[n]);
}