/*
#include<cstdio>
#include<cstring>

int main(void)
{
	int n;
	char word[400];
	for (int i = 0; i < 400; i++)
		word[i] = 'A' + (i) % 26;
	while (scanf("%d", &n) != EOF)
	{
		int s = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = 1; j <= n / 2 - i + 1; j++)
				printf(".");
			for (int j = 1; j <= 2 * (i - 1) + 1; j++)
				printf("%c", word[s++]);
			for (int j = 1; j <= n / 2 - i + 1; j++)
				printf(".");
			printf("\n");
		}
		for (int i = 1; i <= n / 2 + 1; i++)
			printf("%c", word[s++]);
		s -= 2;
		for (int i = 1; i <= n / 2; i++)
			printf("%c", word[s--]);
		printf("\n");
		for (int i = n / 2; i >= 1; i--)
		{
			for (int j = 1; j <= n / 2 + 1 - i; j++)
				printf(".");
			for (int j = 1; j <= 2 * i - 1; j++)
				printf("%c", word[s--]);
			for (int j = 1; j <= n / 2 + 1 - i; j++)
				printf(".");
			printf("\n");
		}
	}
	return 0;
}
*/

#include<stdio.h>
int main(void)
{
	int i, n, max;
	int x, y;
	int number[3][3];
	printf("Input the number:");
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			scanf("%d", &number[i][n]);
		}
	}
	max = number[0][0];
	x = y = 0;
	for (i = 0; i < 3; i++)
	{
		for (n = 0; n < 3; n++)
		{
			if (number[i][n] > max)
			{
				max = number[i][n];
				x = i;
				y = n;
			}
		}
	}
	printf("%d:%d,%d\n", max, x, y);
	return 0;
}