#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 5000;
long long f[maxn][maxn];
long long g[maxn][maxn];
long long h[maxn][maxn];
long long d[maxn];
long long w[maxn];
long long p[maxn];

int main()
{
	int n, s;
	while (scanf("%d %d", &n, &s) != EOF)
	{
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		memset(h, 0, sizeof(h));
		memset(d, 0, sizeof(d));
		memset(w, 0, sizeof(w));
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &d[i], &w[i]);

		for (int i = 1; i <= n; i++)
			p[i] = p[i - 1] + w[i];

		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				h[i][j] = p[n] - p[j] + p[i - 1];

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = g[i][j] = 100000000;


		f[s][s] = g[s][s] = 0;

		for (int j = s; j <= n; j++)
			for (int i = j - 1; i >= 1; i--)
			{
				f[i][j] = min(f[i + 1][j] + h[i + 1][j] * (d[i + 1] - d[i]), g[i + 1][j] + h[i + 1][j] * (d[j] - d[i]));
				g[i][j] = min(f[i][j - 1] + h[i][j - 1] * (d[j] - d[i]), g[i][j - 1] + h[i][j - 1] * (d[j] - d[j - 1]));
			}

		printf("%lld\n", min(f[1][n], g[1][n]));
	}
}
