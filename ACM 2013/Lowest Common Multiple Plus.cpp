# include <stdio.h>
int main (void)
{
	int n, a[100], i, j, flag, min;
	while(scanf("%d",&n) !=EOF)
	{
		for(i = 0 ; i < n; i ++)
		{
			scanf("%d",&a[i]);
		}
		for(j = 2; ; j++)
		{
			flag = 0;
			for(i = 0; i < n ; i++)
			{
				if(j%a[i] == 0)
					flag = flag + 1;
			}
			if(flag == n)
			{
				min = j;
				break;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}