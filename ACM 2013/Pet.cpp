#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int ans;
int T;
vector<int>G[100010];
int n, m;
int a, b;
int dis[100010];

void init(int x)
{
	for (int i = 0; i <= x; i++)
	{
		G[i].clear();
	}
}

void bfs()
{
	queue<int >Q;
	dis[0] = 0;
	Q.push(0);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < G[now].size(); i++)
		{
			dis[G[now][i]] = dis[now] + 1;
			if (dis[G[now][i]] > m)
				ans++;
			Q.push(G[now][i]);
		}
	}
}

int main(void)
{
	scanf("%d", &T);
	while (T--)	
	{
		
		scanf("%d %d", &n, &m);
		init(n);
		for (int i = 1; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
		}
		ans = 0;
		bfs();
		printf("%d\n", ans);
	}
	return 0;
}