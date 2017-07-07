#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005

using namespace std;

int father[maxn];
int rankk[maxn];
bool vis[maxn];
int n, m;

void init(int x)
{
	for (int i = 0; i <= x; i++)
	{
		father[i] = i;
		//rankk[i] = 0;
	}
	memset(vis, false, sizeof(vis));
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	//int i = x;
	//while (father[i] != far)
	//{
	//	int temp = father[i];
	//	father[i] = far;
	//	i = temp;
	//}
	return far;
}

void mix(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
		return;

	//if (rankk[fx] < rankk[fy])
		father[fx] = fy;
	//else
	//{
	//	father[fy] = fx;
	//	if (rankk[fx] == rankk[fy])
	//		rankk[fx]++;
	//}
}

int main(void)
{
	int a, b, n, m;
	int casee = 1;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		init(n + 1);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			mix(a, b);
		}
		int summ = 0, t;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[t = find(i)])
			{
				vis[t] = true;
				summ++;
			}
		}
		printf("Case %d: %d\n", casee++, summ);
	}
	return 0;
}