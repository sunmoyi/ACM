#include<stdio.h>
int main(void)
{
	int num, i, j, k, l;
	while (scanf_s("%d", &num) != EOF)
	{
		l = 0;
		for (i = 1; i * i < num; i++)
		{
			for (j = i; j * j < num; j++)
			{
				for (k = i; k * k < num; k++)
				{
					if (k * k + j * j + i * i == num)
					{
						printf("%d %d %d\n", i, j, k);
						l = 1;
						break;
					}
				}
				if (l == 1)
					break;
			}
			if (l == 1)
				break;
		}

	}
	return 0;
}