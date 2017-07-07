#include<stdio.h>
#include<string.h>
int n, k;
int a[25];
int b[40];
int c[25];
void DFS(int n, int cur);
int main(void)
{
	for (int i = 1; i < 40; i++)
	{
		b[i] = 1;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				b[i] = 0;
	}
	k = 0;
	while (scanf("%d", &n) != EOF)
	{
		k++;
		printf("Case %d:\n", k);
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		a[1] = 1;
		DFS(n, 2);
		printf("\n");
	}
	return 0;
}
void DFS(int n, int cur)
{
	if (cur - 1 == n  && b[a[cur - 1] + a[1]] == 1)
	{
		for (int i = 1; i < n; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n]);
	}
	else
	{
		int i;
		for (i = 2; i <= n; i++)
		{
			if (c[i] == 0 && b[a[cur - 1] + i] == 1)
			{
				c[i] = 1;
				a[cur] = i;
				DFS(n, cur + 1);
				c[i] = 0;
			}
		}
	}
}