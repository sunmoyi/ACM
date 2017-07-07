#include <stdio.h>
int main (void)
{
	double n, m, sum1 = 0, sum = 0;
	int i, j, k, a, sum2, flag;
	while(scanf("%*s %lf %lf", &n, &m) != EOF)
	{
		flag = 0;
		sum1 = n * m;
		sum2 = (sum1 * 100);
		if(sum2 % 10 >= 5)
			flag = 1;
		sum2 = sum2 / 10;
		sum1 = sum2 / 10.0;
		sum = sum + sum1 + flag / 10.0;
	}
	printf("%.1f\n", sum);
	return 0;
}