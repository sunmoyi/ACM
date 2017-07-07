#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int idx(char c) { return c - 'a'; }
struct Trie
{
	int cnt;
	struct Trie *next[26];
	Trie()
	{
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
};

Trie *root;
void Insert(char *word)
{
	Trie *p = root;
	for (int i = 0; word[i] != '\0'; i++)
	{
		int x = idx(word[i]);
		if (p->next[x] == NULL)
		{
			p->next[x] = new Trie;
		}
		p = p->next[x];
		p->cnt++;
	}
}

void Search(char *word)
{
	Trie *p = root;
	for (int i = 0; word[i] != '\0'; i++)
	{
		int x = idx(word[i]);
		if (p->cnt == 1)
		{
			break;
		}
		printf("%c", word[i]);
		p = p->next[x];
	}
	printf("\n");
}

char str[1005][25];
int main()
{
	int num = 0;
	root = new Trie;
	while (scanf("%s", str[num]) != EOF)
	{
		Insert(str[num]);
		num++;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%s ", str[i]);
		Search(str[i]);
	}
	return 0;
}
