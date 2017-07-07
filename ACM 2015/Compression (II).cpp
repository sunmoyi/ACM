#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn];
int b[maxn];
int d[2][maxn][2];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &a[i], &b[i]);

		int cur = 0;
		for (int j = 1; j <= n; j++)
			d[0][j][0] = d[0][j][1] = (b[j] > 0) ? 0 : INF;
		for (int i = 1; i < n; i++)
		{
			cur ^= 1;
			for (int j = 1; j <= n - i; j++)
			{
				d[cur][j][0] = min(d[cur ^ 1][j + 1][0] + a[j + 1] - a[j],
								   d[cur ^ 1][j + 1][1] + a[j + i] - a[j]);
				d[cur][j][1] = min(d[cur ^ 1][j][1] + a[j + i] - a[j + i - 1],
								   d[cur ^ 1][j][0] + a[j + i] - a[j]);
				if (d[cur][j][0] >= b[j])
					d[cur][j][0] = INF;
				if (d[cur][j][1] >= b[j + i])
					d[cur][j][1] = INF;
			}
		}
		int minn = min(d[cur][1][0], d[cur][1][1]);
		if (minn == INF)
			printf("No solution\n");
		else
			printf("%d\n", minn);
	}
	return 0;
}