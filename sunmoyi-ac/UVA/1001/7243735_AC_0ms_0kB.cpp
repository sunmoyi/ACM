#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

double map[maxn][maxn];
struct node {
	int x, y, z, r;
}point[maxn];
int n, x, y, z, r;

int main(void)
{
	int Case = 1;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		for (int i = 0; i < maxn; i++)
		{
			for (int j = 0; j < maxn; j++)
			{
				if (i == j)
					map[i][j] = 0;
				else
					map[i][j] = INF;
			}
		}

		for (int i = 1; i <= n; i++)
			scanf("%d %d %d %d", &point[i].x, &point[i].y, &point[i].z, &point[i].r);
		for (int i = n + 1; i <= n + 2; i++)
			scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].z), point[i].r = 0;

		for (int i = 1; i <= n + 2; i++)
		{
			for (int j = i + 1; j <= n + 2; j++)
			{
				double dist = sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) +
					(point[i].y - point[j].y) * (point[i].y - point[j].y) +
					(point[i].z - point[j].z) * (point[i].z - point[j].z) * 1.0);
				if (dist > point[i].r + point[j].r)
					map[i][j] = map[j][i] = dist - point[i].r - point[j].r;
				else
					map[i][j] = map[j][i] = 0;
			}
		}

		for (int k = 1; k <= n + 2; k++)
			for (int i = 1; i <= n + 2; i++)
				for (int j = 1; j <= n + 2; j++)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		printf("Cheese %d: Travel time = %.0lf sec\n", Case++, map[n + 1][n + 2] * 10.0);
	}
}