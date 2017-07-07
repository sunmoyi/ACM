#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define maxn 330

using namespace std;

int G[maxn][maxn];
int pre[maxn];
bool visited[maxn];
int n, m;

unsigned int Augment()
{
	int v, i;
	deque<int>Q;
	memset(pre, 0, sizeof(pre));
	memset(visited, 0, sizeof(visited));
	pre[1] = 0;
	visited[1] = 1;
	Q.push_back(1);
	bool bfindpath = false;
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop_front();
		for (i = 1; i <= m; i++)
		{
			if (G[v][i] > 0 && visited[i] == 0)
			{
				pre[i] = v;
				visited[i] = 1;
				if (i == m)
				{
					bfindpath = true;
					Q.clear();
					break;
				}
				else
					Q.push_back(i);
			}
		}
	}
	if (!bfindpath)
		return 0;
	int minflow = 99999999;
	v = m;
	while (pre[v])
	{
		minflow = min(minflow, G[pre[v]][v]);
		v = pre[v];
	}
	v = m;
	while (pre[v])
	{
		G[pre[v]][v] -= minflow;
		G[v][pre[v]] += minflow;
		v = pre[v];
	}
	return minflow;
}

int main(void)
{
	while (cin >> n >> m)
	{
		int i, j, k;
		int s, e, c;
		memset(G, 0, sizeof(G));
		for (i = 0; i < n; i++)
		{
			cin >> s >> e >> c;
			G[s][e] += c;
		}
		unsigned int Maxflow = 0;
		unsigned int aug;
		while (aug = Augment())
			Maxflow += aug;
		cout << Maxflow << endl;
	}
	return 0;
}