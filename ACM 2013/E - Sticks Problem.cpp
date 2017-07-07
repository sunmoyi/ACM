#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  

using namespace std;

const int maxn = 50010;
int n, len[maxn];
int minl[maxn][20], maxl[maxn][20];


int Min(int l, int r)
{
	if (len[l] < len[r]) return l;
	return r;
}

int Max(int l, int r)
{
	if (len[l] > len[r]) return l;
	return r;
}

void init()
{
	for (int i = 1; i <= n; ++i)
		minl[i][0] = maxl[i][0] = i;
	for (int j = 1; (1 << j) <= n; ++j)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			minl[i][j] = Min(minl[i][j - 1], minl[i + (1 << (j - 1))][j - 1]);
			maxl[i][j] = Max(maxl[i][j - 1], maxl[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int minrmq(int l, int r)
{
	int k = (int)(log(double(r) - l + 1) / log(2.0));
	return Min(minl[l][k], minl[r + 1 - (1 << k)][k]);
}

int maxrmq(int l, int r)
{
	int k = (int)(log(double(r) - l + 1) / log(2.0));
	return Max(maxl[l][k], maxl[r + 1 - (1 << k)][k]);
}

int bsearch(int x, int l, int r)
{
	while (l <= r)
	{
		if (l == r) return l;
		int m = (l + r) >> 1;
		if (len[x] < len[minrmq(l, m)])
			l = m + 1;
		else r = m;
	}
}

void work()
{
	int ans = 0;
	for (int i = 1; i + ans < n; ++i)
	{
		int r = bsearch(i, i + 1, n);
		int k = maxrmq(i, r);
		if (len[k] > len[i])
			ans = max(ans, k - i);
	}
	if (ans == 0) printf("-1\n");
	else printf("%d\n", ans);
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; ++i)
			scanf("%d", &len[i]);
		init();
		work();
	}
	return 0;
}