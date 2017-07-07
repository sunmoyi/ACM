#include<stdio.h>
#include<string.h>

const int hashsize = 10000000;
int head[hashsize], next[hashsize];
int st[100][100];

void init_lookup_table()
{
	memset(head, 0, sizeof(head));
}

int hash(int s[])
{
	int v = 0;
	for (int i = 0; i < 9; i++)
		v = v * 10 + s[i];
	return v % hashsize;
}

int try_to_intsert(int s)
{
	int h = hash(st[s]);
	int u = head[h];
	while (u)
	{
		if (memcmp(st[u], st[s], sizeof(st[s])) == 0)
			return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}