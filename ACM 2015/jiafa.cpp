#include <stdio.h>
#include <string.h>
int main()
{
	int n, i, j, k, mark, x, y, p, q;
	char a[10000] = {}, b[10000] = {}, c[10000] = {};
	scanf("%s%s", a, b);
	p = x = strlen(a);
	q = y = strlen(b);
	mark = 0;
	for (j = 0; x >= 0 || y >= 0; ++j, --x, --y)
	{
		if (x < 0)
		{
			c[j] = b[y] + mark;
			mark = 0;
		}
		if (y < 0)
		{
			c[j] = a[x] + mark;
			mark = 0;
		}
		if (x >= 0 && y >= 0)
		{
			c[j] = a[x] + b[y] + mark - '0';
			mark = 0;
		}
		if (c[j] >= '0' + 10)
		{
			c[j] -= 10;
			mark = 1;
		}
	}
	--j;
	if (mark == 1)
	{
		++j;
		c[j] = '1';
	}
	for (; j > 0; --j)
		printf("%c", c[j]);
	printf("\n");
	return 0;
}