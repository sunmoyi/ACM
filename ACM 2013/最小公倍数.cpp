#include<stdio.h>
int main (void)
{
	int n, m, i, j, k, l, temp;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n < m)
		{
			temp = n;
			n = m; 
			m = temp;
		}
		l = n * m;;
		while(m != 0)
		{
			k = n % m;
			n = m;
			m = k;
		}
		printf("%d\n", l / n);
	}
	return 0;
}
