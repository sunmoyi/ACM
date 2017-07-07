#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10010

using namespace std;

int father[maxn];
bool vis[maxn];
int n, sum;
int x, y, a, b;

int main(void)
{
	scanf("%d", &n);
	while (n--)
	{
		memset(father, -1, sizeof(father));
		memset(vis, false, sizeof(vis));
		scanf("%d", &sum);
		for (int i = 1; i < sum; i++)
		{
			scanf("%d %d", &a, &b);
			father[b] = a;
		}
		scanf("%d %d", &x, &y);
		while (father[x] != -1)
		{
			vis[x] = true;
			x = father[x];
		}
		while (father[y] != -1)
		{
			if (vis[y] == true)
				break;
			y = father[y] ;
		}
		printf("%d\n", y);
	}
	return 0;
}