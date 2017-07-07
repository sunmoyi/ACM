#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

int dist[maxn][maxn];

int main (void)
{
	int a, b, n, icase = 1;
	while (scanf("%d %d", &a, &b) != EOF && (a + b))
	{
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				dist[i][j] = INF;
		for (int i = 0; i < maxn; i++)
			dist[i][i] = 0;
		n = 0;
		do {
			dist[a][b] = 1;
			n = max(n, max(a, b));
		} while (scanf("%d %d", &a, &b) != EOF && (a + b));
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
		int count = 0, sum = 0;
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] < INF && dist[i][j])
				{
					//printf("%d %d %d\n", i, j, dist[i][j]);
					sum += dist[i][j];
					count++;
				}
		printf("Case %d: ", icase++);
		printf("average length between pages = %.3lf clicks\n", 1.0 * sum / count);
	}
	return 0;
}