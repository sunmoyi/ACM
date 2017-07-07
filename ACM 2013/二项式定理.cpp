# include<stdio.h>
int erxiangshi(int a, int b);
int main (void)
{
	long n, m, i, j, k, s[30];
	while(scanf("%d", &n) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < n/2; j++)
			{
				s[j] = erxiangshi( j, i - 1);
				printf("%d ", s[j]);
			}
			for(k =(n / 2 + 1); k <=n ; k++)
			{
				if(k != n)
					printf("%d ",s[n - k]);
				else
					printf("1\n");
			}
			printf("\n");
		}
		return 0;
	}

}
	int erxiangshi(int a, int b)
	{
		unsigned long long s = 1, z = 1, k, t;
		if(a != 0)
		{
			for(k = b; k >= b - a + 1; k--)
				s = s * k;
			for(k = 1; k <= a ; k++)
				z = z * k;
			//printf("s = %d z = %d", s, z);
			t = (s/z);
			return t;
		}
		else
			return 1;
	}