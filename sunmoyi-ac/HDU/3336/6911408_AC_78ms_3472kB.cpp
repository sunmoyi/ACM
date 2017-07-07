#include<stdio.h>
#include<string.h>
const int MAXN = 200020;
const int MOD = 10007;
int dp[MAXN];
char str[MAXN];
int next[MAXN];

void getNext(char *p)
{
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	int len = strlen(p);
	while (j<len)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else k = next[k];
	}
}

int main()
{
	int T;
	int n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", &str);
		getNext(str);
		dp[0] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[next[i]] + 1;
			dp[i] %= MOD;
			ans += dp[i];
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}