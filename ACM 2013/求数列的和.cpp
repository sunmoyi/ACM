# include <stdio.h>
# include <math.h>
int main (void)
{
	int m ,i;
	float sum ,n;
	
	while( scanf("%f  %d", &n, &m) != EOF )
	{
		sum = n;
		for(i = 1;i < m ;i++)
		{
			sum = sum + sqrt(n);
			n = sqrt(n);
		}
		printf("%.2f\n", sum);
	}
	return 0;

}