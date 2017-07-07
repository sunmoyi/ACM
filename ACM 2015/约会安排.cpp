#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
const int MAXN = 100010;
struct Node
{
	int l, r;
	int Max, Lmax, Rmax;
	int Max1, Lmax1, Rmax1;
}segTree[MAXN * 4];
void push_up(int x)
{
	if (segTree[x].l == segTree[x].r)return;
	int lson = 2 * x;
	int rson = 2 * x + 1;

	segTree[x].Lmax = segTree[lson].Lmax;
	if (segTree[lson].Lmax == segTree[lson].r - segTree[lson].l + 1)
        segTree[x].Lmax += segTree[rson].Lmax;
	segTree[x].Rmax = segTree[rson].Rmax;
	if (segTree[rson].Rmax == segTree[rson].r - segTree[rson].l + 1)
         segTree[x].Rmax += segTree[lson].Rmax;
	segTree[x].Max = max(segTree[lson].Max, segTree[rson].Max);
	segTree[x].Max = max(segTree[x].Max, max(segTree[x].Lmax, segTree[x].Rmax));
	segTree[x].Max = max(segTree[x].Max, segTree[lson].Rmax + segTree[rson].Lmax);

	segTree[x].Lmax1 = segTree[lson].Lmax1;
	if (segTree[lson].Lmax1 == segTree[lson].r - segTree[lson].l + 1)
		segTree[x].Lmax1 += segTree[rson].Lmax1;
	segTree[x].Rmax1 = segTree[rson].Rmax1;
	if (segTree[rson].Rmax1 == segTree[rson].r - segTree[rson].l + 1)
		segTree[x].Rmax1 += segTree[lson].Rmax1;
	segTree[x].Max1 = max(segTree[lson].Max1, segTree[rson].Max1);
	segTree[x].Max1 = max(segTree[x].Max1, max(segTree[x].Lmax1, segTree[x].Rmax1));
	segTree[x].Max1 = max(segTree[x].Max1, segTree[lson].Rmax1 + segTree[rson].Lmax1);
}
void push_down(int x)
{
	if (segTree[x].l == segTree[x].r)
        return;
	int lson = 2 * x, rson = 2 * x + 1;
	if (segTree[x].Max == 0)
	{
		segTree[lson].Max = segTree[lson].Lmax = segTree[lson].Rmax = 0;
		segTree[rson].Max = segTree[rson].Lmax = segTree[rson].Rmax = 0;
	}
	if (segTree[x].Max == segTree[x].r - segTree[x].l + 1)
	{
		segTree[lson].Max = segTree[lson].Lmax = segTree[lson].Rmax = segTree[lson].r - segTree[lson].l + 1;
		segTree[rson].Max = segTree[rson].Lmax = segTree[rson].Rmax = segTree[rson].r - segTree[rson].l + 1;
	}


	if (segTree[x].Max1 == 0)
	{
		segTree[lson].Max1 = segTree[lson].Lmax1 = segTree[lson].Rmax1 = 0;
		segTree[rson].Max1 = segTree[rson].Lmax1 = segTree[rson].Rmax1 = 0;
	}
	if (segTree[x].Max1 == segTree[x].r - segTree[x].l + 1)
	{
		segTree[lson].Max1 = segTree[lson].Lmax1 = segTree[lson].Rmax1 = segTree[lson].r - segTree[lson].l + 1;
		segTree[rson].Max1 = segTree[rson].Lmax1 = segTree[rson].Rmax1 = segTree[rson].r - segTree[rson].l + 1;
	}

}
void Build(int i, int l, int r)
{
	segTree[i].l = l;
	segTree[i].r = r;
	segTree[i].Max = segTree[i].Lmax = segTree[i].Rmax = r - l + 1;
	segTree[i].Max1 = segTree[i].Lmax1 = segTree[i].Rmax1 = r - l + 1;
	if (l == r)return;
	int mid = (l + r) / 2;
	Build(i << 1, l, mid);
	Build((i << 1) | 1, mid + 1, r);
}
int query(int i, int x)
{
	if (segTree[i].Max<x)return 0;
	if (segTree[i].Lmax >= x)return segTree[i].l;
	if (segTree[i << 1].Max >= x)return query(i << 1, x);
	if (segTree[i << 1].Rmax + segTree[(i << 1) | 1].Lmax >= x)
        return segTree[i << 1].r - segTree[i << 1].Rmax + 1;
	return query((i << 1) | 1, x);
}
int query1(int i, int x)
{
	if (segTree[i].Max1<x)return 0;
	if (segTree[i].Lmax1 >= x)return segTree[i].l;
	if (segTree[i << 1].Max1 >= x)return query1(i << 1, x);
	if (segTree[i << 1].Rmax1 + segTree[(i << 1) | 1].Lmax1 >= x)
        return segTree[i << 1].r - segTree[i << 1].Rmax1 + 1;
	return query1((i << 1) | 1, x);
}
void update(int i, int l, int r)
{
	if (segTree[i].l == l && segTree[i].r == r)
	{
		segTree[i].Max = segTree[i].Lmax = segTree[i].Rmax = segTree[i].r - segTree[i].l + 1;
		segTree[i].Max1 = segTree[i].Lmax1 = segTree[i].Rmax1 = segTree[i].r - segTree[i].l + 1;
		return;
	}
	push_down(i);
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)update(i << 1, l, r);
	else if (l>mid) update((i << 1) | 1, l, r);
	else
	{
		update(i << 1, l, mid);
		update((i << 1) | 1, mid + 1, r);
	}
	push_up(i);
}
void zhan1(int i, int l, int r)
{
	if (segTree[i].l == l && segTree[i].r == r)
	{
		segTree[i].Max = segTree[i].Lmax = segTree[i].Rmax = 0;
		return;
	}
	push_down(i);
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)zhan1(i << 1, l, r);
	else if (l>mid) zhan1((i << 1) | 1, l, r);
	else
	{
		zhan1(i << 1, l, mid);
		zhan1((i << 1) | 1, mid + 1, r);
	}
	push_up(i);
}
void zhan2(int i, int l, int r)
{
	if (segTree[i].l == l && segTree[i].r == r)
	{
		segTree[i].Max = segTree[i].Lmax = segTree[i].Rmax = 0;
		segTree[i].Max1 = segTree[i].Lmax1 = segTree[i].Rmax1 = 0;
		return;
	}
	push_down(i);
	int mid = (segTree[i].l + segTree[i].r) / 2;
	if (r <= mid)zhan2(i << 1, l, r);
	else if (l>mid) zhan2((i << 1) | 1, l, r);
	else
	{
		zhan2(i << 1, l, mid);
		zhan2((i << 1) | 1, mid + 1, r);
	}
	push_up(i);
}

int main()
{
	//    freopen("in.txt","r",stdin);
	//    freopen("out.txt","w",stdout);
	int T;
	int n, m;
	int l, r;
	int x;
	char op[20];
	scanf("%d", &T);
	int iCase = 0;
	while (T--)
	{
		iCase++;
		printf("Case %d:\n", iCase);
		scanf("%d%d", &n, &m);
		Build(1, 1, n);
		while (m--)
		{
			scanf("%s", op);
			if (op[0] == 'D')
			{
				scanf("%d", &x);
				int tmp = query(1, x);
				if (tmp == 0)printf("fly with yourself\n");
				else
				{
					zhan1(1, tmp, tmp + x - 1);
					printf("%d,let's fly\n", tmp);
				}
			}
			else if (op[0] == 'N')
			{
				scanf("%d", &x);
				int tmp = query(1, x);
				if (tmp != 0)
				{
					zhan2(1, tmp, tmp + x - 1);
					printf("%d,don't put my gezi\n", tmp);
					continue;
				}
				tmp = query1(1, x);
				if (tmp != 0)
				{
					zhan2(1, tmp, tmp + x - 1);
					printf("%d,don't put my gezi\n", tmp);
					continue;
				}
				printf("wait for me\n");
			}
			else
			{
				scanf("%d%d", &l, &r);
				printf("I am the hope of chinese chengxuyuan!!\n");
				update(1, l, r);
			}
		}
	}
	return 0;
}