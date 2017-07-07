#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>G[100];
int V;
int color[100];

bool DFS(int v, int c)
{
	color[v] = c;
	for (int i = 1; i < G[v].size(); i++)
	{
		if (color[G[v][i]] == c)
			return false;
		if (color[G[v][i]] == 0 && !DFS(G[v][i, -c]))
			return false;
	}
	return true;
}

int main(void)
{
	/*图的读入部分省略*/
	for (int i = 0; i < V; i++)
	{
		if (color[i] == 0)
		{
			if (!DFS(i, 1))
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}