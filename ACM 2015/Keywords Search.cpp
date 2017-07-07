#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010

using namespace std;

char str[maxn << 1], keyword[100];
int head, tail;

struct node {
	node *fail;
	node *next[26];
	int count;
	node()
	{
		fail = NULL;
		count = 0;
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}
}*q[maxn], *root;

void insert(char *str)
{
	int temp, len;
	node *p = root;
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		temp = str[i] - 'a';
		if (p->next[temp] == NULL)
			p->next[temp] = new node();
		p = p->next[temp];
	}
	p->count++;
}

void build_ac()
{
	q[tail++] = root;
	while (head != tail)
	{
		node *p = q[head++];
		node *temp = NULL;
		for (int i = 0; i < 26; i++)
		{
			if (p->next[i] != NULL)
			{
				if (p == root)
					p->next[i]->fail = root;
				else
				{
					temp = p->fail;
					while (temp != NULL)
					{
						if (temp->next[i] != NULL)
						{
							p->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp->fail;
					}
					if (temp == NULL)
						p->next[i]->fail = root;
				}
				q[tail++] = p->next[i];
			}
		}
	}
}

int query()
{
	int index, len, result;
	node *p = root;
	result = 0;
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		//printf("%d\n", i);
		index = str[i] - 'a';
		while (p->next[index] == NULL && p != root)
			p = p->fail;
		p = p->next[index];
		if (p == NULL)
			p = root;
		node *temp = p;
		while (temp != root && temp->count != -1)
		{
			result += temp->count;
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return result;
}

int main(void)
{
	int icase, num;
	scanf("%d", &icase);
	while (icase--)
	{
		head = tail = 0;
		root = new node();
		scanf("%d", &num);
		getchar();
		for (int i = 0; i < num; i++)
		{
			scanf("%s", keyword);
			insert(keyword);
		}
		build_ac();
		scanf("%s", str);
		printf("%d\n", query());
	}
	return 0;
}