#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;	
char map[105][105];
char map2[105][105];

int main(void)
{
	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i < 105; i++)
		{
			for (int j = 1; j < 105; j++)
			{
				if (i % 2 == 0 && j % 2 == 0)
					map[i][j] = 'B';
				if (i % 2 == 0 && j % 2 == 1)
					map[i][j] = 'W';
				if (i % 2 == 1 && j % 2 == 0)
					map[i][j] = 'W';
				if (i % 2 == 1 && j % 2 == 1)
					map[i][j] = 'B';
			}
		}
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &map2[i][j]);
				if (map2[i][j] == '.')
					map2[i][j] = map[i][j];
			}
			getchar();
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("%c", map2[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}