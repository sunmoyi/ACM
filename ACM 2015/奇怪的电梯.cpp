#include<cstdio>  
using namespace std;

#define INF 0x3f3f3f3f

int g[1100][1100];
int a, b, n, k;

int main()
{
	while (scanf("%d%d%d", &n, &a, &b))
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j)
					g[i][j] = 0;
				else
					g[i][j] = INF;
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &k);
			if (i + k <= n)
				g[i][i + k] = 1;
			if (i - k > 0)
				g[i][i - k] = 1;
		}

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (g[i][j] > g[i][k] + g[k][j])
						g[i][j] = g[i][k] + g[k][j];
		if (g[a][b] == INF)
			printf("-1/n");
		else
			printf("%d\n", g[a][b]);
	}
	return 0;
}

//(y + x)(y - x + 1) = 2m
//y2 - xy + y + xy - x2 + x = 2m;
//y2 - x2 + y + x = 2m;