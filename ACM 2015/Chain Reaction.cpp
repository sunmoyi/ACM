#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int a, b;
}num[maxn];

bool cmp(node a, node b)
{
	return a.a < b.a;
}

int dp[maxn];

int find(int l, int r, int val)
{
	int ans = 0;
	while (r >= l)
	{
		int mid = (l + r) >> 1;
		if (num[mid].a >= val)
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &num[i].a, &num[i].b);
	
	sort(num + 1, num + 1 + n, cmp);

	dp[0] = 0; int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		int pos = find(1, n, num[i].a - num[i].b);
		dp[i] = dp[pos - 1] + i - pos;
		ans = min(ans, dp[i] + n - i); 
	}
	printf("%d\n", ans);
	return 0;
}