#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define maxn 10005
#define INF 0xfffffff
using namespace std;

int n, m;
int x[maxn];

bool check(int d)
{
	int last = 0;
	for (int i = 1; i < m; i++)
	{
		int crt = last + 1;
		while (crt < n && x[crt] - x[last] < d)
			crt++;
		if (crt == m)
			return false;
		last = crt;
	}
	return true;
}

int solve()
{
	sort(x, x + n);

	int l = 0, u = INF;

	while (l + 1 < u)
	{
		int mid = (l + u) / 2;
		if (check(mid))
			l = mid;
		else
			u = mid;
	}
	return l;
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(x, 0, sizeof(x));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
