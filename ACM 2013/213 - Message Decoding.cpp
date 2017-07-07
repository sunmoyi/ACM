#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char code[8][256], s[256];

int my_gets(char *s)
{
	int k;
	while ((k = getchar()) == '\n');
	if (k == -1)
		k = 0;
	else
		gets(s + 1);
	s[0] = k;
	return strlen(s);
}

void init()
{
	int i, j, k = 0;
	for (i = 1;; i++)
	{
		for (j = 0; j < (1 << i) - 1; j++)
		{
			code[i][j] = s[k++];
			if (!s[k])
				return;
		}
	}
}

int read()
{
	char ch;
	while ((ch = getchar()) == '\n');
	return ch - '0';
}

int readint(int c)
{
	int v = 0;
	while (c--)
	{
		v = (v << 1) + read();
	}
	return v;
}

int main(void)
{
	int len, v;
	while (my_gets(s))
	{
		init();
		while (len = readint(3))
		{
			while ((v = readint(len)) != (1 << len) - 1)
				putchar(code[len][v]);
		}
		printf("\n");
	}
	return 0;
}