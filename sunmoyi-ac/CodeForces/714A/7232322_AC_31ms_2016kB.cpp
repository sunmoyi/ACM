#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a, b, c, d, p;
long long ans, l, r;

int main(void)
{
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &p);
	l = max(a, c);
	r = min(b, d);
	if (l > r)
		ans = 0;
	else
	{
		ans = r - l + 1;
		if (p >= l && p <= r)
			ans--;
	}
	printf("%lld\n", ans);
}