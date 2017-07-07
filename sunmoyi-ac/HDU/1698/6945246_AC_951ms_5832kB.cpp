#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

struct node {
	int l, r;
	int sum;
	int lazy;
}trees[maxn << 2];

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
		trees[root << 1].sum = (x - (x >> 1)) * trees[root].lazy;
		trees[root << 1 | 1].sum = (x >> 1) * trees[root].lazy;
		trees[root].lazy = -1;
	}
}

void buildtrees(int root, int l, int r)
{
	trees[root].l = l;
	trees[root].r = r;
	trees[root].lazy = -1;
	trees[root].sum = 1;
	if (l == r)
		return;

	int mid = (l + r) >> 1;
	buildtrees(root << 1, l, mid);
	buildtrees(root << 1 | 1, mid + 1, r);
	pushup(root);
}

void update(int root, int l, int r, int x)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		trees[root].lazy = x;
		trees[root].sum = x * (trees[root].r - trees[root].l + 1);
		return;
	}

	pushdown(root);
	int mid = (trees[root].l + trees[root].r) >> 1;

	if (r <= mid)
		update(root << 1, l, r, x);
	else if (l > mid)
		update(root << 1 | 1, l, r, x);
	else
	{
		update(root << 1, l, mid, x);
		update(root << 1 | 1, mid + 1, r, x);
	}
	pushup(root);
}

int main(void)
{
	int T, sum, n, x, y, z;
	while (scanf("%d", &T) != EOF)
	{
		for(int i = 1; i <= T; i++)
		{
			scanf("%d %d", &sum, &n);
			buildtrees(1, 1, sum);

			while (n--)
			{
				scanf("%d %d %d", &x, &y, &z);
				update(1, x, y, z);
			}
			printf("Case %d: The total value of the hook is %d.\n", i, trees[1].sum);
		}
	}
	return 0;
}