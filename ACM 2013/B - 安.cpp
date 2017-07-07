/*
 *百度一下
 ***中位数定理***
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int const MAX = 1e5 + 5;
ll a[MAX];
vector <ll> vt[MAX];

int main()
{
	int n, m;
	ll ma = 0, dif = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%I64d", &a[i]);
		ma = max(ma, a[i]);
	}
	for (int i = 0; i < m - 1; i++)
	{
		if (a[i] == a[i + 1])
			continue;
		dif += abs(a[i + 1] - a[i]);
		vt[a[i]].push_back(a[i + 1]);
		vt[a[i + 1]].push_back(a[i]);
	}
	ll ans = dif;
	for (int i = 1; i <= ma; i++)
	{
		ll tmp = dif;
		int sz = vt[i].size();
		if (sz == 0)
			continue;
		sort(vt[i].begin(), vt[i].end());
		int mid = vt[i][sz / 2];
		for (int j = 0; j < sz; j++)
			tmp = tmp + abs(vt[i][j] - mid) - abs(i - vt[i][j]);
		ans = min(ans, tmp);
	}
	printf("%I64d\n", ans);
}
