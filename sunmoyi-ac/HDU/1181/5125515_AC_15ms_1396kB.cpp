#include<stdio.h>
#include<string.h>

struct node {
	char s;
	int mark;
	char e;
}s[1000];
int k;
int flag;

int dfs(char a)
{
	if (a == 'm')
	{
		flag = 1;
		return 1;
	}
	if (flag == 1)
		return 1;
	for (int i = 0; i < k; i++)
	{
		if (!s[i].mark && s[i].s == a)
		{
			s[i].mark = 1;
			dfs(s[i].e);
			s[i].mark = 0;
		}
	}
	return 0;
}

int main(void)
{
	char in[100];
	while (gets(in))
	{
		k = 0;
		while (in[0] != '0')
		{
			s[k].s = in[0];
			s[k].e = in[strlen(in) - 1];
			s[k].mark = 0;
			k++;
			gets(in);
		}

		flag = 0;
		dfs('b');
		if (flag)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}
