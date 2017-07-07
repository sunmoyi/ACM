#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool vis[1010];

int main(void)
{
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = a + 1; i <= b; i++)
			vis[i] = true;
		for (int i = c + 1; i <= d; i++)
			vis[i] = true;

		int ans = 0;
		for (int i = 0; i <= 100; i++)
			if (vis[i])
				ans++;

		printf("%d\n", ans);
	}
	return 0;
}