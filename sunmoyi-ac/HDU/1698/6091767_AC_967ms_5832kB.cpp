#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

struct node {
	int l, r;
	int lazy, sum;
}trees[maxn << 2];
int T, n, m, a, b, c;

void pushup(int root)
{
	trees[root].sum = trees[root << 1].sum + trees[root << 1 | 1].sum;
}

void pushdown(int root)
{
	if (trees[root].lazy != -1)
	{
		int x = trees[root].r - trees[root].l + 1;
		trees[root << 1].lazy = trees[root << 1 | 1].lazy = trees[root].lazy;
		trees[root << 1].sum = trees[root].lazy * (x - (x >> 1));
		trees[root << 1 | 1].sum = trees[root].lazy * (x >> 1);
		trees[root].lazy = -1;
	}
}

void build(int l, int r, int root)
{
	trees[root].l = l; trees[root].r = r; trees[root].sum = 1; trees[root].lazy = -1;
	if (l == r)
		return;
	
	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
	pushup(root);
}

void update(int l, int r, int c, int root)
{
	if (l <= trees[root].l && r >= trees[root].r)
	{
		trees[root].lazy = c;
		trees[root].sum = c * (trees[root].r - trees[root].l + 1);
		return;
	}
	pushdown(root);
	int mid = (trees[root].l + trees[root].r) >> 1;
	if (l <= mid)
		update(l, r, c, root << 1);
	if (r > mid)
		update(l, r, c, root << 1 | 1);
	pushup(root);
}

int main(void)
{
	while (scanf_s("%d", &T) != EOF)
	{
		for (int i = 1; i <= T; i++)
		{
			scanf_s("%d %d", &n, &m);
			build(1, n, 1);

			while (m--)
			{
				scanf_s("%d %d %d", &a, &b, &c);
				update(a, b, c, 1);
			}

			printf("Case %d: The total value of the hook is %d.\n", i, trees[1].sum);
		}
	}
	return 0;
}