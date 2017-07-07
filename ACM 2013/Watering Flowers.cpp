#include <stdio.h>  
#include <algorithm>  
#define LL long long  
const int maxn = 2005;
struct node
{
	LL d1, d2;
	friend bool operator < (node n1, node n2)
	{
		return n1.d1 < n2.d1;
	}
} a[maxn];
LL distance(LL x1, LL y1, LL x2, LL y2)
{
	return (LL)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
inline LL Min(LL a, LL b) { return a < b ? a : b; }
inline LL Max(LL a, LL b) { return a > b ? a : b; }
int main()
{
	int n;
	LL x, y, x1, y1, x2, y2;;
	scanf("%d%I64d%I64d%I64d%I64d", &n, &x1, &y1, &x2, &y2);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", &x, &y);
		a[i].d1 = distance(x, y, x1, y1);
		a[i].d2 = distance(x, y, x2, y2);
	}
	a[0].d1 = 0;
	std::sort(a + 1, a + 1 + n); //对d1排序  
	LL ans = 1e18;
	for (int i = 0; i <= n; i++) //需要考虑不使用r1的情况  
	{
		LL v1 = a[i].d1, v2;    //取d1,然后找d2的最大值  
		v2 = 0;
		for (int j = i + 1; j <= n; j++)
			v2 = Max(v2, a[j].d2);
		ans = Min(ans, v1 + v2);
	}
	printf("%I64d", ans);
	return 0;
}