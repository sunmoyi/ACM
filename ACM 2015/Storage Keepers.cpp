#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 130
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int f[maxn][maxn], g[maxn][maxn];
int p[maxn];

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		for (int i = 1; i <= m; i++)
			scanf("%d", &p[i]);
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= m; i++)
		{
			f[i - 1][0] = INF;
			for (int j = 1; j <= n; j++)
			{
				f[i][j] = f[i - 1][j];
				for (int k = 1; k <= j; k++)
				{
					f[i][j] = max(f[i][j], min(f[i - 1][j - k], p[i] / k));
				}
			}
		}

		memset(g, INF, sizeof(g));

		for(int i = 1; i <= m; i++)
		{
			g[i - 1][0] = 0;
			for (int j = 1; j <= n; j++)
			{
				g[i][j] = g[i - 1][j];
				for (int k = 1; k <= j; k++)
				{
					if ((p[i] / k) >= f[m][n])
						g[i][j] = min(g[i][j], g[i - 1][j - k] + p[i]);
				}
			}
		}
		printf("%d %d\n", f[m][n], f[m][n] == 0 ? 0 : g[m][n]);
	}
	return 0;
}