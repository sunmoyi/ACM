#include <stdio.h>
int main (void)
{
	int a, n, sum10, sum12, sum16, i, j, k;
	while(scanf("%d",&a) !=EOF && a != 0)
	{
		sum10 = sum12 = sum16 = 0;
		n = a;
		for(i = 1; i <= 4; i++)
		{
			sum10 = sum10 + a % 10;
			a = a / 10;
		}
		a = n;
		for(j = 1; a > 0; j++)
		{
			sum12 = sum12 + a % 12;
			a = a / 12;
		}
		a = n; 
		for(k = 1; a > 0; k++)
		{
			sum16 = sum16 + a % 16;
			a = a / 16;
		}
		if(sum12 == sum10 && sum10 == sum16)
			printf("%d is a Sky Number.\n",n);
		else
			printf("%d is not a Sky Number.\n",n);
	}
	return 0;
}