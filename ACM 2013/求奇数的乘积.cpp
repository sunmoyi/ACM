# include <stdio.h>
int main (void)
{
	long long n, a, i, sum;
	while(scanf("%lld",&n) != EOF)
	{
		sum = 1;
		for(i = 1; i <= n; i++)
		{
			scanf("%lld",&a);
			if(a % 2 == 1)
				sum = sum * a;;
		}
		printf("%lld\n",sum);
	}
	return 0;
}