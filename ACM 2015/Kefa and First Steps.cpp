#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int n;
int num[maxn];
int dp[maxn];

int main (void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	dp[0] = 0;
	int maxx = 1;
	for (int i = 1; i <= n; i++)
	{
		if (num[i] >= num[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
			maxx = max(maxx, dp[i]);
		}
		else
			dp[i] = 1;
	}
	printf("%d\n", maxx);
}