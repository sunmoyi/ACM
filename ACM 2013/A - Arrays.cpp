#include<stdio.h>
signed int q[100005], p[100005];
int main(void)
{
	int n, m, a, b, i, j, k, l;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		scanf_s("%d %d", &a, &b);
		for (i = 1; i <= n; i++)
			scanf_s("%d", &q[i]);
		for (i = 1; i <= m; i++)
			scanf_s("%d", &p[i]);
		if (q[a] < p[m - b + 1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
