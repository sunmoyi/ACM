#include <stdio.h>
int main (void)
{
	int i, j, k, a, b;
	while(scanf("%d", &k) != EOF)
	{
		for( i =1; i <= k; i++)
		{
			scanf("%d %d", &a, &b);
			j = a + b;
			printf("%d\n", j);
		}
	}
	return 0;
}