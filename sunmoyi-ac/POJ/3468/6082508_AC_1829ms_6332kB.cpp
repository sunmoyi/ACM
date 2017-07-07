#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

struct Node{
	int l, r;
	long long sum, add;
} tree[maxn << 2];

inline  void PushUp(int root)
{
	tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}

inline void PushDown(int root, int m)
{
	if (tree[root].add)
	{
		tree[root << 1].add += tree[root].add;
		tree[root << 1 | 1].add += tree[root].add;
		tree[root << 1].sum += tree[root].add * (m - (m >> 1));
		tree[root << 1 | 1].sum += tree[root].add * (m >> 1);
		tree[root].add = 0;
	}
}

void build(int l, int r, int root)
{
	tree[root].l = l;
	tree[root].r = r;
	tree[root].add = 0;
	if (l == r)
	{
		scanf("%I64d", &tree[root].sum);
		return;
	}
	int mid = (tree[root].l + tree[root].r) / 2;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
	PushUp(root);
}

void update(int c, int l, int r, int root)
{
	if (tree[root].l == l && r == tree[root].r)
	{
		tree[root].add += c;
		tree[root].sum += (__int64)c * (r - l + 1);
		return;
	}
	if (tree[root].l == tree[root].r)
		return;

	PushDown(root, tree[root].r - tree[root].l + 1);

	int mid = (tree[root].l + tree[root].r) / 2;
	if (r <= mid) 
		update(c, l, r, root << 1);
	else if (l > mid) 
		update(c, l, r, root << 1 | 1);
	else
	{
		update(c, l, mid, root << 1);
		update(c, mid + 1, r, root << 1 | 1);
	}

	PushUp(root);
}

__int64 query(int l, int r, int root)
{
	if (l == tree[root].l && r == tree[root].r)
	{
		return tree[root].sum;
	}

	PushDown(root, tree[root].r - tree[root].l + 1);

	int mid = (tree[root].l + tree[root].r) / 2;
	__int64 res = 0;
	if (r <= mid) 
		res += query(l, r, root << 1);
	else if (l > mid) 
		res += query(l, r, root << 1 | 1);
	else
	{
		res += query(l, mid, root << 1);
		res += query(mid + 1, r, root << 1 | 1);
	}

	return res;
}

int main()
{
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		build(1, n, 1);
		while (m--)
		{
			char ch[2];
			scanf("%s", ch, 2);
			int a, b, c;
			if (ch[0] == 'Q')
			{
				scanf("%d %d", &a, &b);
				printf("%I64d\n", query(a, b, 1));
			}

			else
			{
				scanf("%d %d %d", &a, &b, &c);
				update(c, a, b, 1);
			}
		}
	}
	return 0;
}