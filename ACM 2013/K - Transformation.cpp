#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define MOD 10007

using namespace std;

struct node {
	int l, r;
	int lazy1, lazy2, lazy3, p1, p2, p3;
}trees[maxn << 2];
int n, m, op, x, y, z;

void change_eq(int root, int val)
{
	int len = trees[root].r - trees[root].l + 1;
	trees[root].lazy1 = 0;
	trees[root].lazy2 = 0;
	trees[root].lazy3 = val % MOD;
	trees[root].p1 = val * len % MOD;
	trees[root].p2 = val % MOD * val % MOD * len %MOD;
	trees[root].p3 = val % MOD * val % MOD * val % MOD * len % MOD;
}

void change_add_mut(int root, int v1, int v2)
{
	int len = trees[root].r - trees[root].l + 1;
	trees[root].lazy2 = trees[root].lazy2 * (v2 % MOD) % MOD;
	trees[root].lazy1 = (trees[root].lazy1 * v2 % MOD + v1 % MOD) % MOD;
	trees[root].p3 = (trees[root].p3 % MOD * v2 % MOD * v2 % MOD * v2 % MOD +
		v1 % MOD * v1 % MOD * v1 % MOD * len % MOD +
		3 * v2 % MOD * v2 % MOD * v1 % MOD * trees[root].p2 % MOD +
		3 * v2 % MOD * v1 % MOD * v1 % MOD * trees[root].p1 % MOD) % MOD;
	trees[root].p2 = (trees[root].p2 % MOD * v2 % MOD * v2 % MOD +
		v1 % MOD * v1 % MOD * len % MOD +
		2 * v2 % MOD * v1 % MOD * trees[root].p1 % MOD) % MOD;
	trees[root].p1 = (v2 * trees[root].p1 % MOD +
		v1 % MOD * len % MOD) % MOD;
}



void pushup(int root)
{
	trees[root].p1 = (trees[root << 1].p1 % MOD + trees[root << 1 | 1].p1 % MOD) % MOD;
	trees[root].p2 = (trees[root << 1].p2 % MOD + trees[root << 1 | 1].p2 % MOD) % MOD;
	trees[root].p3 = (trees[root << 1].p3 % MOD + trees[root << 1 | 1].p3 % MOD) % MOD;
}

void pushdown_eq(int root)
{
	if (trees[root].l == trees[root].r)
		return;
	if (trees[root].lazy3 != 0)
	{
		change_eq(root << 1, trees[root].lazy3);
		change_eq(root << 1 | 1, trees[root].lazy3);
		trees[root].lazy3 = 0;
	}
}

void pushdown_add_mut(int root)
{
	if (trees[root].l == trees[root].r)
		return;
	if (trees[root].lazy1 != 0 || trees[root].lazy2 != 1)
	{
		change_add_mut(root << 1, trees[root].lazy1, trees[root].lazy3);
		change_add_mut(root << 1 | 1, trees[root].lazy1, trees[root].lazy3);
		trees[root].lazy1 = 0;
		trees[root].lazy2 = 1;
	}
}



void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	trees[root].p1 = trees[root].p2 = trees[root].p3 = 0;
	trees[root].lazy1 = trees[root].lazy3 = 0;
	trees[root].lazy2 = 1;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
}

void modefiy_eq(int val, int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		change_eq(root, val);
		return;
	}
	pushdown_eq(root);
	pushdown_add_mut(root);
	int mid = (l + r) >> 1;
	if (l <= mid)
		modefiy_eq(val, l, mid, root << 1);
	if (r > mid)
		modefiy_eq(val, mid + 1, r, root << 1 | 1);
	pushup(root);
}

void modefiy_add_mut(int val, int l, int r, int root, int op)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		val %= MOD;
		if (op == 1)
		{
			int len = trees[root].r - trees[root].l + 1;
			trees[root].lazy1 = (trees[root].lazy1 + val) % MOD;
			trees[root].p3 = (trees[root].p3%MOD +
				3 * val % MOD * trees[root].p2 % MOD +
				3 * val % MOD * val % MOD * trees[root].p1 % MOD +
				val % MOD * val % MOD * val % MOD * len % MOD) % MOD;
			trees[root].p2 = (trees[root].p2%MOD +
				trees[root].p1 % MOD * 2 * val % MOD +
				val % MOD * val % MOD * len % MOD) % MOD;
			trees[root].p1 = (trees[root].p1 + val * len % MOD) % MOD;
		}
		else if (op == 2)
		{
			trees[root].lazy1 = (trees[root].lazy1 * val % MOD) % MOD;
			trees[root].lazy2 = (trees[root].lazy2 * val % MOD) % MOD;
			trees[root].p1 = (trees[root].p1 % MOD * val % MOD) % MOD;
			trees[root].p2 = (trees[root].p2 % MOD * val % MOD * val % MOD) % MOD;
			trees[root].p3 = (trees[root].p3 % MOD * val % MOD * val % MOD * val % MOD) % MOD;
		}
		return;
	}
	pushdown_eq(root);
	pushdown_add_mut(root);
	int mid = (trees[root].l + trees[root].r) >> 1;
	if (l <= mid)
		modefiy_add_mut(val, l, mid, root << 1, op);
	if (r > mid)
		modefiy_add_mut(val, mid + 1, r, root << 1 | 1, op);
	pushup(root);
}

int query(int l, int r, int root, int op)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		if (op == 1)
			return trees[root].p1 % MOD;
		else if (op == 2)
			return trees[root].p2 % MOD;
		else if (op == 3)
			return trees[root].p3 % MOD;
	}
	pushdown_eq(root);
	pushdown_add_mut(root);
	int mid = (trees[root].l + trees[root].r) >> 1;
	int ans = 0;
	if (l <= mid)
		ans += query(l, mid, root << 1, op);
	if (r > mid)
		ans += query(mid + 1, r, root << 1 | 1, op);
	return ans;
}



int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		build(1, n, 1);
		while (m--)
		{
			scanf("%d %d %d %d", &op, &x, &y, &z);
			if (op == 1)
				modefiy_add_mut(z, x, y, 1, op);
			else if (op == 2)
				modefiy_add_mut(z, x, y, 1, op);
			else if (op == 3)
				modefiy_eq(z, x, y, 1);
			else
				printf("%d\n", query(x, y, 1, op));
		}
	}
	return 0;
}