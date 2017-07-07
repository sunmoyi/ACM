#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int map[maxn][maxn];
int n;

int main (void)
{
	int a, b, Case = 0;
	while (scanf("%d %d", &a, &b) != EOF && (a + b))
	{
		memset(map, INF, sizeof(map));
		n = 0;
		for (int i = 1; i < maxn; i++)
			map[i][i] = 0;
		do {
			map[a][b] = 1;
			n = max(n, a);
			b = max(n, b);
		} while (scanf("%d %d", &a, &b) && (a + b));

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

		long long sum = 0, ans = 0;;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] != INF && i != j)
				{
					sum += map[i][j];
					ans++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n", ++Case, sum * 1.0 / ans);
	}
	return 0;
}