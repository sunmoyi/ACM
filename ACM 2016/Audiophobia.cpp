#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0x3f3f3f3f
using namespace std;

int map[maxn][maxn];
int S, C, Q, a, b, len;

int main(void)
{
	int Case = 0;
	while (scanf("%d %d %d", &C, &S, &Q) != EOF && (C + S + Q))
	{
		memset(map, INF, sizeof(map));
		for (int i = 1; i <= S; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			map[a][b] = map[b][a] = len;
		}

		for (int k = 1; k <= C; k++)
			for (int i = 1; i <= C; i++)
					for (int j = 1; j <= C; j++)
						map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));

		if (Case)
			printf("\n");
		printf("Case #%d\n", ++Case);
		while (Q--)
		{
			scanf("%d %d", &a, &b);
			if (map[a][b] != INF)
				printf("%d\n", map[a][b]);
			else
				printf("no path\n");
		}
	}
	return 0;
}