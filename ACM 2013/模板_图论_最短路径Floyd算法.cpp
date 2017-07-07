#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0xfffffff
#define maxn 1005
using namespace std;

struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
int mapp[maxn][maxn];
int V, E;
int mindist[maxn][maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			mindist[i][j] = INF;
		}
	}
}

int Floyd(int s, int t)
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
				mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
			}
		}
	}
	return mindist[s][t];
}

int main(void)
{
	int a, b, len;
	int S, T;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			mapp[a][b] = len;
		}
		scanf("%d %d", &S, &T);
		Floyd(S, T);
		int ans = Floyd(S, T);
		printf("%d\n", ans);
	}
	return 0;
}