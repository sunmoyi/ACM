#include<stdio.h>
int main(void)
{
	int h, u, d, f, i;
	double l, down;
	while (scanf_s("%d %d %d %d", &h, &u, &d, &f) != EOF && h != 0)
	{
		l = 0;
		for (i = 1; ; i++)
		{
			down = (i - 1) * u * f * 0.01;
			if (down <= u)
				;
			else
				down = u;
			l = l + u - down;
			if (l > h)
				break;
			l = l - d;
			if (l < 0)
				break;
		}
		if (l >= h)
			printf("success on day %d\n", i);
		if (l <= 0)
			printf("failure on day %d\n", i);
	}
	return 0;
}