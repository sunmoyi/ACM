#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510

using namespace std;

struct node{
	int len;
	int from;
	int to;
	node(int from = 0, int len = 0, int to = 0) :to(to), len(len), from(from) {}
	friend bool operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
}k[maxn * maxn];
int V, E;
int father[maxn];

void init(int x)
{
	for (int i = 0; i <= x + 1; i++)
		father[i] = i;
}

int find(int x)
{
	int far = x;
	while (far != father[far])
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
	father[x] = y;
	return true;
}

int kruskal(void)
{
	int num = 0, ans = 0;
	for (int i = 0; i < E; i++)
	{
		if (unoin(k[i].from, k[i].to))
		{
			num++;
			ans = k[i].len;
			if (num == V - 1)
				return ans;
		}
	}
}

int main (void)
{
	int T, a;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &V);
			E = 0;
			init(V + 1);
			for (int i = 1; i <= V; i++)
			{
				for (int j = 1; j <= V; j++)
				{
					scanf("%d", &a);
					if (i != j)
					{
						k[E].from = i;
						k[E].to = j;
						k[E++].len = a;
						k[E].from = j;
						k[E].to = i;
						k[E++].len = a;
					}
				}
			}
			sort(k, k + E);
			int ans = kruskal();
			printf("%d\n", ans);
		}
	}
	return 0;
}