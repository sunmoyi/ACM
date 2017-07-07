# include <stdio.h>
int main (void)
{
	int m, n;
	int i, a, b, c, ok, d, q[5];
	while(scanf("%d %d", &m, &n) == 2)
    {
		ok = 1;d=0;
		for(i = m; i <= n ; i++ )
		{
			a = i /100;
			b = (i - a * 100)/10;
			c = i - a*100 - b*10;
			if(i == a*a*a + b*b*b + c*c*c)
			{
				ok = 0;
				q[d] = i;
				d++;
			}
		}
		d--;
		if(ok)
			printf("no");
		else
		{
			for(i = 0; i < d ; i++)
				printf("%d " ,q[i]);
			printf("%d",q[d]);
		}
		printf("\n");
	}
	return 0;
}