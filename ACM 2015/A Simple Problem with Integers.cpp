#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

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

void build(int root, int l, int r)
{
	trees[root].l = l;
	trees[root].r = r;
	trees[root].add = 0;
	if (l == r)
	{
		scanf("%lld", &trees[root].sum);
		return;
	}

	int mid = (trees[root].l + trees[root].r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);
	pushup(root);
}

void update(int root, int l, int r, int c)
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

long long query(int root, int l, int r)
{
	if (trees[root].l == l && trees[root].r == r)
		return trees[root].sum;

	pushdown(root, trees[root].r - trees[root].l + 1);

	int mid = (trees[root].r + trees[root].l) >> 1;
	long long res = 0;
	if (r <= mid)
		res += query(root << 1, l, r);
	else if (l > mid)
		res += query(root << 1 | 1, l, r);
	else
	{
		res += query(root << 1, l, mid);
		res += query(root << 1 | 1, mid + 1, r);
	}
	return res;

}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		build(1, 1, n);
		while(m--)
		{
			char ch[2];
			scanf("%s", ch);
			int a, b, c;
			if (ch[0] = 'Q')
			{
				scanf("%d %d", &a, &b);
				printf("%lld\n", query(1, a, b));
			}
			else
			{
				scanf("%d %d %d", &a, &b, &c);
				update(1, a, b, c);
			}
		}
	}
	return 0;
}