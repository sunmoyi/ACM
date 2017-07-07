#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 400010

using namespace std;

int q[maxn];
long long sum[maxn];
long long a[maxn];
long long dp[maxn];

long long getdp(int i, int j)
{
	return dp[j] + (sum[i] - sum[j]) - a[j + 1] * (i - j);
}

long long getup(int j, int k)
{
	return dp[j] - sum[j] + j * a[j + 1] - (dp[k] - sum[k] + k * a[k + 1]);
}

long long getdown(int j, int k)
{
	return a[j + 1] - a[k + 1];
}

int main(void)
{
	int n, t;
	int head, tail;
	while(scanf("%d %d", &n , &t) != EOF)
	{
		dp[0] = sum[0] = 0;
		a[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i];
		head = tail = 0;
		q[tail++] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (head + 1 < tail &&
				getup(q[head + 1], q[head]) <=
				i * getdown(q[head + 1], q[head]))
				head++;
			dp[i] = getdp(i, q[head]);
			int j = i - t + 1;
			if (j < t)
				continue;
			while (head + 1 < tail &&
				getup(j, q[tail - 1]) * getdown(q[tail - 1], q[tail - 2]) <=
				getup(q[tail - 1], q[tail - 2]) * getdown(j, q[tail - 1]))
				tail--;
			q[tail++] = j;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}