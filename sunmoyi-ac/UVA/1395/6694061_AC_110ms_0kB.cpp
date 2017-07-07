#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 11000

using namespace std;

struct node {
	int len;
	int from;
	int to;
	node(int from = 0, int len = 0, int to = 0) :from(from), len(len), to(to) {}
	friend bool operator < (const node &a, const node&b)
	{
		return a.len < b.len;
	}
}k[maxn];
int father[maxn];
int V, E;

void init()
{
	for (int i = 1; i < maxn; i++)
		father[i] = i;
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	else
		father[x] = y;
	return true;
}

int kulskal(void)
{
	int ans = 0x3f3f3f3f;
	int tot = 0;

	for (int L = 1; L <= E; L++)
	{
		init();
		tot = 0;
		for (int R = L; R <= E; R++)
		{
			if (unoin(k[R].from, k[R].to))
				tot++;
			if (tot == V - 1)
			{
				ans = min(ans, k[R].len - k[L].len);
				break;
			}
		}
	}
	if (ans == 0x3f3f3f3f)
		return -1;
	else
		return ans;
}

int main(void)
{
	while (scanf("%d %d", &V, &E) != EOF && (V + E))
	{
		for (int i = 1; i <= E; i++)
			scanf("%d %d %d", &k[i].from, &k[i].to, &k[i].len);

		sort(k + 1, k + E + 1);
		int ans = kulskal();
		printf("%d\n", ans);
	}
	return 0;
}