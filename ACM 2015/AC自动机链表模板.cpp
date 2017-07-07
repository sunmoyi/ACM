#include <iostream>
#include <vector>
#include <queue>
#define LETTERS 26

using namespace std;

int nNodesCount = 0;
struct CNode
{
	CNode * pChilds[LETTERS];
	CNode * pPrev; //前缀指针
	bool bBadNode; //是否是危险节点
	void Init() {
		memset(pChilds, 0, sizeof(pChilds));
		bBadNode = false;
		pPrev = NULL;
	}
};
CNode Tree[200]; //10个模式串，每个10个字符，每个字符一个节点，也只要100个节点

void Insert(CNode * pRoot, char * s)
{//将模式串s插入trie树
	for (int i = 0; s[i]; i++)
	{
		if (pRoot->pChilds[s[i] - 'a'] == NULL)
		{
			pRoot->pChilds[s[i] - 'a'] =Tree + nNodesCount;
			nNodesCount++;
		}
		pRoot = pRoot->pChilds[s[i] - 'a'];
	}
	pRoot->bBadNode = true;
}

void BuildDfa()
{ //在trie树上加前缀指针
	for (int i = 0; i < LETTERS; i++)
		Tree[0].pChilds[i] = Tree + 1;
	Tree[0].pPrev = NULL;
	Tree[1].pPrev = Tree;
	deque<CNode * > q;
	q.push_back(Tree + 1);
	while (!q.empty()) 
	{
		CNode * pRoot = q.front();
		q.pop_front();
		for (int i = 0; i < LETTERS; i++)
		{
			CNode *p = pRoot->pChilds[i];
			if (p) 
			{
				CNode * pPrev = pRoot->pPrev;
				while (pPrev)
				{
					if (pPrev->pChilds[i]) 
					{
						p->pPrev =
							pPrev->pChilds[i];
						if (p->pPrev->bBadNode)
							p->bBadNode = true;
						//自己的pPrev指向的节点是危险节点，则自己也是危险节点
						break;
					}
					else
						pPrev = pPrev->pPrev;
				}
				q.push_back(p);
			}
		}
	} //对应于while( ! q.empty() )
}

bool SearchDfa(char * s)
{//返回值为true则说明包含模式串
	CNode * p = Tree + 1;
	for (int i = 0; s[i]; i++)
	{
		while (true) 
		{
			if (p->pChilds[s[i] - 'a']) 
			{
				p = p->pChilds[s[i] - 'a'];
				if (p->bBadNode)
					return true;
				break;
			}
			else
				p = p->pPrev;
		}
	}
	return false;
}

int main() 
{
	nNodesCount = 2; int M, N;
	scanf("%d%d", &N, &M); //N个模式串，M个句子
	for( int i = 0;i < N; i ++ ) 
	{
		char s[20];
		scanf("%s",s);
		Insert(Tree + 1,s);
	}
	BuildDfa();
	for( int i = 0 ;i < M;i ++ ) 
	{
		char s[200];
		scanf("%s",s);
		cout << SearchDfa(s) << endl;
	}
	return 0;
}