#include <stdio.h>
int main (void)
{
	int n, a, b, sum1, sum2, i, j, k;
	while(scanf("%d",&n) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			sum1 = 0; sum2 = 0;
			scanf("%d %d",&a,&b);
			for(j = 1; j < a; j++)
			{
				if(a % j == 0)
					sum1 = sum1 + j;
			}
			for(k = 1;k < b; k++)
			{
				if(b % k == 0)
					sum2 = sum2 + k;
			}
			if(sum1 == b && sum2 == a)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}