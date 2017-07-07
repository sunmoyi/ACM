# include<stdio.h>
int main(void)
{
	int n, a, i, j, k, sum;
	char m;
	while (scanf_s("%d", &n) != EOF)
	{

		for (i = 1; i <= n; i++)
		{
			getchar();
			sum = 0;
			scanf("%c %d", &m, &a);
			if (m >= 64 && m <= 90)
				sum = (int)m - 64 + a;
			if (m >= 97 && m <= 122)
				sum = 96 - (int)m + a;
			printf("%d\n", sum);
		}
	}
	return 0;
}