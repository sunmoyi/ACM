#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

struct Point{
	int v, id;
}p[maxn][maxn];
int n, m, d, g[maxn * 3], res;
int f[2][10][10][10][10];

bool cmp(Point a, Point b)
{
	return a.v > b.v;
}

int judge(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;
	return p[x][y].id;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &d);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &p[i][j].v);
				p[i][j].id = j;
			}
			sort(p[i] + 1, p[i] + n + 1, cmp);
		}
		res = 0;
		d += 10;
		for (int i = 1; i <= d; i++)
			scanf("%d", &g[i]);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= d; i++)
		{
			int now = i % 2;
			int pre = 1 - now;
			memset(f[now], 0, sizeof(f[now]));
			if (g[i])
			{
				for (int x = 1; x <= 5; x++)
				{
					for (int j = 0; j <= 5; j++)
					{
						if (i > 1 && judge(g[i], x) == judge(g[i - 1], j))
							continue;
						for (int k = 0; k <= 5; k++)
						{
							if (i > 2 && judge(g[i], x) == judge(g[i - 2], k))
								continue;
							for (int l = 0; l <= 5; l++)
							{
								if (i > 3 && judge(g[i], x) == judge(g[i - 3], l))
									continue;
								for (int o = 0; o <= 5; o++)
								{
									if (i > 4 && judge(g[i], x) == judge(g[i - 4], o))
										continue;
									f[now][x][j][k][l] = max(f[now][x][j][k][l], f[pre][j][k][l][o] + p[g[i]][x].v);
									res = max(res, f[now][x][j][k][l]);
								}
							}
						}
					}
				}
			}
			else
			{
				for (int j = 0; j <= 5; j++)
				{
					for (int k = 0; k <= 5; k++)
					{
						for (int l = 0; l <= 5; l++)
						{
							for (int o = 0; o <= 5; o++)
							{
								f[now][0][j][k][l] = max(f[now][0][j][k][l], f[pre][j][k][l][o]);
								res = max(res, f[now][0][j][k][l]);
							}
						}
					}
				}
			}
		}
		printf("%.2lf\n", res * 1.0 / 100);
	}
	return 0;
}