# include<stdio.h>
# include <string.h>
int main (void)
{
	int n, i, j, len, sum;
	char s[1000];
	while(scanf("%d", &n) !=EOF)
	{
		getchar();
		for(i = 0; i < n ; i++)
		{
			sum = 0;
			gets(s);
			len = strlen(s);
			for(j = 0 ; j < len; j++)
			{
				if(s[j] < 0)
					sum =sum + 1;
			}
			sum = sum / 2;
			printf("%d\n",sum);
	}
	return 0;
}
		}