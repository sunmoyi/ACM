#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define maxn 5555
#define INF 0x3f3f3f3f

using namespace std;

map<int, int>mp;
vector<int>G[maxn];
bool m[maxn][maxn];
int mindist[maxn];
bool inqueue[maxn];
int a, b;
int T;
int top = 0;
int V, E;
int S;

void init()
{
	top = 1;
	for (int i = 0; i < maxn; i++)
	{
		mindist[i] = INF;
		G[i].clear();
		inqueue[i] = false;
	}
	memset(m, false, sizeof(m));
}

void addedge()
{
	for (int i = 1; i < top; i++)
		for (int j = 1; j < i; j++)
			if (!m[i][j])
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
}

void Dijkstra()
{
	mindist[S] = 0;
	queue<int>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i];
		Q.push(G[S][i]);
		mindist[vex] = min(1, mindist[vex]);
		inqueue[vex] = 1;
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		inqueue[now] = 0;
		for (int i = 0; i < G[now].size(); i++)
		{
			int vex = G[now][i];
			int len = 1;
			if (len + mindist[now] < mindist[vex])
			{
				mindist[vex] = len + mindist[now];
				if (!inqueue[vex])
				{
					inqueue[vex] = 1;
					Q.push(G[now][i]);
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &V, &E);
		init();
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d", &a, &b);
			if (mp[a] == 0)
				mp[a] = top++;
			if (mp[b] == 0)
				mp[b] = top++;
			a = mp[a];
			b = mp[b];
			if (a > b)
				swap(a, b);
			m[b][a] = true;
		}
		addedge();
		scanf("%d", &S);
		if (mp[S] == 0)
			mp[S] = top++;
		S = mp[S];
		Dijkstra();
		long long ans = 0;
		for (int i = 1; i < top; i++)
		{
			if (i != S)
				ans += mindist[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
4 3
1 3
3 4
1 4
1
*/