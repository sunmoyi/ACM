#include <stdio.h> 

int inv(int a)
{
	int b = 0;
	while (a)
	{
		b += a % 10;
		a = a / 10;
		if (a) b *= 10;
	}
	return b;
}
int main()
{
	int n, c[100];
	int count, i;
	while (scanf("%d", &n) != EOF)
	{
		count = 0;
		c[count] = n;
		while (n != inv(n))
		{
			n += inv(n);
			c[++count] = n;
		}
		printf("%d\n", count);
		for (i = 0; i <= count; i++)
		{
			if (i == 0)
				printf("%d", c[i]);
			else
				printf("--->%d", c[i]);
		}
		printf("\n");
	}
}