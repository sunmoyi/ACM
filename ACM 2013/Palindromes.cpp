#include<cstdio>
#include<cstring>
#include<cctype>

char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char *msg[] = { " -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.", " -- is a mirrored palindrome." };

char r(char r)
{
	if (isalpha(r))
		return rev[r - 'A'];
	return
		rev[r - '0' + 25];
}

int main(void)
{
	char s[30];
	while (scanf("%s", s) == 1)
	{
		int len = strlen(s);
		int p = 1; int m = 1;
		for (int i = 0; i < (len - 1) / 2; i++)
		{
			if (s[i] != s[len - i - 1])
				p = 0;
			if (r(s[i]) != s[len - i - 1])
				m = 0;
		}
		printf("%s%s\n\n", s, msg[m * 2 + p]);
	}
	return 0;
}