# include<stdio.h>
int main(void)
{
	int a, b;

	for (; scanf("%d %d", &a, &b) != EOF && (a != 0) || (b != 0);)
	{
		printf("%d\n", a + b);
	}
	return 0;
}