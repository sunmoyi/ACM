#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[105][105];
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		memset(map, 0, sizeof(map));
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%c", &map[i][j]);
			}
			getchar();
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '-')
				{
					continue;
				}
				else if (map[i][j] == 'B')
				{
					if (i + 1 < n && map[i + 1][j] == '.')
						map[i + 1][j] = 'W';
					if (i - 1 >= 0 && map[i - 1][j] == '.')
						map[i - 1][j] = 'W';
					if (j + 1 < m && map[i][j + 1] == '.')
						map[i][j + 1] = 'W';
					if (j - 1 >= 0 && map[i][j - 1] == '.')
						map[i][j - 1] = 'W';
				}
				else if (map[i][j] == 'W')
				{
					if (i + 1 < n && map[i + 1][j] == '.')
						map[i + 1][j] = 'B';
					if (i - 1 >= 0 && map[i - 1][j] == '.')
						map[i - 1][j] = 'B';
					if (j + 1 < m && map[i][j + 1] == '.')
						map[i][j + 1] = 'B';
					if (j - 1 >= 0 && map[i][j - 1] == '.')
						map[i][j - 1] = 'B';
				}
				else if (map[i][j] == '.')
				{
					map[i][j] = 'B';
					if (i + 1 < n && map[i + 1][j] == '.')
						map[i + 1][j] = 'W';
					if (i - 1 >= 0 && map[i - 1][j] == '.')
						map[i - 1][j] = 'W';
					if (j + 1 < m && map[i][j + 1] == '.')
						map[i][j + 1] = 'W';
					if (j - 1 >= 0 && map[i][j - 1] == '.')
						map[i][j - 1] = 'W';
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}