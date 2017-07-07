#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct Huffman_trie
{
	int deep;//深度
	int freq;//频度（即哈夫曼树中的权重）
	Huffman_trie *left, *right;
	//优先权队列中用于排序比较的方法，不懂的建议先学一学优先权队列
	friend bool operator< (Huffman_trie a, Huffman_trie b)
	{
		return  a.freq > b.freq;
	}
}Huffman_trie;

Huffman_trie trie[300];//哈夫曼树节点
Huffman_trie *root;
int len, count_num, index, sum;
priority_queue<Huffman_trie> pq;

void huffman()
{
	sum = 0;
	root = (Huffman_trie*)malloc(sizeof(Huffman_trie));
	for (int i = 0; i < index; i++)
		pq.push(trie[i]);
	while (pq.size() > 1)
	{
		Huffman_trie *h1 = (Huffman_trie*)malloc(sizeof(Huffman_trie));
		*h1 = pq.top();
		pq.pop();
		Huffman_trie *h2 = (Huffman_trie*)malloc(sizeof(Huffman_trie));
		*h2 = pq.top();
		pq.pop();

		Huffman_trie h3;
		h3.left = h1;
		h3.right = h2;
		h3.freq = h1->freq + h2->freq;
		pq.push(h3);
	}
	*root = pq.top();
	pq.pop();
	root->deep = 0;

	queue<Huffman_trie>q;
	q.push(*root);
	while (!q.empty())
	{
		Huffman_trie ht = q.front();
		q.pop();
		if (ht.left != NULL)
		{
			ht.left->deep = ht.deep + 1;
			q.push(*ht.left);
		}
		if (ht.right != NULL)
		{
			ht.right->deep = ht.deep + 1;
			q.push(*ht.right);
		}
		if (!ht.left&&!ht.right)
			sum += ht.deep*ht.freq;
	}

}
int main()
{
	char str[1000];
	while (scanf("%s", str) != EOF&&strcmp(str, "END") != 0)
	{
		len = strlen(str);
		str[len] = '!';// ‘！’是为了给str[len]占位
		sort(str, str + len);
		count_num = 1;
		index = 0;
		for (int i = 1; i <= len; i++)
		{
			if (str[i] != str[i - 1])
			{
				trie[index++].freq = count_num;//这一步的基础是上面的排序
				count_num = 1;
			}
			else count_num++;
		}
		if (index == 1)
			printf("%d %d 8.0\n", len * 8, len);
		else
		{
			huffman();
			printf("%d %d %.1lf\n", len * 8, sum, len * 8 * 1.0 / sum);
		}
	}
	return 0;
}