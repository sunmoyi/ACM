#include <stdio.h>
#include <string.h>
#include<algorithm>

using namespace std;

const int MAX = 200010;
/*
int wa[MAX], wb[MAX], wv[MAX], ws[MAX];
int sa[MAX];

int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
// da函数求SA数组
void da(char *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++)
		ws[i] = 0;
	for (i = 0; i < n; i++)
		ws[x[i] = r[i]]++;
	for (i = 1; i < m; i++)
		ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--)
		sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p < n; j <<= 1, m = p)
	{
		for (p = 0, i = n - j; i < n; i++)
			y[p++] = i;
		for (i = 0; i < n; i++)
			if (sa[i] >= j)
				y[p++] = sa[i] - j;
		for (i = 0; i < n; i++)
			wv[i] = x[y[i]];
		for (i = 0; i < m; i++)
			ws[i] = 0;
		for (i = 0; i < n; i++)
			ws[wv[i]]++;
		for (i = 1; i < m; i++)
			ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}
*/

// da函数超时用下面的dc3
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAX], wb[MAX], wv[MAX], ws[MAX];

int c0(int *r, int a, int b)
{
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b)
{
	if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	else return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}
void sort(int *r, int *a, int *b, int n, int m)
{
	int i;
	for (i = 0; i < n; i++) wv[i] = r[a[i]];
	for (i = 0; i < m; i++) ws[i] = 0;
	for (i = 0; i < n; i++) ws[wv[i]]++;
	for (i = 1; i < m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
	return;
}
void dc3(int *r, int *sa, int n, int m)
{
	int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
	r[n] = r[n + 1] = 0;
	for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
	if (p < tbc) dc3(rn, san, tbc, p);
	else for (i = 0; i < tbc; i++) san[rn[i]] = i;
	for (i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
	if (n % 3 == 1) wb[ta++] = n - 1;
	sort(r, wb, wa, ta, m);
	for (i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	for (; i < ta; p++) sa[p] = wa[i++];
	for (; j < tbc; p++) sa[p] = wb[j++];
	return;
}

int rankk[MAX], height[MAX];
//calheight函数 求height数组
void calheight(char *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
		rankk[sa[i]] = i;
	for (i = 0; i < n; height[rankk[i++]] = k)
		for (k ? k-- : 0, j = sa[rankk[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}

int RMQ[MAX];
int mm[MAX];

int best[20][MAX];//best[i][j] 表示从j开始的长度为2的i次方的一段元素的最小值   
void initRMQ(int n)///O(Nlogn) 预处理
{
	int i, j, a, b;
	for (mm[0] = -1, i = 1; i <= n; i++)
		mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
	for (i = 1; i <= n; i++)
		best[0][i] = i;
	for (i = 1; i <= mm[n]; i++)
	{
		for (j = 1; j <= n + 1 - (1 << i); j++)
		{
			a = best[i - 1][j];
			b = best[i - 1][j + (1 << (i - 1))];
			if (RMQ[a] < RMQ[b]) best[i][j] = a;
			else best[i][j] = b;
		}
	}
	return;
}
int askRMQ(int a, int b)///询问a,b后缀的最长公共前缀  O(1)查询
{
	int t;
	t = mm[b - a + 1]; b -= (1 << t) - 1;
	a = best[t][a]; b = best[t][b];
	return RMQ[a]<RMQ[b] ? a : b;
}

int lcp(int a, int b)
{
	int t;
	a = rankk[a]; b = rankk[b];
	if (a>b)
	{
		t = a; a = b; b = t;
	}
	return(height[askRMQ(a + 1, b)]);
}