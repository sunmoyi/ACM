#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int T, n, ans, Min, Max;
int h[100005], p[100005], q[100005];
int main() 
{
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &h[i]);
		memset(p, 0, sizeof(p));
		memset(q, 0, sizeof(q));
		Min = h[1];
		for (int i = 2; i <= n; ++i)
		{
			p[i] = h[i] - Min;
			if (h[i]<Min) Min = h[i];
		}
		Max = h[n];
		for (int i = n - 1; i >= 1; --i)
		{
			q[i] = Max - h[i];
			if (h[i]>Max) Max = h[i];
		}
		for (int i = 2; i <= n; ++i)
			p[i] = max(p[i], p[i - 1]);
		for (int i = n - 1; i >= 1; --i)
			q[i] = max(q[i], q[i + 1]);
		ans = 0;
		for (int i = 2; i <= n - 1; ++i)
			if (p[i - 1] + q[i]>ans)
				ans = p[i - 1] + q[i];
		printf("%d\n", max(ans, 0));
	}
}