#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int h[maxn];
int h1[maxn];
int h2[maxn];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(h1, 0, sizeof(h1));
		memset(h2, 0, sizeof(h2));
		for (int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		for (int i = 1; i <= n; i++)
			h1[i] = min(h1[i - 1] + 1, h[i]);
		for (int i = n; i >= 1; i--)
			h2[i] = min(h2[i + 1] + 1, h[i]);
		int ans = -1;
		for (int i = 1; i <= n; i++)
			ans = max(ans, min(h1[i], h2[i]));
		printf("%d\n", ans);
	}
	return 0;
}