#include<stdio.h>
int main(void)
{
	int j, i, a, sum, k;
	scanf("%d", &k);
	while (k--)
	{
		sum = 0;
		scanf("%d", &j);
		for (i = 0; i < j; i++)
		{
			scanf("%d", &a);
			sum = sum + a;
		}
		if (k != 0)
			printf("%d\n\n", sum);
		else
			printf("%d\n", sum);
	}
	return 0;
}