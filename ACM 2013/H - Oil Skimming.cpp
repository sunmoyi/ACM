#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, n;
char map[605][605];

void clean(int i, int j)
{
	map[i][j] = '.';
	if (i < n - 1)
	{
		map[i + 2][j] = '.';
	}
	if (i < n)
	{
		map[i + 1][j] = '.';
		if (j - 1 > 0)
			map[i + 1][j - 1] = '.';
		if (j + 1 <= n)
			map[i + 1][j + 1] = '.';
	}
}

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d", &n);
			getchar();
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					scanf("%c", &map[i][j]);
				}
				getchar();
			}
			int k = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (map[i][j] == '#')
					{
						clean(i, j);
						k++;
					}
				}
			}
			printf("%d\n", k);
		}
	}
	return 0;
}