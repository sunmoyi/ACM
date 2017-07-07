#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 55;
struct Node
{
	int l, r, len;
};
Node node[MAXN];
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &node[i].len);
			node[i].l = 0;
			for (int j = 1; j < i; j++)
				node[i].l = max(node[i].l, node[j].r - abs(node[i].len - node[j].len));
			node[i].r = node[i].l + 2 * node[i].len;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
				if (node[i].l < node[j].r && node[i].len < node[j].len)
					node[i].l = node[j].r;
			for (int j = i + 1; j <= n; j++)
				if (node[i].r > node[j].l && node[i].len < node[j].len)
					node[i].r = node[j].l;
		}
		bool first = true;
		for (int i = 1; i <= n; i++)
			if (node[i].l < node[i].r)
			{
				if (first)
					first = false;
				else printf(" ");
				printf("%d", i);
			}
		printf("\n");
	}
	return 0;
}