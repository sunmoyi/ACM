#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005

using namespace std;

struct node {
	int l, r;
	int lsum, rsum, msum;
	int ck;
	int mid()
	{
		return (l + r) >> 1;
	}
}trees[maxn << 2];

void pushdown(int root)
{
	if (trees[root].ck != -1)
	{
		int ll = trees[root << 1].r - trees[root << 1].l + 1;
		int rr = trees[root << 1 | 1].r - trees[root << 1 | 1].l + 1;
		trees[root << 1].ck = trees[root << 1 | 1].ck = trees[root].ck;
		trees[root].ck = -1;
		trees[root << 1].rsum = trees[root << 1].lsum = trees[root << 1].msum 
			= trees[root << 1].ck ? 0 : ll;
		trees[root << 1 | 1].rsum = trees[root << 1 | 1].lsum 
			= trees[root << 1 | 1].msum = trees[root << 1 | 1].ck ? 0 : rr;
	}
}

void pushup(int root)
{
	int ll = trees[root << 1].r - trees[root << 1].l + 1;
	int rr = trees[root << 1 | 1].r - trees[root << 1 | 1].l + 1;

	trees[root].lsum = trees[root << 1].lsum;
	if (trees[root].lsum == ll)
		trees[root].lsum += trees[root << 1 | 1].lsum;

	trees[root].rsum = trees[root << 1 | 1].rsum;
	if (trees[root].rsum == rr)
		trees[root].rsum += trees[root << 1].rsum;

	trees[root].msum = max(max(trees[root << 1].msum, trees[root << 1 | 1].msum), trees[root << 1].rsum + trees[root << 1 | 1].lsum);
}

void build(int root, int l, int r)
{
	trees[root].l = l; trees[root].r = r;
	trees[root].lsum = trees[root].msum = trees[root].rsum = r - l + 1;
	
	if (l == r)
		return;

	int mid = (l + r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);

	pushup(root);
}

void update(int root, int l, int r, int c)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		trees[root].msum = trees[root].lsum = trees[root].rsum = c ? 0 : (r - l + 1);
		trees[root].ck = c;
		return;
	}

	pushdown(root);

	int mid = trees[root].mid();
	if (r <= mid)
		update(root << 1, l, r, c);
	else if (l > mid)
		update(root << 1 | 1, l, r, c);
	else
	{
		update(root << 1, l, mid, c);
		update(root << 1 | 1, mid + 1, r, c);
	}

	pushup(root);
}

int query(int root, int w)
{
	if (trees[root].l == trees[root].r)
		return trees[root].l;	

	pushdown(root);

	int mid = trees[root].mid();
	if (trees[root << 1].msum >= w)
		return query(root << 1, w);
	else if (trees[root << 1].rsum + trees[root << 1 | 1].lsum >= w)
		return mid - trees[root << 1].rsum + 1;
	return query(root << 1 | 1, w);
}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		build(1, 1, n);
		while (m--)
		{
			int op, a, b;
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d", &a);
				if (trees[1].msum < a)
					printf("0\n");
				else
				{
					int p = query(1, a);
					printf("%d\n", p);
					update(1, p, p + a - 1, 1);
				}
			}
			else
			{
				scanf("%d %d", &a, &b);
				update(1, a, a + b - 1, 0);
			}
		}
	}
	return 0;
}