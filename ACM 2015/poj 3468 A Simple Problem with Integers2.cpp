#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

struct node {
	int l, r;
	long long sum, add;
}trees[maxn << 2];

void pushup(int root)
{
	trees[root].sum = trees[root << 1].sum + trees[root << 1 | 1].sum;
}

void pushdown(int root, int m)
{
	if (trees[root].add)
	{
		trees[root << 1].add += trees[root].add;
		trees[root << 1 | 1].add += trees[root].add;
		trees[root << 1].sum += trees[root].add * (m - (m >> 1));
		trees[root << 1 | 1].sum += trees[root].add * (m >> 1);
		trees[root].add = 0;
	}
}

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	trees[root].add = 0;
	if (l == r)
	{
		scanf("%lld", &trees[root].sum);
		return;
	}
	int mid = (trees[root].l + trees[root].r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
	pushup(root);
}

void update(int c, int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		trees[root].add += c;
		trees[root].sum += (long long)c * (r - l + 1);
		return;
	}
	if (trees[root].l == trees[root].r)
		return;

	pushdown(root, trees[root].r - trees[root].l + 1);

	int mid = (trees[root].l + trees[root].r) >> 1;
	if (r <= mid)
		update(c, l, r, root << 1);
	else if (l > mid)
		update(c, l, r, root << 1 | 1);
	else
	{
		update(c, l, mid, root << 1);
		update(c, mid + 1, r, root << 1 | 1);
	}
	pushup(root);
}

long long query(int l, int r, int root)
{
	if (l == trees[root].l && r == trees[root].r)
		return trees[root].sum;

	pushdown(root, trees[root].r - trees[root].l + 1);

	int mid = (trees[root].r + trees[root].l) >> 1;
	long long res;
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

int main(void)
{
	int n, m; char ch[2];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		build(1, n, 1);
		while(m--)
		{
			scanf("%s", ch);
			int a, b, c;
			if (ch[0] == 'Q')
			{
				scanf("%d %d", &a, &b);
				printf("%lld\n", query(a, b, 1));
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
