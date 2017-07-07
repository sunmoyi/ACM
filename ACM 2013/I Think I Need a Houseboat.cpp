#include <stdio.h>  
#include <math.h>  
#define PI 3.1415926  
int main()
{
	int n, i;
	double x, y;
	scanf("%d", &n);
	i = 1;
	while (n--)
	{
		scanf("%lf%lf", &x, &y);
		printf("Property %d: This property will begin eroding in year %d.\n", i++, 
			(int)(PI * (x*x + y*y) / 100) + 1);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}