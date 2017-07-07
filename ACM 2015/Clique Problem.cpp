#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

struct Node {
	int x, y;
	bool friend operator < (const Node&a, const Node&b)
	{
		return a.x < b.x;
	}
}node[maxn];

int main(void)
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		node[i].x = x - y;
		node[i].y = x + y;
	}
	sort(node + 1, node + n + 1);

	int maxx = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (maxx <= node[i].x)
			maxx = node[i].y, ans++;
		else if (maxx > node[i].y)
			maxx = node[i].y;
	}
	printf("%d\n", ans);
	return 0;
}