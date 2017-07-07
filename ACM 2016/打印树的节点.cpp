#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1000
using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len){}
};
vector<int>G[maxn];

void bfs()
{
	queue<node>Q;
	Q.push(node(1, 0));
	int temp = 0;
	while (!Q.empty())
	{
		node now = Q.front();
		if (temp == now.len)
			printf("%d ", now.v);
		else
		{
			printf("\n");
			printf("%d ", now.v);
			temp = now.len;
		}
		for (int i = 0; i < G[now.v].size(); i++)
		{
			Q.push(node(G[now.v][i], now.len + 1));
		}
	}
}