#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 220010

using namespace std;

int N, p[maxn];
char str[maxn], b[maxn];

void init()
{
	int i;
	for (i = 0; str[i]; i++)
		b[2 * i + 1] = '#',
		b[2 * i + 2] = str[i];
	N = 2 * i + 1;
	b[0] = '$', b[N] = b[N + 1] = '#';
}

void solve()
{
	int i, id = 0, maxx = 0, ans = 0;
	for (i = 1; i <= N; i++)
	{
		if (p[id] + id > i)
			p[i] = min(p[id * 2 - i], p[id] - (i - id));
		else
			p[i] = 1;
		while (b[i + p[i]] == b[i - p[i]])
			++p[i];
		if (i + p[i] > maxx)
			maxx = i + p[i], id = i;
		ans = max(ans, p[i] - 1);
	}
	printf("%d\n", ans);
}

int main (void)
{
	while (scanf("%s", str) != EOF)
	{
		init();
		solve();
	}
	return 0;
}