#include<stdio.h>
#include<string.h>
char s1[1009], s2[1009];
int c[1009][1009];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int i, j, n, m;
	while (scanf("%s %s", s1 + 1, s2 + 1) != EOF)//×Ö·û±àºÅ´Ó1¿ªÊ¼£¡
	{

		n = strlen(s1 + 1);
		m = strlen(s2 + 1);
		for (i = 1; i <= n; i++)
			c[i][0] = 0;
		for (j = 1; j <= m; j++)
			c[0][j] = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				if (s1[i] == s2[j])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
					c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		printf("%d\n", c[n][m]);

	}
	return 0;
}