#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct node{
	int len;
	int v;
	node(int v = 0, int len = 0) : v(v), len(len) {}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};

vector<node>G[100];
int indgree[100];
int V, E;

bool topsort(void)
{
	int count = 0;
	queue<int>Q;
	for (int i = 0; i <= V; i++)
	{
		if (indgree[i] == 0)
			Q.push(i);
	}
	while (!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		count++;
		for (int i = 0; i <= G[t].size(); i++)
		{
			if (--indgree[G[t][i].v] == 0)
				Q.push(G[t][i].v);
		}
	}
	if (count < V)
		return false;
	else
		return true;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		memset(indgree, 0, sizeof(indgree));
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			indgree[a]++;
		}
		bool flag = topsort();
		if (flag)
			printf("work down\n");
		else
			printf("Wrong");
	}
	return 0;
}