#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010

using namespace std;

int n, m;
struct node {
	int l, r, mid;
	int cnt, add;
	long long sum[8];
}trees[maxn << 2];
long long b[maxn], mx;
int mxk;

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r, trees[root].mid = (l + r) >> 1, trees[root].cnt = trees[root].add = 0;
	int i;
	if (l == r)
	{
		trees[root].sum[0] = b[l];
		if (b[l] == 0)
		{
			for (int i = 1; i <= mxk; i++)
				trees[root].sum[i] = 0;
			return;
		}
		for (i = 1; trees[root].sum[i - 1] > 1; i++)
			trees[root].sum[i] = sqrt(trees[root].sum[i - 1] * 1.0);
		for (; i <= mxk; i++)
			trees[root].sum[i] = 1;
		return;
	}
	build(1, trees[root].mid, root << 1);
	build(trees[root].mid + 1, r, root << 1 | 1);
	for (int i = 0; i <= mxk; i++)
		trees[root].sum[i] = trees[root << 1].sum[i] + trees[root << 1 | 1].sum[i];
}

void down(int root)
{
	if (trees[root].add != 0)
	{
		trees[root << 1].cnt += trees[root].add;
		trees[root << 1 | 1].cnt += trees[root].add;
		trees[root << 1].add += trees[root].add;
		trees[root << 1 | 1].add += trees[root].add;
		trees[root].add = 0;
	}
}

void update(int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		trees[root].cnt++;
		trees[root].add++;
		return;
	}
	down(root);
	if (r <= trees[root].mid)
		update(l, r, root << 1);
	else if (l > trees[root].mid)
		update(l, r, root << 1 | 1);
	else
	{
		update(l, trees[root].mid, root << 1);
		update(trees[root].mid + 1, r, root << 1 | 1);
	}
}

long long query(int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		if (trees[root].cnt > mxk)
			trees[root].cnt = mxk;
		if (trees[root].cnt == mxk || trees[root].l == trees[root].r)
			return trees[root].sum[trees[root].cnt];
		down(root);
		return query(l, trees[root].mid, root << 1) + query(trees[root].mid + 1, r, root << 1 | 1);
	}

	down(root);
	if (r <= trees[root].mid)
		return query(l, r, root << 1);
	else if (l > trees[root].mid)
		return query(l, r, root << 1 | 1);
	else
		return query(l, trees[root].mid, root << 1) + query(trees[root].mid + 1, r, root << 1 | 1);
}

int main(void)
{
	int i, ca1, op, x, y;
	ca1 = 1;
	while (scanf("%d", &n) != EOF)
	{
		mx = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &b[i]);
			if (b[i] > mx)
				mx = b[i];
		}
		for (mxk = 1; mx > 1; mxk++, mx = sqrt(mx * 1.0))
			;
		build(1, n, 1);
		scanf("%d", &m);
		printf("Case #%d:\n", ca1++);
		while (m--)
		{
			scanf("%d %d %d", &op, &x, &y);
			if (x > y)
			{
				int temp = x;
				x = y;
				y = temp;
			}
			if (op == 0)
				update(x, y, 1);
			else
				printf("%lld\n", query(x, y, 1));
		}
		printf("\n");
	}
	return 0;
}