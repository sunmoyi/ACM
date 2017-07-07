# include<stdio.h>
int main (void)
{
	int h[3], min[3], sec[3], i, n, flag;
	while(scanf("%d", &n) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			flag = 0;
			scanf("%d %d %d %d %d %d",&h[0],&min[0],&sec[0],&h[1],&min[1],&sec[1]);
			sec[2] = sec[0] + sec[1];
			if(sec[2] >= 60)
			{
				sec[2] = sec[2] - 60;
				flag = 1;
			}
			min[2] = min[0] + min [1] + flag;
			if(min[2] >= 60)
			{
				min[2] = min[2] - 60;
				flag = 1;
			}
			h[2] = h[0] + h[1] + flag;
			printf("%d %d %d\n" , h[2], min[2], sec[2]);

		}
	}
	return 0;
}