#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define letters 26

using namespace std;

int nNodeCount = 0;

struct node {
	node *childs[letters];
	node *pre;
	bool badnode;
	void init()
	{
		memset(childs, 0, sizeof(childs));
		badnode = false;
		pre = NULL;
	}
}tree[200];

void insert(node *root, char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (root->childs[s[i] - 'a'] == NULL)
		{
			root->childs[s[i] - 'a'] = tree + nNodeCount;
			nNodeCount++;
		}
		root = root->childs[s[i] - 'a'];
	}
	root->badnode = true;
}

void builddfs()
{
	for (int i = 0; i < letters; i++)
		tree[0].childs[i] = tree + 1;
	tree[0].pre = NULL;
	tree[1].pre = tree;
	deque<node*>q;
	q.push_back(tree + 1);
	while (!q.empty())
	{
		node * root = q.front();
		q.pop_front();
		for (int i = 0; i < letters; i++) 
		{
			node * p = root->childs[i];
			if (p) 
			{
				node * pre = root->pre;
				while (pre)
				{
					if (pre->childs[i])
					{
						p->pre = pre->childs[i];
						if (p->pre->badnode)
							p->badnode = true;
						//自己的pPrev指向的节点是危险节点，则自己也是危险节点
						break;
					}
					else
						pre = pre->pre;
				}
				q.push_back(p);
			}
		}
	} //对应于while( ! q.empty() )
}


bool searchdfs(char *s)
{
	node * p = tree + 1;
	for (int i = 0; s[i]; i++) 
	{
		while (true)
		{
			if (p->childs[s[i] - 'a']) 
			{
				p = p->childs[s[i] - 'a'];
				if (p->badnode)
					return true;
				break;
			}
			else
				p = p->pre;
		}
	}
	return false;
}

int main(void)
{
	nNodeCount = 2;
	int M, N;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		char s[20];
		scanf("%s", s);
		insert(tree + 1, s);
	}
	builddfs();
	for (int i = 0; i < M; i++)
	{
		char s[200];
		scanf("%s", s);
		if (searchdfs(s))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}