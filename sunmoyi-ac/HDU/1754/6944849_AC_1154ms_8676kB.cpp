#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000010

using namespace std;

int n, m, a[maxn];

struct tree {
	int l, r;
	int  v;
}trees[maxn << 1];

void buildtree(int root, int l, int r)
{
	trees[root].l = l;
	trees[root].r = r;
	if (r == l)
	{
		trees[root].v = a[l];
		return;
	}
	int mid = (l + r) >> 1;

	buildtree(root << 1, l, mid);
	buildtree(root << 1 | 1, mid + 1, r);

	trees[root].v = max(trees[root << 1].v, trees[root << 1 | 1].v);
}

void update(int root, int k, int l)
{
	if (trees[root].l == k &&  trees[root].r == k)
	{
		trees[root].v = l;
		return;
	}

	int mid = (trees[root].l + trees[root].r) >> 1;

	if (k <= mid)
		update(root << 1, k, l);
	else
		update(root << 1 | 1, k, l);

	trees[root].v = max(trees[root << 1].v, trees[root << 1 | 1].v);
}

int query(int root, int l, int r)
{
	if (trees[root].l == l && trees[root].r == r)
		return trees[root].v;

	int mid = (trees[root].l + trees[root].r) >> 1;

	if (r <= mid)
		return query(root << 1, l, r);
	else if (l > mid)
		return query(root << 1 | 1, l, r);
	else
		return max(query(root << 1, l, mid), query(root << 1 | 1, mid + 1, r));
}

int main (void)
{
	int i, ac, bc;
	char c;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		buildtree(1, 1, n);

		for (int i = 1; i <= m; i++)
		{
			getchar();
			scanf("%c%d%d", &c, &ac, &bc);
			if (c == 'Q')
				printf("%d\n", query(1, ac, bc));
			else
				update(1, ac, bc);
		}
	}
	return 0;
}