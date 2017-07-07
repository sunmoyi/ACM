#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 31000

using namespace std;

int parent[maxn];
int sum[maxn];
int under[maxn];

int getparent(int a)
{
	if (parent[a] == a)
		return a;

	int t = getparent(parent[a]);
	under[a] += under[parent[a]];
	parent[a] = t;
	return parent[a];
}

void merge(int a, int b)
{
	int n;
	int pa = getparent(a);
	int pb = getparent(b);
	if (pa == pb)
		return;
	parent[pb] = pa;
	under[pb] = sum[pa];
	sum[pa] += sum[pb];
}

int main()
{
	int p;
	for (int i = 0; i < maxn; i++)
	{
		sum[i] = 1;
		under[i] = 0;
		parent[i] = i;
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++)
	{
		char s[20];
		int a, b;
		scanf("%s", s);
		if (s[0] == 'M')
		{
			scanf("%d %d", &a, &b);
			merge(b, a);
		}
		else
		{
			scanf("%d", &a);
			getparent(a);
			printf("%d\n", under[a]);
		}
	}
	return 0;
}