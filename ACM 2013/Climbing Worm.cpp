#include<stdio.h>
#include<string.h>

int main(void)
{
	int n, u, d, i, j, k, t;
	while (scanf_s("%d %d %d", &n, &u, &d) != EOF && (n + u + d))
	{
		t = 0;
		for (i = n; i > u; i -= (u - d))
			t += 2;
		t++;
		printf("%d\n", t);
	}
	return 0;
}