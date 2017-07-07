#include<cstdio>
#include<cstring>
#define Max(a, b) a > b? a : b
using namespace std;

const int maxn = 805000;

int wa[maxn], wb[maxn], wv[maxn], ws[maxn], rank[maxn], height[maxn], sa[maxn], s[maxn], loc[maxn];
char str[201], ans[201];
bool vis[4001];
int m;

int cmp(int *r, int a, int b, int l){
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int n, int m){
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i<m; i++) ws[i] = 0;
	for (i = 0; i<n; i++) ws[x[i] = r[i]] ++;
	for (i = 1; i<m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p<n; j *= 2, m = p){
		for (p = 0, i = n - j; i<n; i++) y[p++] = i;
		for (i = 0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i<n; i++) wv[i] = x[y[i]];
		for (i = 0; i<m; i++) ws[i] = 0;
		for (i = 0; i<n; i++) ws[wv[i]] ++;
		for (i = 1; i<m; i++) ws[i] += ws[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i<n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}
void calheight(int *r, int n){
	int i, j, k = 0;
	for (i = 1; i <= n; i++) rank[sa[i]] = i;//»ñÈ¡rankÖµ O(n)
	for (i = 0; i<n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}

int check(int mid, int len)
{
	int count = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= len; i++)
	{
		if (height[i] < mid)
		{
			memset(vis, 0, sizeof(vis));
			count = 0;
			continue;
		}
		if (!vis[loc[sa[i - 1]]])
			vis[loc[sa[i - 1]]] = true, count++;
		if (!vis[loc[sa[i]]])
			vis[loc[sa[i]]] = true, count++;
		if (count == m)
		{
			for (int j = 0; j < mid; j++)
			{
				ans[j] = s[sa[i] + j] + 'a' - 1;
			}
			ans[mid] = '\0';
			return 1;
		}
	}
	return 0;
}

int main(){
	int t, n, i, j, max, temp, flag;
	while (~scanf_s("%d", &m) && m)
	{
		n = 0, temp = 30, flag = 0;
		for (i = 1; i <= m; i++)
		{
			scanf_s("%s", str, 200);
			for (j = 0; j<strlen(str); j++)
			{
				loc[n] = i;
				s[n++] = str[j] - 'a' + 1;
			}
			loc[n] = temp;
			s[n++] = temp++;
		}
		s[n] = 0;
		da(s, n + 1, temp);
		calheight(s, n);
		int left = 0, right = strlen(str), mid;
		while (right >= left)
		{
			mid = (right + left) / 2;
			if (check(mid, n))
			{
				left = mid + 1;
				flag = mid;
			}
			else
				right = mid - 1;
		}
		if (flag)    
			printf("%s\n", ans);
		else       
			printf("IDENTITY LOST\n");
	}
	return 0;
}