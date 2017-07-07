#include<stdio.h>
int main (void)
{
	signed int n, m, i, j, k, a, l, flag;
	while(scanf("%d %d", &n, &m) != EOF && n != 0 || m != 0)
	{
		flag = 0;
		if(m > 0)
		{
			for(i = 0 - m; i <= m; i++)
			{
				if(i != 0 && m % i == 0 && i + m / i == n)
						flag = 1;
			}
		}
		if(m <= 0)
		{
			for(i = m; i <= 0 - m; i++)
			{
				if(i != 0 && m % i == 0 && i + m / i == n)
					flag = 1;
			}
			
		}
		if(flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}