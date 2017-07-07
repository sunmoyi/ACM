#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn  100000005

using namespace std;

struct node {
	int len;
	int from;
	int to;
	node(int from = 0, int len = 0, int to = 0) : to(to), len(len), from(from) {}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
node k[maxn];
int V, E;
int father[maxn];
int rankk[maxn];
int num[2010];

void init(int x)
{
	for (int i = 0; i <= x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
	}
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

bool unionn(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	//father[x] = y;
	father[x] = y;
	return true;
}

int kruskal(void)
{
	int ans = 0;
	for (int i = 1; i < E; i++)
	{
		if (unionn(k[i].from, k[i].to))
			ans += k[i].len;
	}
	return ans;
}

int main(void)
{
	while (scanf("%d", &V) != EOF)
	{
		init(V + 1);
		E = 1;
		for (int i = 1; i <= V; i++)
			scanf("%d", &num[i]);
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (i != j)
				{
					k[E].from = i;
					k[E].to = j;
					k[E++].len = -(num[i] ^ num[j]);
					k[E].from = j;
					k[E].to = i;
					k[E++].len = -(num[i] ^ num[j]);
				}
			}
		}
		sort(k + 1, k + E);
		
		int ans = kruskal();
		printf("%d\n", -ans);
	}
	return 0;
}
