#include<cstdio>
#include<cstring>
#include<algorithm>

#define inf 1e9
using namespace std;
int t[10001];
int n, ans = 0;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		int k, num, ti, x, y;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &k, &ti);
			t[k] = ti;
			scanf("%d", &x);
			while (x != 0)
			{
				t[k] = max(t[k], ti + t[x]);
				ans = max(ans, t[k]);
				scanf("%d", &x);
			}
		}
		printf("%d", ans);
	}
	return 0;
}