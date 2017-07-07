#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 8080

using namespace std;

struct node {
	int l, r;
	int color;
}trees[maxn << 2];
int color[maxn];
int temp;

void build(int root, int l, int r)
{
	trees[root].l = l, trees[root].r = r, trees[root].color = -1;
	if (l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid, r);
}

void insert(int root, int l, int r, int c)
{
	if (l == r)
		return;
	if (trees[root].color == c)
		return;
	if (l <= trees[root].l && r >= trees[root].r)
	{
		trees[root].color = c;
		return;
	}
	if (trees[root].color >= 0)
	{
		trees[root << 1].color = trees[root << 1 | 1].color = trees[root].color;
	}
}

void count(int root)
{
	if (trees[root].color == -1)
	{
		temp = -1;
		return;
	}
	if (trees[root].color != -2)
	{
		if (trees[root].color != temp)
		{
			color[trees[root].color]++;
			temp = trees[root].color;
		}
		return;
	}
	if (trees[root].l + 1 != trees[root].r)
	{
		count(root << 1);
		count(root << 1 | 1);
	}
}

int main(void)
{
	int n, a, b, c;
	int maxx;
	while (scanf("%d", &n) != EOF)
	{
		build(1, 0, 8000);
		maxx = 0;

		while (n--)
		{
			scanf("%d %d %d", &a, &b, &c);
			insert(1, a, b, c);
			if (c > maxx)
				maxx = c;
		}
		temp = -1;
		memset(color, 0, sizeof(color));
		count(1);
		for (int i = 0; i <= maxx; i++)
			if (color[i])
				printf("%d %d\n", i, color[i]);
		printf("\n");
	}
	return 0;
}