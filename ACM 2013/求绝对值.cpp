# include <stdio.h>
int main (void)
{
	double a;
	while(scanf("%lf",&a) != EOF)
	{
		if(a >= 0)
			printf("%.2lf\n", a);
		else
		{
			a = -a;
			printf("%.2lf\n",a);
		}
	}
	return 0;
}