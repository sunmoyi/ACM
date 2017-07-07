#include<cstdio>
#include<cstring>

using namespace std;

const int max = 1100000;

int wa[max], wb[max], wv[max], ws[max];
int rank[max], height[max];
int sa[max], r[max];
char str[max * 2];

int cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
//函数API   r 原始数组  sa 数组 n 数组长度 m数组内容最大值
void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i<m; i++) ws[i] = 0;
	for (i = 0; i<n; i++) ws[x[i] = r[i]]++;
	for (i = 1; i<m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
	for (p = 1, j = 1; p<n; j *= 2, m = p)
	{
		for (p = 0, i = n - j; i<n; i++) y[p++] = i;
		for (i = 0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i<n; i++) wv[i] = x[y[i]];
		for (i = 0; i<m; i++) ws[i] = 0;
		for (i = 0; i<n; i++) ws[wv[i]]++;
		for (i = 1; i<m; i++) ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i<n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
}
//函数API  r 原始数组   sa sa打表数组    n数组大小
void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for (i = 0; i<n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}

int main(void)
{
	int ans;
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%s", &str);
			int len = strlen(str);
			for (int i = 0; i <= len; i++)
				r[i] = str[i]; 
			da(r, sa, len + 1, 300);
			calheight(r, sa, len);
			int maxx = len *(len - 1) / 2;
			for (int i = 2; i <= len; i++)
				ans -= height[i];
			printf("%d\n", maxx); 
		}
	}
	return 0;
}