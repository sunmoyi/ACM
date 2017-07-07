#include <iostream>  
#include <cstdio>  
using namespace std;
const int N = 100005;


struct Node
{
	int l, r;
	long long sum, add;
	int mid(){return (l + r) >> 1;}
} tree[N << 2];


void PushUp(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void PushDown(int rt, int m)
{
	if (tree[rt].add)
	{
		tree[rt << 1].add += tree[rt].add;
		tree[rt << 1 | 1].add += tree[rt].add;
		tree[rt << 1].sum += tree[rt].add * (m - (m >> 1));
		tree[rt << 1 | 1].sum += tree[rt].add * (m >> 1);
		tree[rt].add = 0;
	}
}

void build(int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].add = 0;
	if (l == r)
	{
		scanf("%I64d", &tree[rt].sum);
		return;
	}
	int m = tree[rt].mid();
	build(l, m, rt << 1);
	build(m + 1, r, rt << 1 | 1);
	PushUp(rt);
}

void update(int c, int l, int r, int rt)
{
	if (tree[rt].l == l && r == tree[rt].r)
	{
		tree[rt].add += c;
		tree[rt].sum += (__int64)c * (r - l + 1);
		return;
	}
	if (tree[rt].l == tree[rt].r)
		return;
	PushDown(rt, tree[rt].r - tree[rt].l + 1);
	int m = tree[rt].mid();
	if (r <= m) 
		update(c, l, r, rt << 1);
	else if (l > m) 
		update(c, l, r, rt << 1 | 1);
	else
	{
		update(c, l, m, rt << 1);
		update(c, m + 1, r, rt << 1 | 1);
	}
	PushUp(rt);
}

__int64 query(int l, int r, int rt)
{
	if (l == tree[rt].l && r == tree[rt].r)
	{
		return tree[rt].sum;
	}
	PushDown(rt, tree[rt].r - tree[rt].l + 1);
	int m = tree[rt].mid();
	__int64 res = 0;
	if (r <= m) 
		res += query(l, r, rt << 1);
	else if (l > m) 
		res += query(l, r, rt << 1 | 1);
	else
	{
		res += query(l, m, rt << 1);
		res += query(m + 1, r, rt << 1 | 1);
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