#include<stdio.h>
char word(int a);
int main(void)
{
	int i, j, k, l, n, m, a = 0;
	for (i = 3; i <= 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c", word(a + j - 1));
			for (k = 1; k <= i - 1 - j; k++)
				printf(" ");
			if (j >= 2 && j != i)
				printf("%c", word(a + 2 * i - j - 1));
			for (k = j - 2; k >= 1; k--)
				printf(" ");
			printf("%c\n", word(a + 2 * i - 3 + j));
		}
		//printf("\n");
		a = a + 3 * j - 5;
	}
	return 0;
}
char word(int a)
{
	char s;
	s = a % 26 + 'a';
	return s;
}