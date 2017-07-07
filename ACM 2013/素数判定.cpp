#include<stdio.h>
int sushu(int a)
{
	for (int i = 2; i < a; i++)
		if (a % i == 0)
			goto end;
	return 1;
	end:return 0;
}
int main(void)
{
	int n;
	while (scanf_s("%d", &n) != EOF)
	{
		if (sushu(n))
			printf("%d is a primer\n", n);
		else
			printf("%d is not a primer", n);
	}
	return 0;
}