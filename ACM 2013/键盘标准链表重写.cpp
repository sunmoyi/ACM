#include<cstdio>
#include<cstring>
char s[30];
int end, start, cur;
struct t{
	char c;
	char *a = NULL;
}word[26];
int main(void)
{
	while (scanf_s("%s", s + 1, 25) != EOF)
	{
		int flag = 0;
		int n = strlen(s + 1);
		for (int i = 1; i <= n; i++)
		{
			word[i].c = s[i];
			if (s[i] == '[')
			{
				flag--;
			}
			else if (s[i] == ']')
			{
				flag++;
			}
			else
			{
				if (s[i - 1] == '[')
				{
					word[0].a = &word[i].c;
					word[i].a = &word[start].c;
					start = i;
				}
				else if (s[i - 1] == ']')
				{
					word[end].a = &word[i].c;

				}
				else
				{
					word[i - 1].a = &word[i].c;
				}
				if (flag >= 0)
					end++;

			}
		}
		for (int i = 0;;)
		{
			printf("%c", *(word[i].a))

		}
	}

}