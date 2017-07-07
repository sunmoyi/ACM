#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int price[maxn], edge[maxn][maxn], leave[maxn];
int vis[maxn], d[maxn];
int N, M, ans;

void init()
{
	memset(price, 0, sizeof(price));
	memset(leave, 0, sizeof(leave));
	memset(edge, 0x7f, sizeof(edge));
}

void read()
{
	int i, j, X, T, TP;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d %d", &price[i], &leave[i], &X);
		for (int j = 0; j < X; j++)
		{
			scanf("%d %d", &T, &TP);
			edge[T][i] = TP;
		}
		edge[0][i] = price[i];
	}
}

int Dijkstra()
{
	for (int i = 1; i <= N; i++)
		d[i] = price[i];

	int temp = INF, x;
	for (int i = 1; i <= N; i++)
	{
		temp = INF;
		for (int j = 1; j <= N; j++)
			if (!vis[j] && d[j] <= temp)
				temp = d[x = j];

		vis[x] = 1;

		for (int j = 1; j <= N; j++)
			if (!vis[j] && d[j] > d[x] + edge[x][j])
				d[j] = d[x] + edge[x][j];
	}
	return d[1];
}

int main (void)
{
	while (scanf("%d %d", &M, &N) != EOF)
	{
		init();
		read();
		ans = INF;
		for (int i = 1; i <= N; i++)
		{
			int minleave = leave[i];
			for (int j = 1; j <= N; j++)
			{
				if (leave[j] - minleave > M || minleave > leave[j])
					vis[j] = 1;
				else
					vis[j] = 0;
			}
			int now = Dijkstra();
			ans = min(ans, now);
		}
		printf("%d\n", ans);
	}
	return 0;
}