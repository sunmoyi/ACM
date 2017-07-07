#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int V, E;
bool map[110][110];

void Floyed(void)
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for(int k = 1; k <= V; k++)
			{
				map[j][k] = map[j][k] || (map[j][i] && map[i][k]);
			}
		}
	}
}

int main(void)
{
	int a, b;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &a, &b);
			map[a][b] = true;
		}
		Floyed();
		int maxx = 0;
		for (int i = 1; i <= V; i++)
		{
			int sum = 0;
			for (int j = 1; j <= V; j++)
			{
				if (map[i][j] || map[j][i])
					sum++;
			}
			if (sum == V - 1)
				maxx++;
		}
		printf("%d\n", maxx);
	}
	return 0;
}