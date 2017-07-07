#include<stdio.h>
int a[100000];
int main(void)
{
	int i, j, k, l;
	while (scanf_s("%d", &i) != EOF && i != 0)
	{
		k = 0;
		for (j = 1; j <= i; j++)
		{
			scanf_s("%d", &a[i]);
			k = k ^ a[i];
		}
		printf("%d\n", k);
	}
	return 0;
}