#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int sum[maxn << 2];
int lazy[maxn << 2];

void pushup(int root)
{
	sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void pushdown(int root, int x)
{
	if (lazy[root] != -1)
	{
		lazy[root << 1] = lazy[root << 1 | 1] = lazy[root];
		sum[root << 1] = (x - (x >> 1)) * lazy[root];
		sum[root << 1 | 1] = (x >> 1) * lazy[root];
		lazy[root] = -1;
	}
}

void creat(int l, int r, int root)
{
	lazy[root] = -1;
	sum[root] = 1;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	creat(l, mid, root << 1);
	creat(mid + 1, r, root << 1 | 1);
	pushup(root);
}

void update(int l, int r, int x, int L, int R, int root)
{
	if (l <= L && r >= R)
	{
		lazy[root] = x;
		sum[root] = x *(R - L + 1);
		return;
	}
	pushdown(root, R - L + 1);
	int mid = (L + R) >> 1;
	if (l <= mid)
		update(l, r, x, L, mid, root << 1);
	if (r > mid)
		update(l, r, x, mid + 1, R, root << 1 | 1);
	pushup(root);
}

int main(void)
{
	int T, n, q;
	int x, y, w;
	while (scanf_s("%d", &T) != EOF)
	{
		for(int i = 1; i <= T; i++)
		{
			scanf_s("%d %d", &n, &q);
			creat(1, n, 1);

			while (q--)
			{
				scanf_s("%d %d %d", &x, &y, &w);
				update(x, y, w, 1, n, 1);
			}

			printf("Case %d: The total value of the hook is %d.\n", i, sum[1]);
		}
	}
	return 0;
}