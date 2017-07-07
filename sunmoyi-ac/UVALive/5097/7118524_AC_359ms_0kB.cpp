#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010
#define INF 0x3f3f3f3f

using namespace std;

struct person {
	long long w, h;
}P[maxn];

int n, k, flag;
int que[maxn];
long long dp[maxn][110];

bool cmp(const person &a, const person &b)
{
	if (a.h == b.h)
		return a.w > b.w;
	return a.h > b.h;
}

void init()
{
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld", &P[i].w, &P[i].h);
	sort(P + 1, P + 1 + n, cmp);
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (P[cnt].w < P[i].w)
			P[++cnt] = P[i];
	}
	n = cnt;
	k = min(n, k);
}

long long getUp(int j, int k, int hole)
{
	return dp[j][hole] - dp[k][hole];
}

long long getDown(int j, int k)
{
	return P[j + 1].h - P[k + 1].h;
}

void solve()
{
	int head, tail;
	for (int i = 1; i <= n; i++) dp[i][1] = P[i].w * P[1].h;
	for (int hole = 2; hole <= k; hole++) 
	{
		head = tail = 0;
		que[tail++] = 0;
		for (int i = 1; i <= n; i++)
		{
			while (head + 1 < tail && 
				getUp(que[head + 1], que[head], hole - 1) 
				<= P[i].w * getDown(que[head], que[head + 1]))
				head++;
			dp[i][hole] = dp[que[head]][hole - 1] + P[i].w * P[que[head] + 1].h;
			while (head + 1 < tail &&  
				getUp(i, que[tail - 1], hole - 1) * getDown(que[tail - 2], que[tail - 1]) 
				<= getUp(que[tail - 1], que[tail - 2], hole - 1) * getDown(que[tail - 1], i))
				tail--;
			que[tail++] = i;
		}
	}
	long long  ans = dp[n][1];
	for (int i = 2; i <= k; i++)
		ans = min(ans, dp[n][i]);
	printf("%lld\n", ans);
}

int main(void)
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		init();
		solve();
	}
	return 0;
}