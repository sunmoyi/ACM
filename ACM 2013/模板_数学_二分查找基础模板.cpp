#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define maxn 10005
#define INF 0xfffffff
using namespace std;

int n, k;
int a[maxn];

int solve()
{
	int l = -1, u = n;
	while (l + 1 < u)
	{
		int mid = (l + u) / 2;
		if (a[mid] >= k)
			u = mid;
		else
			l = mid;
	}
	return l + 1;
}

int main(void)
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int ans = solve();
		printf("%d", ans);
	}
	return 0;
}