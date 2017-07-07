#include<stdio.h>
#include<string.h>
int main(void)
{
	int a, b;
	char i, j, k, l[3], n;
	while (scanf_s("%d %c %d %*c %s", &j, &a, &k, l) != EOF)
	{
		i = strlen(l);
		printf("%d %c %d ", j, a, k);
		for (n = 0; n < i; n++)
			printf("%c\n\n\n", l[n]);
	}
	return 0;
}