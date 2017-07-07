#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50050

using namespace std;

struct node {
	int l, r;
	int maxx, minn;
	int num;
}trees[maxn << 2];
int n, m;
int maxxx, minnn;

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	if (l == r)
	{
		scanf_s("%d", &trees[root].num);
		trees[root].maxx = trees[root].minn = trees[root].num;
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
	trees[root].maxx = max(trees[root << 1].maxx, trees[root << 1 | 1].maxx);
	trees[root].minn = min(trees[root << 1].minn, trees[root << 1 | 1].minn);
}

void query(int l, int r, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		maxxx = max(maxxx, trees[root].maxx);
		minnn = min(minnn, trees[root].minn);
		return;
	}
	if (trees[root].maxx <= maxxx && trees[root].minn >= minnn)
		return;
	int mid = (trees[root].l + trees[root].r) >> 1;
	if (r <= mid)
		query(l, r, root << 1);
	else if (l > mid)
		query(l, r, root << 1 | 1);
	else
	{
		query(l, mid, root << 1);
		query(mid + 1, r, root << 1 | 1);
	}
}

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		build(1, n, 1);
		while (m--)
		{
			scanf_s("%d %d", &a, &b);
			maxxx = -0xfffffff;
			minnn = 0xfffffff;
			query(a, b, 1);
			printf("%d\n", maxxx - minnn);
		}
	}
	return 0;
}