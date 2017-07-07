#include <stdio.h>
int main (void)
{
	int  n, m, i, j;
	float a, max;
	while(scanf("%d",&n) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			max = 0;
			scanf("%d", &m);
			for(j = 1; j <= m; j++)
			{
				scanf("%f",&a);
				if(a > max)
					max = a;
			}
			printf("%.2f\n", max);
		}
	}
	return 0;
}