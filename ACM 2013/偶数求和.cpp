# include<stdio.h>
int main (void)
{
	int  n, m, i, average[100], a[100], k, j,sum, x, d;

	while(scanf("%d %d", &n, &m) == 2)
	{
		for(i = 0 ; i < n ; i++)
		{
			a[i] = 2 * (i + 1);
		}
		for(k = 1 , d = 0; k <= n/m ; k++)
		{
			sum = 0; 
			for(j = k * m - m ; j < k * m ; j++)
			{
				sum = sum + a[j];
			}
			average [d] = sum / m;
			d++;
		}
		sum = 0; 
		d--;
		if(m * (n / m) != n)
		{
			for(x = m * (n / m) ;  x < n; x++)
			{
				sum = sum + a [x];
			}
			d++;
			average[d] = sum / (n - m * (n / m) );
		}
		for(int i = 0 ; i <= d ; i++)
		{
			if(i != d)
				printf("%d ",average[i]);
			else
				printf("%d",average[i]);
		}
		printf("\n");
	}
	return 0;
}
