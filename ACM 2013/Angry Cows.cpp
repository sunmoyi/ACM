#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define rep(i,j,k) for(i=j;i<k;++i)
const int N = 50005;

int dp1[N], dp2[N], a[N];
int main()
{
	int n, i, j, ans = 0x3f3f3f3f;
	scanf("%d", &n);
	rep(i, 0, n) 
		scanf("%d", a + i), a[i] *= 2;
	sort(a, a + n);
	n = unique(a, a + n) - a;


	memset(dp1, 127, sizeof dp1);
	dp1[j = 0] = -2;
	rep(i, 1, n)
	{
		while (j + 1 < i && a[i] - a[j + 1] > dp1[j + 1] + 2)
			++j;
		dp1[i] = min(a[i] - a[j], dp1[j + 1] + 2);
	}


	memset(dp2, 127, sizeof dp2);
	dp2[j = n - 1] = -2;
	for (i = n - 2; i >= 0; --i) 
	{
		while (j - 1 > i && a[j - 1] - a[i] > dp2[j - 1] + 2)
			--j;
		dp2[i] = min(a[j] - a[i], dp2[j - 1] + 2);
	}


	for (i = 0, j = n - 1; i < j; )
	{
		ans = min(ans, max((a[j] - a[i]) / 2, 2 + max(dp1[i], dp2[j])));
		if (dp1[i + 1] < dp2[j - 1])
			++i; else --j;
	}
	printf("%.1f", 1.0 * ans / 2);
	return 0;
}