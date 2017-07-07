#include<stdio.h>
int main (void)
{
	long n, a, b,i, j, k, l, flag = 0;
	while(scanf("%d",&n) !=EOF)
	{ 
		flag = 0;
		for(i = 1; i <= n; i++)
		{
			if(n % i == 0)
				flag = flag + 1;
		}
		if(flag % 2 == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}