#include <stdio.h>
#include <string.h>

const int MAX = 200010;

int wa[MAX], wb[MAX], wv[MAX], ws[MAX];
int sa[MAX];

int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(char *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i<m; i++)
		ws[i] = 0;
	for (i = 0; i<n; i++)
		ws[x[i] = r[i]]++;
	for (i = 1; i<m; i++)
		ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--)
		sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p<n; j <<= 1, m = p)
	{
		for (p = 0, i = n - j; i<n; i++)
			y[p++] = i;
		for (i = 0; i<n; i++)
			if (sa[i] >= j)
				y[p++] = sa[i] - j;
		for (i = 0; i<n; i++)
			wv[i] = x[y[i]];
		for (i = 0; i<m; i++)
			ws[i] = 0;
		for (i = 0; i<n; i++)
			ws[wv[i]]++;
		for (i = 1; i<m; i++)
			ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i<n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}

int rank[MAX], height[MAX];

void calheight(char *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for (i = 0; i<n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}

bool check(int *sa, int i, int len1)
{
	return sa[i] <= len1 != sa[i - 1] <= len1;
}

char a[MAX], b[MAX];

int main()
{
	while (~scanf("%s%s", a, b))
	{
		int len1 = strlen(a);
		int len2 = strlen(b);
		int len = len1 + len2 + 1;
		a[len1] = 0;
		for (int i = 0; i<len2; i++)
			a[len1 + 1 + i] = b[i];
		da(a, sa, len, 123);
		calheight(a, sa, len);
		int ans = 0;
		for (int i = 1; i<len; i++)
			if (height[i]>ans && check(sa, i, len1))
				ans = height[i];
		printf("%d\n", ans);
	}
	return 0;
}