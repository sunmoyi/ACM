#include<stdio.h>
int main (void)
{
	int a, b, i, j, k, l;
	while(scanf("%d %d", &a,&b) != EOF)
	{
		printf("+");
		for(i = 1; i <= a; i++)
			printf("-");
		printf("+\n");

		for(j =1; j <= b; j++)
		{
			for(k = 1; k <= a + 1; k++)
			{
				if(k == 1)
					printf("|");
				if(k == a + 1)
					printf("|\n");
				else
					printf(" ");
			}
		}
		printf("+");
		for(i = 1; i <= a; i++)
			printf("-");
		printf("+\n\n");
	}
	return 0;
}