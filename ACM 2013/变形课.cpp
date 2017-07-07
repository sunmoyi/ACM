#include<stdio.h>
#include<string.h>

struct node {
	char s;
	int mark;
	char e;
}s[1000];
int k;
int flag;
int judge;
int dfs(char a);

int main(void)
{
	char in[100];
	while (gets_s(in, 99))
	{
		k = 0;
		judge = 0;
		while (in[0] != '0')
		{
			s[k].s = in[0];
			s[k].e = in[strlen(in) - 1];
			k++;
			if (in[0] == 'b') judge++;
			if (in[0] == 'm') judge++;
			gets_s(in, 99);
		}
		if (judge < 2)
		{
			printf("No.\n");
			continue;
		}
		flag = 0;
		for (int i = 0; i < k; i++)
			s[i].mark = 0;
		dfs('b');
		if (flag)
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}
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