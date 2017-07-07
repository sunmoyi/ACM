/*
思考后可以发现答案就是
分裂次数+合并次数-n-1 = 分裂次数*2-n-1。

接下来考虑如何让分裂次数最小。
将盘子排序，大小相同的盘子视作同一种，
设 f[i][j] 表示到第i种盘子，这个盘子来自j堆的最小分裂次数，
枚举上一个盘子属于的堆k，
则如果k可以放在第i-1种盘子的末尾和第i种盘子的开头，
则       f[i][j]=min(f[i-1][k]+拥有第i种盘子的堆数-1)，
否则     f[i][j]=min(f[i-1][k]+拥有第i种盘子的堆数)。
而k需要满足的条件，
就是第k堆既拥有第i种盘子，
又拥有第i-1种盘子，
且除非第i种盘子来源仅有j，否则j!=k。
答案即为min(f[m][i])(1<=i<=n)。
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2510

using namespace std;

pair<int, int>a[maxn];
int f[maxn][55];
int h[maxn][55];
int cnt[maxn];
int n, c, m;

void pre()
{
	int i, j, p;
	sort(a + 1, a + c + 1);
	c = unique(a + 1, a + c + 1) - a - 1;
	for (i = 1; i <= c; i++)
	{
		p = i;
		m++;
		while (a[p].first == a[p + 1].first && p < c)
			p++;
		for (j = i; j <= p; j++)
			h[m][a[j].second] = 1;
		cnt[m] = p - i + 1;
		i = p;
	}
}

int dp()
{
	int i, j, k, ans = 0x3f3f3f3f;
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++)
		if (h[1][i])
			f[1][i] = cnt[1];
	for(i = 2; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (h[i][j])
			{
				for (k = 1; k <= n; k++)
				{
					if (h[i][k] && (cnt[i] == 1 || k != j))
						f[i][j] = min(f[i][j], f[i - 1][k] + cnt[i] - 1);
					else
						f[i][j] = min(f[i][j], f[i - 1][k] + cnt[i]);
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		ans = min(ans, f[m][i]);
	return ans * 2 - n - 1;
}

int main(void)
{
	int i, j, k, t, test = 0;
	while (scanf("%d", &n) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(h, 0, sizeof(h));
		m = c = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t);
			for (int j = 1; j <= t; j++)
			{
				scanf("%d", &a[++c].first);
				a[c].second = i;
			}
		}
		pre();
		printf("Case %d: %d\n", ++test, dp());
	}
	return 0;
}