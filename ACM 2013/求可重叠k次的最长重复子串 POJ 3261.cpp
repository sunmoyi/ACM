/**********************************************************
题目大意：
给定一个字符串,求至少出现k次的最长重复子串,这k个子串可以重叠;

算法分析:
这个题和PKU1743的做法差不多;
也是先二分答案，然后将后缀分成若干组;
即先用后缀数组求出height数组;
然后利用height数组把排序后的后缀分成若干组;
不同的这里要判断有没有一个组的后缀个数不小于k;
如果有就存在等于k个相同的子串满足条件,否则就不存在;
***********************************************************/
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 20010;
const int M = 1000010;//r数组的最大值

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[N], wb[N], wv[N], _ws[M];

int c0(int *r, int a, int b)
{
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b)
{
	if (k == 2)
		return r[a]<r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	else
		return r[a]<r[b] || r[a] == r[b] && wv[a + 1]<wv[b + 1];
}

void sort(int *r, int *a, int *b, int n, int m)
{
	for (int i = 0; i<n; i++)
		wv[i] = r[a[i]];
	for (int i = 0; i<m; i++)
		_ws[i] = 0;
	for (int i = 0; i<n; i++)
		_ws[wv[i]]++;
	for (int i = 1; i<m; i++)
		_ws[i] += _ws[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--_ws[wv[i]]] = a[i];
	return;
}

void dc3(int *r, int *sa, int n, int m)
{
	int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
	r[n] = r[n + 1] = 0;
	for (i = 0; i<n; i++)
	{
		if (i % 3 != 0)
			wa[tbc++] = i;
	}
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i<tbc; i++)
	{
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
	}
	if (p<tbc)
		dc3(rn, san, tbc, p);
	else
	{
		for (i = 0; i<tbc; i++)
			san[rn[i]] = i;
	}
	for (i = 0; i<tbc; i++)
	{
		if (san[i]<tb)
			wb[ta++] = san[i] * 3;
	}
	if (n % 3 == 1)
		wb[ta++] = n - 1;
	sort(r, wb, wa, ta, m);
	for (i = 0; i<tbc; i++)
		wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i<ta && j<tbc; p++)
	{
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	}
	for (; i<ta; p++)
		sa[p] = wa[i++];
	for (; j<tbc; p++)
		sa[p] = wb[j++];
	return;
}

int rank[N], height[N];

void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for (i = 0; i<n; height[rank[i++]] = k)
	{
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	}
	return;
}

int check(int n, int k, int mid)
{
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		if (height[i] >= mid)
		{
			s++;
			if (s >= k)
				return 1;
		}
		else
			s = 1;
	}
	return 0;
}

int r[N * 3], sa[N * 3];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &r[i]);
	}
	r[n] = 0;
	dc3(r, sa, n + 1, M);
	calheight(r, sa, n);
	int min = 1;
	int max = n;
	while (min <= max)
	{
		int mid = (min + max) >> 1;
		if (check(n, k, mid))
			min = mid + 1;
		else
			max = mid - 1;
	}
	printf("%d\n", max);
	return 0;
}