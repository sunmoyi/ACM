#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 100010
#define INF 1e16

using namespace std;

long long num[maxn];
string str[maxn][2];
long long dp[maxn][2];

string reverse(string s)
{
	string ans = s;
	int len = s.length();
	for (int i = 0; i < len; i++)
		ans[i] = s[len - i - 1]; 
	return ans;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%lld", &num[i]);
		for (int i = 1; i <= n; i++)
		{
			cin >> str[i][0];
			str[i][1] = reverse(str[i][0]);
		}

		for (int i = 0; i <= n; i++)
			dp[i][0] = dp[i][1] = INF;
		dp[1][0] = 0, dp[1][1] = num[1];

		bool flag = true;
		for (int i = 2; i <= n; i++)
		{
			if (str[i][0] >= str[i - 1][0])
				dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			if (str[i][1] >= str[i - 1][0])
				dp[i][1] = min(dp[i][1], dp[i - 1][0] + num[i]);
			if (str[i][0] >= str[i - 1][1])
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			if (str[i][1] >= str[i - 1][1])
				dp[i][1] = min(dp[i][1], dp[i - 1][1] + num[i]);
			if (dp[i][0] == INF && dp[i][1] == INF)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			printf("%lld\n", min(dp[n][0], dp[n][1]));
		else
			printf("-1\n");
	}
	return 0;
}