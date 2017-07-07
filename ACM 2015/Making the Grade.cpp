#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 2010
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn], b[maxn];
long long dp[2][maxn];
int n;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		long long minn = dp[(i - 1) % 2][1];
		for (int j = 1; j <= n; j++)
		{
			minn = min(minn, dp[(i - 1) % 2][j]);
			dp[i % 2][j] = minn + abs(a[i] - b[j]);
		}
	}
	long long ans = INF;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dp[n % 2][i]);
	printf("%lld\n", ans);
	return 0;
}