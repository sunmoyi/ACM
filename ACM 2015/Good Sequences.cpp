#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<time.h>
#define mod 1000000007
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

int dp[maxn], a[maxn];
vector<int>num[maxn];

void init()
{
	for (int i = 2; i < maxn; i++)
	{
		for (int j = i; j <= maxn; j += i)
		{
			num[j].push_back(i);
		}
	}
}

int main(void)
{
	init();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (vector<int>::iterator it = num[a[i]].begin(); it != num[a[i]].end(); it++)
			temp = max(temp, dp[*it]);
		for (vector<int>::iterator it = num[a[i]].begin(); it != num[a[i]].end(); it++)
			dp[*it] = temp + 1;
	}
	int ans = 1;
	for (int i = 0; i < maxn; i++)
		ans = max(dp[i], ans);
	printf("%d\n", ans);
	return 0;
}