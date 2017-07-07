#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000000

using namespace std;

int n, m, num[maxn + 5], a, b;
char c;

struct node {
	int l, r;
	int v;
}trees[maxn * 4];

void buildtree(int rs, int l, int r)
{
	trees[rs].l = l;
	trees[rs].r = r;
	if (r == l)
	{
		trees[rs].v = num[l];
		return;
	}

	int mid = (l + r) / 2;

	buildtree(rs * 2, l, mid);
	buildtree(rs * 2 + 1, mid + 1, r);

	trees[rs].v = max(trees[rs * 2].v, trees[rs * 2 + 1].v);
}

void update(int rs, int k, int l)
{

	if (trees[rs].l == k&&trees[rs].r == k)
	{
		trees[rs].v = l;
		return;
	}

	int mid = (trees[rs].l + trees[rs].r) / 2;

	if (k <= mid)update(rs * 2, k, l);
	if (k>mid)update(rs * 2 + 1, k, l);

	trees[rs].v = max(trees[rs * 2].v, trees[rs * 2 + 1].v);
}

int querry(int rs, int l, int r)
{
	if (trees[rs].l == l&&trees[rs].r == r)
		return trees[rs].v;

	int mid = (trees[rs].l + trees[rs].r) / 2;

	if (r <= mid)
		return querry(rs * 2, l, r);
	if (l>mid)
		return querry(rs * 2 + 1, l, r);
	if (l <= mid&&r>mid)
		return max(querry(rs * 2, l, mid), querry(rs * 2 + 1, mid + 1, r));

	return 0;
}

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf_s("%d", &num[i]);

		buildtree(1, 1, n);

		for (int i = 1; i <= m; i++)
		{
			getchar();
			scanf("%c%d%d", &c, &a, &b);
			if (c == 'Q')
				printf("%d\n", querry(1, a, b));
			else
				update(1, a, b);
		}
	}
	return 0;
}