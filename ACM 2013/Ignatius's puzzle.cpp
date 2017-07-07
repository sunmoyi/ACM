#include<stdio.h>
int gcd(int a, int b);
int swap(int *a, int *b);
int main(void)
{
	int i, k;
	while (scanf_s("%d", &k) != EOF)
	{
		
		if (18 % gcd(65, k) !=  0)
		{
			printf("no\n");
			continue;
		}
		for (i = 1;; i++)
		{
			if ((65 * i - 18) % k == 0)
			{
				printf("%d\n", (65 * i - 18) / k);
				break;
			}
		}
	}
	return 0;
}
int swap(int *a, int *b)
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
	return 0;
}
int gcd(int i, int j)
{
	int t;
	if (i < j)
		swap(&i, &j);
	t = i % j;
	if (t == 0)
		return j;
	else
		gcd(j, t);
}
