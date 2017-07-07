#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long int
using namespace std;

int p[15], cnt[10], w[20], len;
LL f[30][60005][2];

bool check(int j)
{
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; j; ++i, j /= 3)
		cnt[i] = j % 3;
	for (int i = 0; i<10; ++i)
		if (cnt[i])
		{
			if (i & 1)
			{
				if (cnt[i] & 1)return 0;
			}
			else if (!(cnt[i] & 1))return 0;
		}
	return 1;
}

LL cal(LL n)
{
	if (!n)return 0;
	memset(f, 0, sizeof f);
	LL m = n;
	len = 0;
	while (m) { w[++len] = m % 10; m /= 10; }
	f[len][p[w[len]]][1] = 1;
	for (int i = len; i>0; --i)f[i][0][0] = 1;
	for (int i = w[len] - 1; i>0; --i)
		++f[len][p[i]][0];
	for (int i = len - 1, s; i>0; --i)
	{
		for (int j = 0; j<59049; ++j)
		{
			if (!f[i + 1][j][1] && !f[i + 1][j][0])continue;
			for (int k = 0; k <= 9; ++k)
			{
				if (!j && !k)continue;//特殊处理前导零
				s = j / p[k] % 3 + 1;
				s = s & 1;
				if (s == 0)s = 2;
				s = j - j / p[k] % 3 * p[k] + s*p[k];
				if (k == w[i])f[i][s][1] += f[i + 1][j][1];
				else if (k<w[i])f[i][s][0] += f[i + 1][j][1];
				f[i][s][0] += f[i + 1][j][0];
			}
		}
	}
	LL ans = 0;
	for (int j = 1; j<59049; ++j)
		if (check(j))ans += f[1][j][0] + f[1][j][1];
	return ans;
}

int main()
{
	p[0] = 1;
	for (int i = 1; i <= 11; ++i)p[i] = p[i - 1] * 3;
	int cas;
	LL a, b;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", cal(b) - cal(a - 1));
	}
	return 0;
}