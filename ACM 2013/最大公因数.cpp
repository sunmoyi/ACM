#include<stdio.h>
int swap(int *a, int *b);
int goc(int i, int j);
int main(void)
{
	int n, m;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		printf("%d\n", goc(n, m));
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
int goc(int i, int j)
{
	int t;
	if (i < j)
		swap(&i, &j);
	t = i % j;
	if (t == 0)
		return j;
	else
		goc(j, t);
}
