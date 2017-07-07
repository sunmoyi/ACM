#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int mat[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int n, a, b;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = INF;
		}
	}
}

void floyed()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	if (mat[a][b] >= INF)
		printf("-1\n");
	else
		printf("%d\n", mat[a][b]);
}

int main(void)
{
	while (scanf("%d %d %d", &n, &a, &b) != EOF)
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			int m, v;
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &v);
				if (j == 0)
					mat[i][v] = 0;
				else
					mat[i][v] = 1;
			}
		}
		floyed();
	}
	return 0;
}