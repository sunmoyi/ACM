#include<stdio.h>
#include<string.h>
int map[35][35], v[35][35], n;
void print1()
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (j)
				printf(" %d", map[i][j]);
			else
				printf("%d", map[i][j]);
		}
		printf("\n");
	}
}
void print2()
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (j)
				printf(" %2d", map[i][j]);
			else
				printf("%2d", map[i][j]);
		}
		printf("\n");
	}
}
void print3()
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (j)
				printf(" %3d", map[i][j]);
			else
				printf("%3d", map[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	//int n;
	while (scanf("%d", &n) != EOF, n)
	{
		int j = n / 2, i = n - 1, cot = 1, m = n*n;
		memset(v, 0, sizeof(v));
		while (cot <= m)
		{
			if (v[i][j] || (i >= n&&j >= n))
			{
				i -= 2;
				j--;
			}
			else
			{
				if (i >= n)
				{
					i = 0;
				}
				else
					if (j >= n)
					{
						j = 0;
					}
			}
			map[i][j] = cot++;
			v[i][j] = 1;
			i++;
			j++;
		}
		if (n <= 3)
		{
			print1();
		}
		else
		{
			if (n <= 9)
				print2();
			else
				print3();
		}
		printf("\n");
	}
}