#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int maps[11][101];
int smap[11][101];
int fath[11][101];

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &maps[i][j]);
		memset(smap, 0, sizeof(smap));

		for (int i = m; i >= 1; --i)
		{	
			for (int j = 1; j <= n; ++j)
			{
				smap[j][i] = smap[j][i + 1] + maps[j][i];
				fath[j][i] = j;
				if (j > 1 && smap[j][i] >= smap[j - 1][i + 1] + maps[j][i])
				{
					smap[j][i] = smap[j - 1][i + 1] + maps[j][i];
					fath[j][i] = j - 1;
				}
				if (j == n && smap[j][i] >= smap[1][i + 1] + maps[j][i])
				{
					smap[j][i] = smap[1][i + 1] + maps[j][i];
					fath[j][i] = 1;
				}
				if (j < n && smap[j][i] > smap[j + 1][i + 1] + maps[j][i])
				{
					smap[j][i] = smap[j + 1][i + 1] + maps[j][i];
					fath[j][i] = j + 1;
				}
				if (j == 1 && smap[j][i] > smap[n][i + 1] + maps[j][i])
				{
					smap[j][i] = smap[n][i + 1] + maps[j][i];
					fath[j][i] = n;
				}
			}
		}
		int row = 1;
		for (int i = 2; i <= n; i++)
			if (smap[row][1] > smap[i][1])
				row = i;

		int minn = smap[row][1];
		for (int i = 1; i <= m; i++)
		{
			if (i < m)
				printf("%d ", row);
			else
				printf("%d\n%d\n", row, minn);
			row = fath[row][i];
		}
	}
	return 0;
}