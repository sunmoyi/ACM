#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <math.h>  
#include <stdlib.h>  
using namespace std;

const int maxn = 50000 + 10;

int n, m;
int s[maxn], top;//s为模拟栈  

struct node
{
	int l, r;
	int ls, rs, ms;//ls,左端最大连续区间，rs右端最大连续区间，ms区间内最大连续区间  
} a[maxn << 2];

void init(int l, int r, int i)
{
	a[i].l = l;
	a[i].r = r;
	a[i].ls = a[i].rs = a[i].ms = r - l + 1;
	if (l != r)
	{
		int mid = (l + r) >> 1;
		init(l, mid, i * 2);
		init(mid + 1, r, 2 * i + 1);
	}
}

void insert(int i, int t, int x)
{
	if (a[i].l == a[i].r)
	{
		if (x == 1)
			a[i].ls = a[i].rs = a[i].ms = 1;//修复  
		else
			a[i].ls = a[i].rs = a[i].ms = 0;//破坏  
		return;
	}
	int mid = (a[i].l + a[i].r) >> 1;
	if (t <= mid)
		insert(2 * i, t, x);
	else
		insert(2 * i + 1, t, x);
	a[i].ls = a[2 * i].ls;//左区间  
	a[i].rs = a[2 * i + 1].rs;//右区间  
	a[i].ms = max(max(a[2 * i].ms, a[2 * i + 1].ms), a[2 * i].rs + a[2 * i + 1].ls);//父亲区间内的最大区间必定是，左子树最大区间，右子树最大区间，左右子树合并的中间区间，三者中最大的区间值  
	if (a[2 * i].ls == a[2 * i].r - a[2 * i].l + 1)//左子树区间满了的话，父亲左区间要加上右孩子的左区间  
		a[i].ls += a[2 * i + 1].ls;
	if (a[2 * i + 1].rs == a[2 * i + 1].r - a[2 * i + 1].l + 1)//同理  
		a[i].rs += a[2 * i].rs;
}

int query(int i, int t)
{
	if (a[i].l == a[i].r || a[i].ms == 0 || a[i].ms == a[i].r - a[i].l + 1)//到了叶子节点或者该访问区间为空或者已满都不必要往下走了  
		return a[i].ms;
	int mid = (a[i].l + a[i].r) >> 1;
	if (t <= mid)
	{
		if (t >= a[2 * i].r - a[2 * i].rs + 1)//因为t<=mid，看左子树，a[2*i].r-a[2*i].rs+1代表左子树右边连续区间的左边界值，如果t在左子树的右区间内，则要看右子树的左区间有多长并返回  
			return query(2 * i, t) + query(2 * i + 1, mid + 1);
		else
			return query(2 * i, t);//如果不在左子树的右边界区间内，则只需要看左子树  
	}
	else
	{
		if (t <= a[2 * i + 1].l + a[2 * i + 1].ls - 1)//同理  
			return query(2 * i + 1, t) + query(2 * i, mid);
		else
			return query(2 * i + 1, t);
	}
}

int main()
{
	int i, j, x;
	char ch[2];
	while (~scanf("%d%d", &n, &m))
	{
		top = 0;
		init(1, n, 1);
		while (m--)
		{
			scanf("%s", ch);
			if (ch[0] == 'D')
			{
				scanf("%d", &x);
				s[top++] = x;
				insert(1, x, 0);
			}
			else if (ch[0] == 'Q')
			{
				scanf("%d", &x);
				printf("%d\n", query(1, x));
			}
			else
			{
				if (x>0)
				{
					x = s[--top];
					insert(1, x, 1);
				}
			}
		}
	}

	return 0;
}