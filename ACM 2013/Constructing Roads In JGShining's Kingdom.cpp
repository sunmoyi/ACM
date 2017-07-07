#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
#define INF 0xfffffff

using namespace std;

int ans, s1, s2;
int dp[500005];
int num[500005];

int main(void)
{
	int casee = 1;
	while (scanf_s("%d", &ans) != EOF)
	{
		for (int i = 1; i <= ans; i++)
			num[i] = INF;

		for (int i = 1; i <= ans; i++)
		{
			scanf_s("%d %d", &s1, &s2);
			num[s1] = s2;
		}

		for (int i = 0; i <= ans + 1; i++)
			dp[i] = INF;

		for (int i = 1; i <= ans; i++)
			*lower_bound(dp, dp + ans, num[i]) = num[i];

		printf("Case %d:\n", casee++);
		int t = lower_bound(dp, dp + ans, INF) - dp;
		if (t == 1)
			printf("My king, at most 1 road can be built.\n\n");
		else
			printf("My king, at most %d roads can be built.\n\n", t);
	}
	return 0;
}