#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 130
#define maxm 11
#define INF 0x3f3f3f3f

using namespace std;

int d[1 << maxm][1 << maxm];
int cnt[1 << maxm][1 << maxm];
int p[maxn], n, m;
char t[maxm + 3];

void init()
{
	memset(cnt, 0, sizeof(cnt));
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &t);
		int len = strlen(t);
		for (int j = 0; j < len; j++)
			p[i] = (p[i] << 1) + t[j] - 48;
	}
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < n; j++)
			cnt[i][i & p[j]]++;//每个物品在询问i的情况下的应答状态， 如果这个应答状态是1 那么我们说这个状态是唯一的
}

int dp(int s0, int s1)
{
	if (d[s0][s1] != -1)
		return d[s0][s1];
	if (cnt[s0][s1] <= 1)
		return d[s0][s1] = 0;
	d[s0][s1] = INF;
	for (int i = 0; i < m; i++)
	{
		if (s0 & (1 << i))
			continue;
		int &ans = d[s0][s1];
		int t0 = s0 ^ (1 << i);
		ans = min(ans, max(dp(t0, s1), dp(t0, s1 ^ (1 << i))) + 1);
	}
	return d[s0][s1];
}

int main(void)
{
	while (scanf("%d %d", &m, &n) != EOF && (m + n))
	{
		init();
		int ans = dp(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}