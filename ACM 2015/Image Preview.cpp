#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010

using namespace std;

int  sum[maxn << 1];
char s[maxn];

int main(void)
{
	int n, a, b, T, h, r, ans, ss;
	scanf("%d %d %d %d", &n, &a, &b, &T);
	scanf("%s", s);
	ss = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'w')
			sum[i] = sum[i + n] = b + 1;
		else
			sum[i] = sum[i + n] = 1;
		ss += sum[i];
	}
	ss -= sum[0];
	h = 1, r = n; ans = 0;
	while (h <= n && r < 2 * n)
	{
		ss += sum[r++];
		while (r - h > n || ss + (r - h - 1 + min(r - n - 1, n - h)) * a > T)
			ss -= sum[h++];
		ans = max(ans, r - h);
	}
	printf("%d\n", ans);
	return 0;
}