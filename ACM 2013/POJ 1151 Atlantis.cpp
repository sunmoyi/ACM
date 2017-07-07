#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
double y[210];
struct CNode
{
	int L, R;
	double Len; //当前,本区间上有多长的部分是落在那些矩形中的
	int Covers;//本区间当前被多少个矩形完全包含
};
CNode tree[4100];

struct CLine {
	double x, y1, y2;
	bool bLeft; //是否是矩形的左边 
} lines[210];

int nNodeCount = 0;

bool operator< (const CLine & l1, const CLine & l2)
{
	return l1.x < l2.x;
}

int bin_search(int s, int e, double val)
{ //在区间[s,e)中查找 val,找不到就返回 e
	int L = s;
	int R = e - 1;
	while (L <= R) 
	{
		int mid = L + (R - L) / 2;
		if (!(y[mid] > val || y[mid] < val))
			return mid;
		else if (val < y[mid])
			R = mid - 1;
		else
			L = mid + 1;
	}
	return e;
}

int Mid(int root)
{
	return (tree[root].L + tree[root].R) >> 1;
}

void Insert(int root, int L, int R)
//在区间root 插入矩形左边的一部分或全部，该左边的一部分或全部覆盖了区间[L,R]
{
	if (tree[root].L == L && tree[root].R == R)
	{
		tree[root].Len = y[R + 1] - y[L];
		tree[root].Covers++;
		return;
	}
	if (R <= Mid(root))
		Insert(root * 2, L, R);
	else if (L >= Mid(root) + 1)
		Insert(root * 2 + 1, L, R);
	else {
		Insert(root * 2, L, Mid(root));
		Insert(root * 2 + 1, Mid(root) + 1, R);
	}
	if (tree[root].Covers == 0) //如果不为0，则说明本区间当前仍然被某个矩形完全包含，则不能更新 Len
		tree[root].Len = tree[root * 2].Len +
		tree[root * 2 + 1].Len;
}

void Delete(int root, int L, int R)
{
	// 在区间root 删除矩形右边的一部分或全部，该矩形右边的一部分或全部覆盖了区间[L, R]
	if (tree[root].L == L && tree[root].R == R)
	{
		tree[root].Covers--;
		if (tree[root].Covers == 0)
			if (tree[root].L == tree[root].R)
				tree[root].Len = 0;
			else
				tree[root].Len = tree[root * 2].Len +
				tree[root * 2 + 1].Len;
		return;
	}
	if (R <= Mid(root))
		Delete(root *  2, L, R);
	else if (L >= Mid(root) + 1)
		Delete(root * 2 + 1, L, R);
	else
	{
		Delete(root * 2, L, Mid(root));
		Delete(root * 2 + 1, Mid(root) + 1, R);
	}
	if (tree[root].Covers == 0) //如果不为0，则说明本区间当前仍然被某个矩形完全包含，则不能更新 Len
		tree[root].Len = tree[root * 2].Len + tree[root * 2 + 1].Len;
}

void BuildTree(int root, int L, int R)
{
	tree[root].L = L;
	tree[root].R = R;
	tree[root].Covers = 0;
	tree[root].Len = 0;
	if (L == R)
		return;
	BuildTree(root * 2, L, (L + R) / 2);
	BuildTree(root * 2 + 1, (L + R) / 2 + 1, R);
}

int main()
{
	int n;
	int i, j, k;
	double x1, y1, x2, y2;
	int yc, lc;
	int nCount = 0;
	int t = 0;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		t++;
		yc = lc = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			y[yc++] = y1;
			y[yc++] = y2;
			lines[lc].x = x1;
			lines[lc].y1 = y1;
			lines[lc].y2 = y2;
			lines[lc].bLeft = true;
			lc++; 
			lines[lc].x = x2;
			lines[lc].y1 = y1;
			lines[lc].y2 = y2;
			lines[lc].bLeft = false;
			lc++;
		}
		sort(y, y + yc);
		yc = unique(y, y + yc) - y;//“删除”所有相邻的重复元素
		nNodeCount = 0;
		//yc 是横线的条数，yc- 1是纵向区间的个数，这些区间从0
		//开始编号，那么最后一个区间
		//编号就是yc - 1 -1
		BuildTree(1, 0, yc - 1 - 1);
		sort(lines, lines + lc);
		double Area = 0;

		for (i = 0; i < lc - 1; i++) 
		{
			int L = bin_search(0, yc, lines[i].y1);
			int R = bin_search(0, yc, lines[i].y2);
			if (lines[i].bLeft)
				Insert(1, L, R - 1);
			else
				Delete(1, L, R - 1);
			Area += tree[1].Len * (lines[i + 1].x - lines[i].x);
		}
		printf("Test case #%d\n", t);
		printf("Total explored area: %.2lf\n", Area);
		printf("\n");
	}
	return 0;
}