#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
int a[2100];
int b[15][2100];
int d[410][2100][15];
int e[15];
int ans[410][15];

int main(void)
{
	int i, j, u, p, q, n, m, pi, qi, OK;
	p = (1 << 11);
	b[1][0] = b[1][1] = 1;
	for (i = 2; i <= 11; i++)
	{
		p = (1 << i);
		for (j = 0; j < p; j++)
		{
			q = j;
			for (u = 1; u <= i; u++)
			{
				e[u] = q % 2;
				q /= 2;
			}
			OK = 1;
			for (u = 1; u <= i / 2; u++)
			{
				if (e[u] != e[i + 1 - u])
				{
					OK = 0;
					break;
				}
			}
			if (OK == 1)
			{
				b[i][j] = i;
			}
			else
			{
				q = (j&((1 << (i - 1)) - 1));
				b[i][j] = (b[i - 1][q] > b[i - 1][j / 2]) ? b[i - 1][q] : b[i - 1][j / 2];
			}
		}
	}
	for (i = 1; i <= 10; i++)
	{
		p = (1 << i);
		for (j = 0; j < p; j++)
		{
			for (u = b[i][j] + 1; u <= 10; u++)
			{
				ans[i][u]++;
			}
		}
	}
	p = (1 << 11);
	for (j = 0; j < p; j++)
	{
		a[j] = b[11][j];
	}
	for (j = 0; j < p; j++)
	{
		for (u = a[j] + 1; u <= 10; u++)
		{
			d[11][j][u]++;
			ans[11][u]++;
		}
	}
	for (i = 12; i <= 400; i++)
	{
		for (j = 0; j < p; j++)
		{
			for (u = 2; u <= 10; u++)
			{
				if (a[j] >= u)
				{
					d[i][j][u] = 0;
				}
				else
				{
					d[i][j][u] = (d[i - 1][j / 2][u] + d[i - 1][j / 2 + (1 << 10)][u]) % MOD;
					ans[i][u] = (ans[i][u] + d[i][j][u]) % MOD;
				}
			}
		}
	}
	scanf("%d", &pi);
	for (qi = 0; qi < pi; qi++)
	{
		scanf("%d%d", &n, &m);
		printf("%d\n", ans[n][m]);
	}
	return 0;
}