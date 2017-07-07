#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
double y[210];
struct CNode
{
	int L, R;
	double Len; //��ǰ,���������ж೤�Ĳ�����������Щ�����е�
	int Covers;//�����䵱ǰ�����ٸ�������ȫ����
};
CNode tree[4100];

struct CLine {
	double x, y1, y2;
	bool bLeft; //�Ƿ��Ǿ��ε���� 
} lines[210];

int nNodeCount = 0;

bool operator< (const CLine & l1, const CLine & l2)
{
	return l1.x < l2.x;
}

int bin_search(int s, int e, double val)
{ //������[s,e)�в��� val,�Ҳ����ͷ��� e
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
//������root ���������ߵ�һ���ֻ�ȫ��������ߵ�һ���ֻ�ȫ������������[L,R]
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
	if (tree[root].Covers == 0) //�����Ϊ0����˵�������䵱ǰ��Ȼ��ĳ��������ȫ���������ܸ��� Len
		tree[root].Len = tree[root * 2].Len +
		tree[root * 2 + 1].Len;
}

void Delete(int root, int L, int R)
{
	// ������root ɾ�������ұߵ�һ���ֻ�ȫ�����þ����ұߵ�һ���ֻ�ȫ������������[L, R]
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
	if (tree[root].Covers == 0) //�����Ϊ0����˵�������䵱ǰ��Ȼ��ĳ��������ȫ���������ܸ��� Len
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
		yc = unique(y, y + yc) - y;//��ɾ�����������ڵ��ظ�Ԫ��
		nNodeCount = 0;
		//yc �Ǻ��ߵ�������yc- 1����������ĸ�������Щ�����0
		//��ʼ��ţ���ô���һ������
		//��ž���yc - 1 -1
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