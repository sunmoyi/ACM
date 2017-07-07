#include<stdio.h>
#include<string.h>
#define NN 1004
#define INF 0x3fffffff
int map[NN][NN];
int dis[NN];
int mark[NN];
int N, M;

void prim(int sta) 
{
	int i;
	for (i = 1; i <= N; i++)
	{
		dis[i] = map[sta][i];
		mark[i] = 0;
	}
	dis[sta] = 0;
	mark[sta] = 1;

	int num = N - 1;

	int ans = INF;
	while (num--) 
	{
		int max = -2;
		int key = 0;
		for (i = 1; i <= N; i++) 
		{
			if (!mark[i] && dis[i] > max)
			{
				max = dis[i];
				key = i;
			}
		}
		if (max < ans) ans = max;
		if (key == N) break;
		mark[key] = 1;
		for (i = 1; i <= N; i++) {
			if (!mark[i] && dis[i] < map[key][i]) 
			{
				dis[i] = map[key][i];
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int T, ca, a, b, c;
	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++) 
	{
		scanf("%d%d", &N, &M);
		/*for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
		map[i][j] = -1;
		}
		}*/

		memset(map, -1, sizeof(map));

		while (M--) 
		{
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}

		printf("Scenario #%d:\n", ca);
		prim(1); puts("");
	}
	return 0;
}