# include <stdio.h>
# include <string.h>
int main(void)
{
	int n, i, j, len, flag;
	char s[100];

	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (i = 0; i < n; i++)
		{
			gets(s);
			len = strlen(s);
			flag = 1;
			if (len % 2 == 0)
			{
				for (j = 0; j <= len / 2; j++)
				{
					if (s[j] != s[len - 1 - j])
						flag = 0;
				}

			}
			else
			{
				for (j = 0; j <= (len - 1) / 2; j++)
				{
					if (s[j] != s[len - 1 - j])
						flag = 0;
				}
			}
			if (flag)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}