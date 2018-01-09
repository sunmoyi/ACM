#include<cstdio>
#include<cstring>
#define N 30
#define M 30
#define ys 1
#define yx 2
#define zs 3
#define zx 4
int rank[N + 5][M + 5];

int main()
{
	int i, j;
	while (scanf("%d%d", &i, &j)!=EOF)
	{
		int nowx = 1, nowy = 1;
		memset(rank, 0, sizeof(rank));
		int dire = yx;
		do
		{
			rank[nowx][nowy]++;
			if (dire == yx)
			{
				nowx++;
				nowy++;

			}
			else if (dire == ys)
			{
				nowx--;
				nowy++;
			}
			else if (dire == zs)
			{
				nowx--;
				nowy--;
			}
			else if (dire == zx)
			{
				nowx++;
				nowy--;
			}

			if (nowx == 1)
			{
				if (dire == ys)dire = yx;
				else if (dire == zs)dire = zx;
			}
			else if (nowx == i)
			{
				if (dire == yx)dire = ys;
				else if (dire == zx)dire = zs;
			}
			else if (nowy == 1)
			{
				if (dire == zs)dire = ys;
				else if (dire == zx)dire = yx;
			}
			else if (nowy == j)
			{
				if (dire == yx)dire = zx;
				else if (dire == ys)dire = zs;
			}
		} while (!((nowx == 1 || nowx == i) && (nowy == 1 || nowy == j)));
		rank[nowx][nowy]++;
		int ans = 0;
		for (int k = 1; k <= i; k++)
		{
			for (int p = 1; p <= j; p++)
			{
				if (rank[k][p] > 0)printf("*");
				else printf("-");
			}
			printf("\n");
		}

	}
}