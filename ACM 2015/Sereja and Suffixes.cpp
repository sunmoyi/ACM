#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int dp[maxn];
bool vis[maxn];
int n, m;

int main (void)
{
	int x;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
	
		for (int i = n; i >= 1; i--)
		{
			dp[i] = dp[i + 1];
			if (!vis[num[i]])
			{
				vis[num[i]] = true;
				dp[i]++;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &x);
			printf("%d\n", dp[x]);
		}
	}
	return 0;
}