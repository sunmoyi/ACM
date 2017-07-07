#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

int n, m;
int a[maxn], sum[maxn], w[maxn];
int dp[maxn][maxn];
int q[maxn], head, tail;

int dy(int x, int j, int i)
{
	return dp[x][i] - w[i] + sum[i] * sum[i] - (dp[x][j] - w[j] + sum[j] * sum[j]);
}

int dx(int j, int i)
{
	return sum[i] - sum[j];
}

void DP()
{
	for (int i = 1; i <= n; i++)
		dp[1][i] = w[i];

	for (int i = 2; i <= m + 1; i++)
	{
		head = tail = 0;
		q[tail++] = i - 1;
		for (int j = i; j <= n; j++)
		{
			while (tail - head >= 2 &&
				dy(i - 1, q[head], q[head + 1]) <
				sum[j] * dx(q[head], q[head + 1]))
				head++;
			dp[i][j] = dp[i - 1][q[head]] + w[j] - w[q[head]] - sum[q[head]] * (sum[j] - sum[q[head]]);

			while (tail - head >= 2 &&
				dy(i - 1, q[tail - 2], q[tail - 1]) * dx(q[tail - 1], j) >=
				dx(q[tail - 2], q[tail - 1]) * dy(i - 1, q[tail - 1], j))
				tail--;
			q[tail++] = j;
		}
	}
	printf("%d\n", dp[m + 1][n]);
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		sum[0] = 0;
		w[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
			w[i] = w[i - 1] + sum[i - 1] * a[i];
		}
		DP();
	}
	return 0;
}