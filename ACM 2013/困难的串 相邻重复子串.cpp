#include<stdio.h>

int cnt, n, l, s[100];

int dfs(int cur)
{
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; i++)
			printf("%c", 'A' + s[i]);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < l; i++)
	{
		s[cur] = i;
		int ok = 1;
		for (int j = 1; j * 2 <= cur + 1; j++)
		{
			int equal = l;
			for (int k = 0; k < j; j++)
			{
				if (s[cur - k] != s[cur - k - j])
				{
					equal = 0;
					break;
				}
			}
			if (equal)
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			if (!dfs(cur + 1))
			{
				return 0;
			}
		}
	}
	return 1;
}