#include<stdio.h>

int maxx;

void printN(int n)
{
	while (n > 0)
	{
 		printN( n - 1);
		printf("%d\n", n);
		return;
	}
}

int main(void)
{
	while (scanf_s("%d", &maxx))
		printN(maxx);
	return 0;
}