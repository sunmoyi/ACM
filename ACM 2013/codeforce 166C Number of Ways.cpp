#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500010;
typedef long long LL;

LL a[maxn];
int cnt[maxn];

int main()
{
	int n;
	LL x;
	while (~scanf_s("%d", &n))
	{
		LL s = 0, p = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%lld", &a[i]);
			s += a[i];
		}
		if (s % 3)
		{ 
			puts("0"); 
			continue;
		}
		s /= 3;
		int com = 0;
		for (int i = 1; i <= n; i++)
		{
			p += a[i];
			if (p == s)
				cnt[com++] = i;
		}
		LL ans = 0;
		p = 0;
		for (int i = n; i >= 1; i--)
		{
			p += a[i];
			if (p == s)
			{
				int pos = lower_bound(cnt, cnt + com, i - 1) - cnt;
				ans += pos;
			}
		}
		cout << ans << endl;
	}
	return 0;
}