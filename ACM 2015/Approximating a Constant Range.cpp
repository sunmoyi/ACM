#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100100
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn], maxv[maxn][20], minv[maxn][20];
int n;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		minv[i][0] = a[i];
		maxv[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++)
	{
		for (int k = 0; k + (1 << j) - 1 <= n; k++)
		{
			minv[k][j] = min(minv[k][j - 1], minv[k + (1 << (j - 1))][j - 1]);
			maxv[k][j] = max(maxv[k][j - 1], maxv[k + (1 << (j - 1))][j - 1]);
		}
	}
}

int q_max(int l, int r)
{
	int k = (int)(log((double)(r - l + 1))/ log(2.0));
	return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
}

int q_min(int l, int r)
{
	int k = (int)(log((double)(r - l + 1)) / log(2.0));
	return min(minv[l][k], minv[r - (1 << k) + 1][k]);
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		init();
		int ans = 0;
		int p = 1;
		for (int i = 1; i <= n; i++)
		{
			while (q_max(p, i) - q_min(p, i) > 1 && p <= i)
				p++;
			ans = max(ans, i - p + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}