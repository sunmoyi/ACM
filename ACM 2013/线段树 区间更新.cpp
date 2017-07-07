#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int l; 
	int r;
	int mid;
	int num;
}tree[3000007];
int countt;
int n, a, b;

void build(int left, int right, int i)
{
	tree[i].l = left;
	tree[i].r = right;
	tree[i].mid = (left + right) / 2;
	tree[i].num = 0;
	if (left == right)
		return;
	build(left, tree[i].mid, 2 * i);
	build(tree[i].mid + 1, right,2 * i + 1);
}

void insert(int left, int right, int i)
{
	if (tree[i].l == left && tree[i].r == right)
	{
		tree[i].num++;
		return;
	}
	if (tree[i].mid < left)
		insert(left, right, 2 * i + 1);
	else if (tree[i].mid >= right)
		insert(left, right, 2 * i);
	else
	{
		insert(left, tree[i].mid, 2 * i);
		insert(tree[i].mid + 1, right, 2 * i + 1);
	}
}

void search(int id, int i)
{
	countt += tree[i].num;
	if (tree[i].l == tree[i].r && tree[i].l == id)
	{
		return;
	}
	if (tree[i].mid >= id)
		search(id, i * 2);
	else
		search(id, i * 2 + 1);
}

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &a, &b);
			insert(a, b, 1);
		}

		for (int i = 1; i < n; i++)
		{
			countt = 0;
			search(i, 1);
			printf("%d ", countt);
		}
		countt = 0;
		search(n, 1);
		printf("%d\n", countt);
	}
	return 0;
}