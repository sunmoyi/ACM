#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int u, v, len;
	node(int u = 0, int v = 0, int len = 0) :u(u), v(v), len(len){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len > b.len;
	}
}way[maxn * maxn];

int father[maxn];
int rankk[maxn];
int E, V;

void init(int n)
{
	for (int i = 0; i <= n; i++)
		father[i] = i;
	memset(rankk, 0, sizeof(rankk));
}

int find(int x)
{
	int far = x;
	while (father[far] != far)
		far = father[far];

	int i = x;
	while (father[i] != far)
	{
		int temp = father[i];
		father[i] = far;
		i = temp;
	}
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	if (rankk[x] < rankk[y])
		father[y] = x;
	else
	{
		father[x] = y;
		if (rankk[x] == rankk[y])
			rankk[x]++;
	}
	father[x] = y;
	return true;
}

int main(void)
{
	int T, Case, a, b, c;
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++)
	{
		scanf("%d %d", &V, &E);
		init(V);
		int top = 1;
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			way[top].u = a;
			way[top].v = b;
			way[top++].len = c;
			way[top].u = b;
			way[top].v = a;
			way[top++].len = c;
		}

		sort(way + 1, way + top);

		int maxx = -1;
		for (int i = 1; i < top; i++)
		{
			if (unoin(way[i].u, way[i].v))
			{
				if (find(1) == find(V))
				{
					maxx = way[i].len;
					break;
				}
			}
		}
		printf("Scenario #%d:\n", Case);
		printf("%d\n\n", maxx);
	}
	return 0;
}