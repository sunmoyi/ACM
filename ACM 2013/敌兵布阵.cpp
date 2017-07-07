#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lowbit(int a);
int sum2(int a[], int k);
void add(int i, int x, int c[]);
int n;
int b[100000];
int c[100000];
char d[10];
int main(void)
{
	int i, j, k, l, a, change1, change2, sum, v;
	
	while (scanf_s("%d", &a) != EOF)
	{
		for (i = 1; i <= a; i++)
		{
			memset(b, 0, sizeof(b)); memset(c, 0, sizeof(c)); 
			scanf_s("%d", &n);
			for (j = 1; j <= n; j++)
				scanf_s("%d", &b[j]);
			for (k = 1; k <= n; k++)
				for (l = k - lowbit(k) + 1; l <= k; l++)
					c[k] += b[l];
			printf("Case %d:\n", i);
			getchar();
			scanf_s("%s", d, 10);
			while (d[0] != 'E')
			{
				scanf_s("%d %d", &change1, &change2);
				if (d[0] == 'Q')
				{
					sum = 0; v = change1 - 1;
					sum = sum2(c, change2) - sum2(c, v);
					//printf("%d %d  ", sum2(c, v), sum2(c, change2));
					printf("%d\n", sum);
				}
				else if (d[0] == 'A')
				{
					add(change1, change2, c);
				}
				else
				{
					add(change1, -(change2), c);
				}
				getchar();
				scanf_s("%s", d, 10);
			}
		}
	}
	return 0;
}
int lowbit(int a)
{
	return a & (-a);
}
int sum2(int a[], int k)
{
	int sum = 0;
	while (k > 0)
	{
		sum += a[k];
		k -= lowbit(k);
	}

	return sum;
}
void add(int i, int x, int c[])
{
	while (i <= n)
	{
		c[i] += x;
		i += lowbit(i);
	}
}