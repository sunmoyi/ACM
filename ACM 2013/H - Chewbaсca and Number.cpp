#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100];
	int i, j, k, l, n, m;
	while (scanf_s("%s", a, 100) != EOF)
	{
		n = strlen(a);
		for (k = 0; k < n; k++)
		{
			if (k != 0 || a[k] != '9')
			{
				if ((a[k] - 48) >= 5)
					a[k] = (9 - a[k] + 48) + 48;
			}
		}
		for (l = 0; l < n; l++)
			printf("%c", a[l]);
		printf("\n");
		getchar();
	}
	return 0;
}