#include<stdio.h>
#include<cmath>
int main (void)
{
	int n, m, i, k;
	while (scanf_s("%d %d %d", &n, &m, &k) != EOF)
	{
		n = abs(n);
		m = abs(m);
		if (k < (n + m))
			printf("No\n");
		else if ((k - n - m) % 2 == 1)
			printf("NO\n");
		else
			printf("Yes\n");
	}
	return 0;
}