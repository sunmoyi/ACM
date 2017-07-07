#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

int map[maxn][maxn];
int dis[maxn];
int mark[maxn];
int N, M;

void prim(int S)
{
	int i;
	for (int i = 1; i <= N; i++)
	{
		dis[i] = map[S][i];
		mark[i] = 0;
	}
	dis[S] = 0;
	mark[S] = 1;

	int num = N - 1;
	int ans = INF;
	while (num--)
	{
		int maxx = -1;
		int key = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!mark[i] && dis[i] > maxx)
			{
				maxx = dis[i];
				key = i;
			}
		}
		if (maxx < ans)
			ans = maxx;
		if (key == N)
			break;
		mark[key] = 1;
		for (int i = 1; i <= N; i++)
		{
			if (!mark && dis[i] < map[key][i])
				dis[i] = map[key][i];
		}
	}
	printf("%d\n", ans);
}

int main(void)
{
	int T, Case, a, b, c;
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++)
	{
		scanf("%d %d", &N, &M);
		memset(map, -1, sizeof(map));

		while (M--)
		{
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}

		printf("Scenario #%d:\n", Case);
		prim(1);;
		printf("\n");
	}
	return 0;
}