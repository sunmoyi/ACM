#include<cstdio>
#include<cstring>
#include<algorithm>
#define L(m) m << 1
#define R(m) m << 1 | 1

using namespace std;

const int maxn = 1000000 + 1;
int num[maxn]; 

struct node{
	int l;
	int r;
	int sum;
}tree[maxn << 2];

void build(int m, int l, int r)// 新建线段树 （1号节点， 节点起始标号， 节点终点标号）
{
	tree[m].l = l;
	tree[m].r = r;
	if (tree[m].l == tree[m].r)
	{
		tree[m].sum = num[l];
		return;

	}
	int mid = (tree[m].l + tree[m].r) >> 1;
	build(L(m), l, mid);
	build(R(m), mid + 1, r);
	tree[m].sum = tree[L(m)].sum + tree[R(m)].sum;
}

void update(int m, int a, int x)//（1， 将节点a， 增加x）
{
	if (tree[m].l == a && tree[m].r == a)
	{
		tree[m].sum += x;
		return;
	}
	int mid = (tree[m].l + tree[m].r) >> 1;
	if (mid >= a)
		update(L(m), a, x);
	else
		update(R(m), a, x);
	tree[m].sum = tree[L(m)].sum + tree[R(m)].sum;
}

int query(int m, int l, int r)//区间求和（1， 区间起点， 区间终点）
{
	if (tree[m].l == l && tree[m].r == r)
		return tree[m].sum;
	int mid = (tree[m].l + tree[m].r) >> 1;
	if (mid >= r)
		return query(L(m), l, r);
	if (mid < l)
		return query(R(m), l, r);
	return query(L(m), l, mid) + query(R(m), mid + 1, r);
}

int main(void)
{
	int t, ans;
	while (scanf_s("%d", &t) != EOF)
	{
		for (int ss = 1; ss <= t; ss++)
		{
			scanf_s("%d", &ans);
			for (int i = 1; i <= ans; i++)
				scanf_s("%d", &num[i]);
			build(1, 1, ans);
			getchar();
			char s[10];
			printf("Case %d:\n", ss);
			while (scanf_s("%s", s, 9))
			{
				if (s[0] == 'E')
					break;
				else if (s[0] == 'Q')
				{
					int  a, b;
					scanf_s("%d %d", &a, &b);
					printf("%d\n", query(1, a, b));
				}
				else if (s[0] == 'A')
				{
					int a, b;
					scanf_s("%d %d", &a, &b);
					update(1, a, b);
				}
				else if (s[0] == 'S')
				{
					int a, b;
					scanf_s("%d %d", &a, &b);
					update(1, a, -b);
				}
			}
		}
	}
	return 0;
}