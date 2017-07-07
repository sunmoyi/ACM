#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct node{
	int len;
	int v;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};

vector<node>G[1000];
int V, E;
int color[1000];

bool DFS(int V, int c)
{
	color[V] = c;
	for (int i = 0; i < G[V].size(); i++)
	{
		if (color[G[V][i].v] == c)
			return false;
		if (color[G[V][i].v] == 0 && !DFS(G[V][i].v, -c))
			return false;
	}
	return true;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d", &V, &E) != EOF)
	{	
		memset(color, 0, sizeof(color));
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
		}
		bool flag = true;
		for (int i = 0; i < V; i++)
		{
			if (color[i] == 0)
			{
				if (!DFS(i, 1))
				{
					flag = false;
					printf("NO\n");
					break;
				}
			}

		}
		if (flag)
		printf("YES\n");
	}
	return 0;
}