#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int trees[maxn << 2];

void build(int root, int l, int r)
{
	trees[root] = INF;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);
}

void update(int pos, int root, int val, int l, int r)
{
	if (trees[root] > val)
		trees[root] = val;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	if (pos <= mid)
		update(pos, root << 1, val, l, mid);
	else
		update(pos, root << 1 | 1, val, mid + 1, r);
}

int query(int root, int L, int R, int l, int r)
{
	if (L <= l && r <= R)
		return trees[root];
	int mid = (l + r) >> 1;
	if (R <= mid)
		return query(root << 1, L, R, l, mid);
	else if (L > mid)
		return query(root << 1 | 1, L, R, mid + 1, r);
	else
		return min(query(root << 1, L, R, l, mid), query(root << 1 | 1, L, R, mid + 1, r));
}

int main (void)
{
	int a, b, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		build(1, 1, n);
		update(1, 1, 0, 1, n);
		while (m--)
		{
			scanf("%d %d", &a, &b);
			int x = query(1, a, b, 1, n);
			update(b, 1, x + 1, 1, n);
		}
		printf("%d\n", query(1, n, n, 1, n));
		if (T)
			printf("\n");
	}
	return 0;
}