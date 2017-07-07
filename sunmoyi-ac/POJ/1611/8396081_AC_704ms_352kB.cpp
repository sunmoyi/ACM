#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30030
#define maxm 505

using namespace std;

int father[maxn];
int rankk[maxn];
int n, m;

int find(int i)
{
	int x = i;
	while (x != father[x])
		x = father[x];
	return x;
}

int main(void)
{
	int a, b, c;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		for (int i = 0; i <= n; i++)
		{
			father[i] = i;
			rankk[i] = 0;
		}
		while (m--)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			for (int i = 1; i < a; i++)
			{
				scanf("%d", &c);
				father[find(b)] = find(c);
			}
		}

		int num = 1;
		int k1 = find(0);
		for (int i = 1; i < n; i++)
		{
			if (k1 == find(i))
				num++;
		}
		printf("%d\n", num);
	}
	return 0;
}