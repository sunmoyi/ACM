#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[1100][1100], b[1100][1100], c[1100][1100], l[1100], r[1100];

int main()
{
	int M, N;
	char ch;
	while (scanf("%d%d", &M, &N) != EOF)
	{
		for (int i = 1; i <= M; i++)
		{
			getchar();
			for (int j = 1; j <= N; j++)
			{
				scanf("%c", &ch);
				if (ch == 'a' || ch == 'w' || ch == 'y' || ch == 'z')
					a[i][j] = a[i - 1][j] + 1;
				else
					a[i][j] = 0;
				if (ch == 'b' || ch == 'w' || ch == 'x' || ch == 'z')
					b[i][j] = b[i - 1][j] + 1;
				else
					b[i][j] = 0;
				if (ch == 'c' || ch == 'x' || ch == 'y' || ch == 'z')
					c[i][j] = c[i - 1][j] + 1;
				else
					c[i][j] = 0;
			}
		}

		int area = -1;
		for (int i = 1; i <= M; i++)
		{
			//			------------------求a最大面积---------------
			l[0] = 1, r[N + 1] = N;
			a[i][0] = a[i][N + 1] = -1;
			for (int j = 1; j <= N; j++)
			{
				l[j] = j;
				while (a[i][l[j] - 1] >= a[i][j])
					l[j] = l[l[j] - 1];
			}
			for (int j = N; j >= 1; j--)
			{
				r[j] = j;
				while (a[i][r[j] + 1] >= a[i][j])
					r[j] = r[r[j] + 1];
			}
			for (int j = 1; j <= N; j++)
			{
				if (a[i][j] * (r[j] - l[j] + 1) > area)
					area = a[i][j] * (r[j] - l[j] + 1);
			}
			//			----------------求b最大面积----------------
			l[0] = 1, r[N + 1] = N;
			b[i][0] = b[i][N + 1] = -1;
			for (int j = 1; j <= N; j++)
			{
				l[j] = j;
				while (b[i][l[j] - 1] >= b[i][j])
					l[j] = l[l[j] - 1];
			}
			for (int j = N; j >= 1; j--)
			{
				r[j] = j;
				while (b[i][r[j] + 1] >= b[i][j])
					r[j] = r[r[j] + 1];
			}
			for (int j = 1; j <= N; j++)
			{
				if (b[i][j] * (r[j] - l[j] + 1) > area)
					area = b[i][j] * (r[j] - l[j] + 1);
			}
			//			-------------求c最大面积---------------
			l[0] = 1, r[N + 1] = N;
			c[i][0] = c[i][N + 1] = -1;
			for (int j = 1; j <= N; j++)
			{
				l[j] = j;
				while (c[i][l[j] - 1] >= c[i][j])
					l[j] = l[l[j] - 1];
			}
			for (int j = N; j >= 1; j--)
			{
				r[j] = j;
				while (c[i][r[j] + 1] >= c[i][j])
					r[j] = r[r[j] + 1];
			}
			for (int j = 1; j <= N; j++)
			{
				if (c[i][j] * (r[j] - l[j] + 1) > area)
					area = c[i][j] * (r[j] - l[j] + 1);
			}
		}
		printf("%d\n", area);
	}
	return 0;
}