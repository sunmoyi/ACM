#include <stdio.h>
#include <string.h>

const int MAXN = 100010;
int sum[MAXN << 2];
int lazy[MAXN << 2];

void pushup(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int x)
{
	if (lazy[rt] != -1) {
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		sum[rt << 1] = (x - (x >> 1))*lazy[rt];///!!!
		sum[rt << 1 | 1] = (x >> 1)*lazy[rt];///!!!
		lazy[rt] = -1;
	}
}

void creat(int l, int r, int rt)
{
	lazy[rt] = -1, sum[rt] = 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	creat(l, mid, rt << 1);
	creat(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

void modify(int l, int r, int x, int L, int R, int rt)
{
	if (l <= L && r >= R) {
		lazy[rt] = x;
		sum[rt] = x*(R - L + 1);///!!!
		return;
	}
	pushdown(rt, R - L + 1);///!!!
	int mid = (L + R) >> 1;
	if (l <= mid) modify(l, r, x, L, mid, rt << 1);
	if (r > mid) modify(l, r, x, mid + 1, R, rt << 1 | 1);
	pushup(rt);
}

int main()
{
	int i, j, k = 0;
	int n, T, q;
	int x, y, w;
	while (scanf("%d", &T) != EOF)
		while (T--)
		{
			scanf("%d %d", &n, &q);
			creat(1, n, 1);

			while (q--) {
				scanf("%d %d %d", &x, &y, &w);
				modify(x, y, w, 1, n, 1);
			}

			printf("Case %d: The total value of the hook is %d.\n", ++k, sum[1]);
		}
	return 0;
}