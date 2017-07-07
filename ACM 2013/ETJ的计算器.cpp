#include<stdio.h>
#include<string.h>
int main(void)
{
	int a, b, i, j, k, l;
	while (scanf("%d %d", &a, &b) != EOF && a != 0 || b !=0 )
	{
			k = 1;
		while (b != 0)
		{
			if (b % 2 == 1)
			{
				k = k * a;
				b--;
				k = k % 1000;
			}
			else
			{
				a = a * a;
				b /= 2;
				a = a % 1000;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}