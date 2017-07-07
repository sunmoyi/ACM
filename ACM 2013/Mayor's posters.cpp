#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

struct node {
	int l, r;
	int color;
}trees[maxn << 2];

bool hashh[maxn << 2];
int li[maxn], ri[maxn], x[maxn], ans;

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	trees[root].color = 0; ;

	if (l == r)
		return;

	int mid = (l + r) / 2;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
}

void pushdown(int root)
{
	trees[root << 1].color = trees[root << 1 | 1].color = trees[root].color;
	trees[root].color = 0;
}

void update(int c, int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		trees[root].color = c;
		return;
	}
	if (trees[root].l == trees[root].r)
		return;

	if (trees[root].color != 0)
		pushdown(root);

	int mid = (trees[root].l + trees[root].r) / 2;
	if (r <= mid)
		update(c, l, r, root << 1);
	else if (l > mid)
		update(c, l, r, root << 1 | 1);
	else
	{
		update(c, l, mid, root << 1);
		update(c, mid + 1, r, root << 1 | 1);
	}
}

void query(int l, int r, int root)
{
	if (trees[root].l == trees[root].r)
	{
		if (!hashh[trees[root].color])
		{
			ans++;
			hashh[trees[root].color] = true;
		}
		return;
	}

	if (trees[root].color != 0)
		pushdown(root);

	int mid = (trees[root].l + trees[root].r) / 2;
	query(l, mid, root << 1);
	query(mid + 1, r, root << 1 | 1);
}

int BSearch(int ll, int hh, int rr)
{
	int mid;
	while (ll <= hh)
	{
		mid = (ll + hh) >> 1;
		if (x[mid] == rr)
			return mid;
		else if (x[mid] > rr)
			hh = mid - 1;
		else
			ll = mid + 1;
	}
	return -1;
}

int main(void)
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		memset(hashh, false, sizeof(hashh));
		hashh[0] = true;
		int nn = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &li[i], &ri[i]);
			x[++nn] = li[i];
			x[++nn] = ri[i];
		}

		sort(x + 1, x + nn + 1);
		int m = 1;
		for (int i = 2; i <= nn; i++)
			if (x[i] != x[i - 1])
				x[++m] = x[i];
		for (int i = m; i > 1; i--)
			if (x[i] - x[i - 1] > 1)
				x[++m] = x[i] - 1;
		sort(x + 1, x + m + 1);

		build(1, m, 1);
		for (int i = 1; i <= n; i++)
		{
			int l = BSearch(1, m, li[i]);
			int r = BSearch(1, m, ri[i]);
			update(i, l, r, 1);
		}
		ans = 0;
		query(1, m, 1);
		printf("%d\n", ans);
	}
	return 0;
}