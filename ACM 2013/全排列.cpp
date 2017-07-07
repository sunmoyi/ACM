#include <stdio.h>

int n = 0, B[10];

double i = 0;
void perm(int list[], int n, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i > 0) printf(" ");
			printf("%d", B[i]);
		}
		i++;
		printf("      %.3lf%%\n", 100 * i / (3628800 * 1.0));

	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			B[cur] = list[i];
			// Хажи;
			int ok = 1;
			for (int i = 0; i < cur; ++i)
			{
				if (B[i] == B[cur])
				{
					ok = 0;
					break;
				}
			}
			if (ok)
				perm(list, n, cur + 1);
		}
	}
}
int main()
{
	int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	perm(list, 10, 0);
	return 0;
}