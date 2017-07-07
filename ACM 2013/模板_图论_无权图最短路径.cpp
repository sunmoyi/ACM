#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
const int maxn = 100005;
using namespace std;

struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator <(const node &a, const node&b)
	{
		return a.len < a.len;
	}
};

vector<node>G[maxn];
int V, E;
bool inqueue[maxn];
int mindist[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INT_MAX;
		G[i].clear();
	}
}

int unweighted(int s, int t)
{
	queue<int>Q;
	Q.push(s);
	inqueue[s] = true;
	mindist[s] = 0;
	while (!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		for (int i = 0; i < G[t].size(); i++)
		{
			int vex = G[t][i].v;
			if (mindist[vex] = INT_MAX && !inqueue[vex])
			{
				mindist[vex] = mindist[t] + 1;
				Q.push(vex);
				inqueue[vex] = true;
			}
		}
	}
	return mindist[t];
}

int main(void)
{
	int a, b, len; 
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init();
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
		}
		int S, T;
		int dis = unweighted(S, T);
		printf("%d\n", dis);
	}
	return 0;
}