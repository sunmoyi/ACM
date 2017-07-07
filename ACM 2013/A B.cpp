# include <stdio.h>
int main (void)
{
	long long n, a, b, i, j;
	while(scanf("%lld", &n) != EOF)
	{
		for(i = 1; i<= n; i++)
		{
			scanf("%lld %lld", &a, &b);
			if(a % b == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}