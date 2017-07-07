#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 6060

using namespace std;

int a[maxn], n;

int dfs(int l, int r, int bottom)
{
	if (l > r)
		return 0;
	else if (l == r)
	{
		if (a[l] <= bottom)
			return 0;
		else
			return 1;
	}
	int m = min_element(a + l, a + r + 1) - a;
	return min(r - l + 1, dfs(l, m - 1, a[m]) + dfs(m + 1, r, a[m]) + a[m] - bottom);
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = dfs(1, n, 0);
		printf("%d\n", ans);
	}
	return 0;
}