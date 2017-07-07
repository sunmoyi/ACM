#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define maxm 5010

using namespace std;
int a[maxn], dp[maxm][maxn];
int n, m;
int q[maxn];
int head, tail;

int DP()
{
	for (int i = 1; i <= n; i++)
		dp[1][i] = (a[i] - a[1])*(a[i] - a[1]);
	for (int i = 2; i <= m; i++)
	{
		head = tail = 0;
		q[tail++] = i - 1;
		for (int j = i; j <= n; j++)
		{
			while (head + 1<tail)
			{
				int p1 = q[head];
				int p2 = q[head + 1];
				int x1 = a[p1 + 1];
				int x2 = a[p2 + 1];
				int y1 = dp[i - 1][p1] + x1*x1;
				int y2 = dp[i - 1][p2] + x2*x2;
				if ((y2 - y1) <= 2 * a[j] * (x2 - x1))head++;
				else break;
			}
			int k = q[head];
			dp[i][j] = dp[i - 1][k] + (a[j] - a[k + 1])*(a[j] - a[k + 1]);
			while (head + 1<tail)
			{
				int p1 = q[tail - 2];
				int p2 = q[tail - 1];
				int p3 = j;
				int x1 = a[p1 + 1];
				int x2 = a[p2 + 1];
				int x3 = a[p3 + 1];
				int y1 = dp[i - 1][p1] + x1*x1;
				int y2 = dp[i - 1][p2] + x2*x2;
				int y3 = dp[i - 1][j] + x3*x3;
				if ((y3 - y2)*(x2 - x1) <= (y2 - y1)*(x3 - x2))tail--;
				else break;
			}
			q[tail++] = j;
		}
	}
	return dp[m][n];
}

int main(void)
{
	int T;
	scanf("%d", &T);
	int iCase = 0;
	while (T--)
	{
		iCase++;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		printf("Case %d: %d\n", iCase, DP());
	}
	return 0;
}