#include<stdio.h>
int main (void)
{
	int n, m, i, j, k, a, b, c;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for( i = n ; i <= m; i++ )
		{
			a = i / 100;
			b = (i - a * 100) / 10;
			c = i % 10;
			if(a * a * a + b * b * b + c * c * c == i)
				printf("%d\n", i);
		}
	}
	return 0;
}