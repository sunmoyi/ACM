#include<iostream>
#include<string.h>

using namespace std;

int n, m;
char map[1005][1005];
int a[1005][1005], l[1005], r[1005];

int main()
{
	int T, i, j, max, t;
	scanf("%d", &T);
	{
		while (T--)
		{
			max = -1;
			scanf("%d%d", &n, &m);
			getchar();
			for (i = 1; i <= n; i++)
				for (j = 1; j <= m; j++)
					cin >> map[i][j];
			for (i = 1; i <= m; i++)
				a[0][i] = 0;

			for (i = 1; i <= m; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (map[j][i] == 'F')
						a[j][i] = a[j - 1][i] + 1;
					else
						a[j][i] = 0;
				}
			}

			for (i = 1; i <= n; i++)
			{
				l[1] = 1; r[m] = m;
				for (j = 2; j <= m; j++)
				{
					if (a[i][j] == 0)
						continue;
					t = j;
					while (t>1 && a[i][j] <= a[i][t - 1])
						t = l[t - 1];
					l[j] = t;
				}

				for (j = m - 1; j >= 1; j--)
				{
					if (a[i][j] == 0)
						continue;
					t = j;
					while (t<m&&a[i][j] <= a[i][t + 1])
						t = r[t + 1];
					r[j] = t;
				}

				for (j = 1; j <= m; j++)
					if ((r[j] - l[j] + 1)*a[i][j]>max)
						max = (r[j] - l[j] + 1)*a[i][j];

			}
			printf("%d\n", max * 3);
		}
	}
	return 0;
}