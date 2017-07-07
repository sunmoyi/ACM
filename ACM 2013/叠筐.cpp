# include <stdio.h>
int main (void)
{
	int n, i, j, k, l, m, flag;
	char q, p;
	while(scanf("%d %c %c", &n, &q, &p) != EOF)
	{
		printf(" ");
		for(i = 2; i <= n - 1; i++)
			printf("%c", p);
		printf(" \n");         // 1Ϊq     -1 Ϊp
		flag = 1;
		for(i = 1; i <= n; i++)
		{
			printf("%c", p);

		}
	}
}