# include<stdio.h>
# include<math.h>
int main(void)
{
	int a, b, n, i, e;
	char c;
	double d;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			getchar();
			scanf("%c %d %d", &c, &a, &b);
			if (c == '+')
				printf("%d\n", a + b);
			if (c == '-')
				printf("%d\n", a - b);
			if (c == '*')
				printf("%d\n", a * b);
			if (c == '/')
			{
				if (a / b * b == a)
					printf("%d\n", a / b);
				else
					printf("%.2f\n", (double)a / b);
			}
		}
	}
	return 0;
}