#include <stdio.h>
int main (void)
{
	int n, m, i, j, k, a10, a100, flag, sum;
	while(scanf("%d %d", &n, &m) != EOF && n != 0 || m != 0)
	{
		sum = 0;
		for(i = n; i <= m; i++)
		{
			j = i;
			flag = 1;
			for(;j > 0;)
			{
				a10 = j % 10;
				if(a10 == 4)
				{
					flag = 0;
					break;
				}
				a100 = j % 100;
				if(a100 == 62)
				{
					flag = 0;
					break;
				}
				j = j / 10;
			}
			if(flag)
				sum = sum + 1;
		}
		printf("%d\n",sum);
	}
	return 0;
}