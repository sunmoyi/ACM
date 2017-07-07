#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1010

using namespace std;

int dp[maxn][maxn], v;
vector<long long>G, ans, temp;

void floyed()
{
	for (int vi = G.size() - 1; vi >= 0; vi--)
	{
		long long k = G[vi], an = 0;
		temp.push_back(k);
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		for (int i = 0; i < temp.size(); i++)
			for (int j = 0; j < temp.size(); j++)
				an += dp[temp[i]][temp[j]];
		ans.push_back(an);
	}
}

int main(void)
{
	while (scanf("%d", &v) != EOF)
	{
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				scanf("%d", &dp[i][j]);
		for (int i = 0; i < v; i++)
		{
			int x;
			scanf("%d", &x);
			G.push_back(x);
		}
		floyed();
		for (int i = ans.size() - 1; i >= 0; i--)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}