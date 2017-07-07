#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 110

using namespace std;

int V, E;
int indgee[maxn];
vector<int>G[maxn];

bool topu()
{
	queue<int>Q;
	int t = 0;
	for (int i = 0; i < V; i++)
	{
		if (indgee[i] == 0)
			Q.push(i);
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		t++;
		for (int i = 0; i < G[now].size(); i++)
		{
			if (--indgee[G[now][i]] == 0)
				Q.push(G[now][i]);
		}
	}
	if (t == V)
		return true;
	else
		return false;
}

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &V, &E) != EOF && (V + E))
	{
		memset(indgee, 0, sizeof(indgee));
		for (int i = 0; i <= V; i++)
			G[i].clear();
		for (int i = 1; i <= E; i++)
		{
			scanf_s("%d %d", &a, &b);
			G[b].push_back(a);
			indgee[a]++;
		}
		if (topu())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}