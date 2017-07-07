#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

struct node {
	int to, next;
}edge[maxn];
int head[maxn], tot;
int cnt;
int start[maxn], endd[maxn];

void init()
{
	cnt = 0;
	tot = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int u)
{
	++cnt;
	start[u] = cnt;
	for (int i = head[u]; i != -1; i = edge[i].next)
		dfs(edge[i].to);
	endd[u] = cnt;
}

struct Node {
	int l, r;
	int val;
	int lazy;
}trees[maxn << 2];

void pushup(int root, int v)
{
	trees[root].val = v;
	trees[root].lazy = 1;
}

void pushdown(int root)
{
	if (trees[root].lazy)
	{
		trees[root << 1].val = trees[root].val;
		trees[root << 1 | 1].val = trees[root].val;
		trees[root << 1].lazy = trees[root << 1 | 1].lazy = 1;
		trees[root].lazy = 0;
	}
}

void build(int l, int r, int root)
{
	trees[root].l = l, trees[root].r = r;
	trees[root].lazy = 0;
	trees[root].val = -1;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
}

void update(int l, int r, int v, int root)
{
	if (trees[root].l == l && trees[root].r == r)
	{
		pushup(root, v);
		return;
	}
	pushdown(root);

	int mid = (trees[root].l + trees[root].r) >> 1;
	if (r <= mid)
		update(l, r, v, root << 1);
	else if (l > mid)
		update(l, r, v, root << 1 | 1);
	else
	{
		update(l, mid, v, root << 1);
		update(mid + 1, r, v, root << 1 | 1);
	}
}

int query(int root, int u)
{
	if (trees[root].l == trees[root].r && trees[root].l == u)
		return trees[root].val;

	pushdown(root);

	int mid = (trees[root].l + trees[root].r) >> 1;
	if (u <= mid)
		return query(root << 1, u);
	else
		return query(root << 1 | 1, u);
}

bool used[maxn];

int main(void)
{
	int T, n;
	scanf("%d", &T);
	int icase = 0;
	while (T--)
	{
		icase++;
		printf("Case #%d:\n", icase);
		int u, v;
		memset(used, false, sizeof(used));

		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &u, &v);
			used[u] = true;
			addedge(v, u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!used[i])
			{
				dfs(i);
				break;
			}
		}
		build(1, cnt, 1);
		char op[10];
		int m;
		scanf("%d", &m);
		while (m--)
		{
			scanf("%s", op);
			if (op[0] == 'C')
			{
				scanf("%d", &u);
				printf("%d\n", query(1, start[u]));
			}
			else
			{
				scanf("%d %d", &u, &v);
				update(start[u], endd[u], v, 1);
			}
		}
	}
	return 0;
}