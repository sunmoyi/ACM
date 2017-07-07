#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15000

using namespace std;

int dp[maxn], st[maxn], sf[maxn], que[maxn];
int head, tail;

int main(void)
{
	int n, s;
	while (scanf("%d %d", &n, &s) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d%d", st + i, sf + i);
		dp[n + 1] = st[n + 1] = sf[n + 1] = 0;
		for (int i = n; i >= 1; i--)
			st[i] += st[i + 1], sf[i] += sf[i + 1];

		head = 0, tail = 0;
		que[head] = n + 1;
		for (int i = n; i >= 1; i--)
		{
			while (head < tail &&
				dp[que[head + 1]] - dp[que[head]] <= 
				(st[que[head + 1]] - st[que[head]])*sf[i])
				head++;
			dp[i] = dp[que[head]] + (st[i] - st[que[head]] + s)*sf[i];

			while (head < tail && 
				(dp[i] - dp[que[tail]]) *(st[que[tail]] - st[que[tail - 1]]) <= 
				(st[i] - st[que[tail]])*(dp[que[tail]] - dp[que[tail - 1]]))
				tail--;
			que[++tail] = i;
		}
		printf("%d\n", dp[1]);
	}
	return 0;
}