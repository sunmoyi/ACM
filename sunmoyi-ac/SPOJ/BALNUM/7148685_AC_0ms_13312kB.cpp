#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 22

using namespace std;

int dit[maxn];
int poww[maxn];
long long dp[maxn][60000];

long long dfs(int pos, int sta, int limit)
{
	if (pos < 0)
	{
		if (limit == 1)
			int kk = 1;
		for (int i = 0; i <= 9; i++)
		{
			int tem = sta % 3;
			sta /= 3;
			if (tem != 0)
			{
				if (tem % 2 == 1 && i % 2 == 1)
					return 0;
				if (tem % 2 == 0 && i % 2 == 0)
					return 0;
			}
		}
		return 1;
	}
	if (!limit && dp[pos][sta] != -1)
		return dp[pos][sta];
	long long res = 0;
	int last = limit ? dit[pos] : 9;
	for (int i = 0; i <= last; i++)
	{
		int tsta = sta;
		if (i == 0)
		{
			if (tsta != 0)
			{
				int tem = tsta % 3;
				tsta = tsta / 3 * 3;
				if (tem == 1)
					tem = 2;
				else tem = 1;
				tsta += tem;
			}
		}
		else
		{
			int tem = tsta / poww[i] % 3;
			int hou = tsta % poww[i];
			if (hou != tsta % poww[i + 1])
				int kk = 1;
			int qian = tsta / poww[i + 1] * poww[i + 1];

			if (tem == 0 || tem == 2)
				tem = 1;
			else tem = 2;

			tsta = qian + tem * poww[i] + hou;
		}
		res += dfs(pos - 1, tsta, limit && (i == last));
	}
	if (!limit) 
		dp[pos][sta] = res;
	return res;
}

long long solve(long long n)
{
	int len = 0;
	while (n)
	{
		dit[len++] = n % 10;
		n /= 10;
	}
	return dfs(len - 1, 0, 1);
}

int main(void)
{
	poww[0] = 1;
	for (int i = 1; i <= 10; i++)
		poww[i] = poww[i - 1] * 3;
	memset(dp, -1, sizeof(dp));
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", solve(b) - solve(a - 1));
	}
	return 0;
}