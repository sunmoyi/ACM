#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define maxn 1010

using namespace std;

int n, f[maxn][maxn], sum[maxn][maxn], s[maxn][maxn];

struct Point {
	int x, y;
}stone[maxn];

int dis(Point a, Point b, Point c, Point d)
{
	return abs(c.x - a.x) + abs(d.y - b.y);
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &stone[i].x, &stone[i].y);
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= n; i++)
			s[i][i] = i;

		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i <= n - len + 1; i++)
			{
				int j = i + len - 1;
				f[i][j] = INF;
				for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++)
				{
					if (f[i][j] > f[i][k] + f[k + 1][j] + dis(stone[i], stone[k], stone[k + 1], stone[j]))
					{
						f[i][j] = f[i][k] + f[k + 1][j] + dis(stone[i], stone[k], stone[k + 1], stone[j]);
						s[i][j] = k;
					}
				}
			}
		}
		printf("%d\n", f[1][n]);
	}
	return 0;
}