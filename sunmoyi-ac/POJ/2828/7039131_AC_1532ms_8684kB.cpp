//http://blog.csdn.net/z309241990/article/details/9322135
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

struct node {
	int l, r, val;
}trees[maxn << 2];

int n, a[maxn], b[maxn], ans[maxn];

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	trees[root].val = r - l + 1;
	if (l == r)
		return;

	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
}

int query(int root, int num)
{
	trees[root].val -= 1;
	if (trees[root].l == trees[root].r)
		return trees[root].l;
	if (trees[root << 1].val >= num)
		return query(root << 1, num);
	else
		return query(root << 1 | 1, num - (trees[root << 1].val));
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &a[i], &b[i]);
		for (int i = n; i >= 1; i--)
		{
			int root = query(1, a[i] + 1);
			ans[root] = b[i];
		}
		for (int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}