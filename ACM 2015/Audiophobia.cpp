#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int d[maxn][maxn];
int m, n, Q;
int G[maxn][maxn];

void Floyed()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}
}

void output()
{
	int u, v;
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d %d", &u, &v);
		if (d[u][v] == INF)
			printf("no path\n");
		else
			printf("%d\n", d[u][v]);
	}
}

void read()
{
	int a, b, c;
	for (int i = 1; i < maxn; i++)
	{
		for (int j = i; j < maxn; j++)
		{
			d[i][j] = d[j][i] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = d[b][a] = c;
	}
}

int main(void)
{
	int casee = 1;
	while (scanf("%d %d %d", &n, &m, &Q) != EOF && (n + m + Q))
	{
		read();
		Floyed();	
		if (casee != 1)
			printf("\n");
		printf("Case #%d\n", casee++);
		output();
	}
	return 0;
}