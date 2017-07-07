#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

struct node {
	int len, weight;
	bool vis;
	node(int len = 0, int weight = 0, bool vis = false) :len(len), weight(weight), vis(vis){}
}num[maxn];
int sum;

bool cmp(node a, node b)
{
	if (a.len == b.len)
		return a.weight < b.weight;
	return a.len < b.len;
}

int main (void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
		{
			scanf("%d %d", &num[i].len, &num[i].weight);
			num[i].vis = false;
		}
		sort(num + 1, num + sum + 1, cmp);

		int temp = sum;
		int ans = 0;
		while (temp)
		{
			node now = node(-1, -1);
			ans++;
			for (int i = 1; i <= sum; i++)
			{
				if (!num[i].vis && num[i].len >= now.len && num[i].weight >= now.weight)
				{
					num[i].vis = true;
					temp--;
					now = num[i];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}