#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn  100000005
using namespace std;

struct node{
	int len;
	int from;
	int to;
	node(int from = 0, int len = 0, int to = 0) : to(to), len(len), from(from){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
node k[maxn];
int V, E;
int father[maxn];
int rankk[maxn];

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

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] == rankk[y])
		{
			rankk[x]++;
		}
	}
}

int kruskal(void)
{
	int ans = 0;
	for (int i = 1; i < V; i++)
	{
		if (unionn(k[i].from, k[i].to))
			ans += k[i].len;
	}
	return ans;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init(E);
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &k[i].from, &k[i].to, &k[i].len);
		}
		sort(k + 1, k + V + 1);
		int ans = kruskal();
		printf("%d\n", ans);
	}
	return 0;
}