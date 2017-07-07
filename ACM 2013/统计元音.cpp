# include <stdio.h>
# include <string.h>
int i;
int main (void)
{
	int n, j, sum[6] = {0}, len,k;
	char s[100];
	while(scanf("%d", &n) != EOF)
	{
		getchar();
		for( i = 0 ; i < n ; i++)
		{
			for(k = 0; k < 6 ; k++)
				sum[k] = 0;
			gets(s);
			len = strlen(s);
			for( j = 0 ; j < len ; j++)
			{
				if(s[j] == 'a')
					sum[1] = sum [1] + 1;
				if(s[j] == 'e')
					sum[2] = sum [2] + 1;
				if(s[j] == 'i')
					sum[3] = sum [3] + 1;
				if(s[j] == 'o')
					sum[4] = sum [4] + 1;
				if(s[j] == 'u')
					sum[5] = sum [5] + 1;
			}
			if(i != n -1)
				printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n",sum[1],sum[2],sum[3],sum[4],sum[5]);
			if(i == n - 1)
				printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",sum[1],sum[2],sum[3],sum[4],sum[5]);
		}
		

	}
	return 0;
}