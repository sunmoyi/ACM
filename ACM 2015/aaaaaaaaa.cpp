#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2050
#define INF 0x3f3f3f3f

using namespace std;

int n, a[maxn], dist[maxn];
bool vis[maxn];

long long prim()
{
	memset(dist, 0xef, sizeof (dist));
	dist[1] = 0;
	long long ret = 0;
	int x, t;
	for (int i = 1; i <= n; i++)
	{
		t = -INF;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dist[j] > t)
				t = dist[j], x = j;
		vis[x] = 1;
		ret += dist[x];
		for (int j = 1; j <= n; j++)
			if (!vis[j])
				dist[j] = max(dist[j], (a[x] ^ a[j]));
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%lld\n", prim());
	return 0;
}
