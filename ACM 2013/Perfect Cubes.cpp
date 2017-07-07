#include <stdio.h>
int main(void)
{
	int i, k, j, l, a;
	for (i = 6; i <= 200; i++)
	{
		for (j = 2; j < i ; j++)
		{
			for (k = j + 1; k < i ; k++)
			{
				for (l = k + 1; l < i; l++)
					if (i * i * i == j * j * j + k * k * k + l * l * l)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
			}
		}
	}
	return 0;
}