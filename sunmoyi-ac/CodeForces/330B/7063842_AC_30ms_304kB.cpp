#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300010

using namespace std;

bool vis[maxn];
int E, V;
int a, b;

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF)
	{
		memset(vis, false, sizeof(vis));
		
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &a, &b);
			vis[a] = true;
			vis[b] = true;
		}
		int i = 1;
		for (; i <= V; i++)
			if (!vis[i])
				break;

		printf("%d\n", V - 1);
		for (int j = 1; j <= V; j++)
		{
			if (i != j)
				printf("%d %d\n", i, j);
		}
	}
	return 0;
}