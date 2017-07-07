#include <stdio.h>
int main(void)
{
	int n, i, sum = 0;
	while(scanf("%d", &n) != EOF)
	{
		sum = 0;
		for(i = 0; n > 0; i++)
		{
			sum = sum + n % (2);
			n = n / 2;
		}
		printf("%d\n",sum);
	}
	return 0;
}