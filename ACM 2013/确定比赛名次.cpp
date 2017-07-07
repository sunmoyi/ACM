#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#include<functional>
#define maxn 505

using namespace std;

vector<int>G[maxn];
int indgree[maxn];
int V, E;
bool map[maxn][maxn];

void topu()
{
	priority_queue<int, vector<int>, greater<int>>Q;
	for (int i = 1; i <= V; i++)
	{
		if (indgree[i] == 0)
			Q.push(i);
	}
	while (!Q.empty())
	{
		int a = Q.top();
		if (V >= 2)
			printf("%d ", a);
		else
			printf("%d\n", a);
		V--;
		Q.pop();
		for (int i = 0; i < G[a].size(); i++)
		{
			indgree[G[a][i]]--;
			if (indgree[G[a][i]] == 0)
				Q.push(G[a][i]);
		}
	}
}

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &V, &E) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(indgree, 0, sizeof(indgree));
		for (int i = 1; i <= V; i++)
			G[i].clear();
		for (int i = 1; i <= E; i++)
		{
			scanf_s("%d %d", &a, &b);
			if (map[a][b] == 0)
			{
				G[a].push_back(b);
				indgree[b]++;
			}
		}
		topu();
	}
	return 0;
}