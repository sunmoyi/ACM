# include <stdio.h>
int main(void)
{
	int a, b, c, d, i, j;


	while (scanf("%d", &a) != EOF)
	{
		for (i = 1; i <= a; i++)
		{

			d = 0;
			scanf("%d", &b);
			for (j = 1; j <= b; j++)
			{
				scanf("%d", &c);
				d = d + c;
			}
			printf("%d\n", d);
		}
	}
	return 0;
}