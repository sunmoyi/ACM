#include <stdio.h>
int main (void)
{
	int i, j, k, l,sum10, sum12, sum16, a, b, c, d;
	for (i = 2991; i <= 9999; i++)
	{
		sum10 = sum12 = sum16 = 0;
		j = i;
		for (k = 1; j > 0; k++)
		{
			sum10 = sum10 + j % 10;
			j = j / 10;
		}
		j = i;
		for (k = 1; j > 0; k++)
		{
			sum12 = sum12 + j % 12;
			j = j / 12;
		}
		j = i;
		for (k = 1; j > 0; k++)
		{
			sum16 = sum16 + j % 16;
			j = j / 16;
		}
		if (sum10 == sum12 && sum12 == sum16)
			printf("%d\n", i);
	}
	return 0;
}