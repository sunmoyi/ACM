#include<stdio.h> 
int main(void)
{
	char c;
	int n, i, j, kase = 1;
	while (scanf_s("%c", &c) != EOF)
	{
		if (c == '@')
			break;
		if (kase)
			kase = 0;
		else
			printf("\n");
		scanf_s("%d", &n);
		getchar();        
		for (i = 1; i < n; i++)
		{
			for (j = 1; j < n + i; j++)
			{
				if (j == n + 1 - i || j == n + i - 1)
					printf("%c", c);
				else
					printf(" ");
			}     printf("\n");
		}
		for (i = 0; i < 2 * n - 1; i++)
			putchar(c);
		printf("\n");
		//getchar();   
	}
	return 0;
}