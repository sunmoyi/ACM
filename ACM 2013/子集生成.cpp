

#include<stdio.h>
/*增量构造*/
/*
void print_subset(int n, int a[], int cur)
{
	for (int i = 0; i < cur; i++)
	{
		printf("%d ", a[i]);
		printf("\n");
	}
	int s = cur ? a[cur - 1] + 1 : 0;
	for (int i = s; i < n; i++)
	{
		a[cur] = i;
		print_subset(n, a, cur + 1);
}
*/

/*位向量法*/
/*
void printf_subset(int n, int b[], int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			if (b[i])
				printf("%d	", i);
		printf("\n");
		return;
	}
	b[cur] = 1;
	printf_subset(n, b, cur + 1);
	b[cur] = 0;
	printf_subset(n, b, cur + 1);
}
*/

