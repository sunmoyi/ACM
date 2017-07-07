#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int max_v = 1005;
const int INF = 0xfffffff;

struct edge{
	int to;
	int cap;
	int rev;
	edge(int to = 0, int cap = 0, int rev = 0) : to(to), cap(cap), rev(rev){}
};

vector<edge>G[max_v];
bool used[max_v];	
				 /*起点	   终点	   容量*/
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size()));
}
/*运送深搜寻找增广路 v当前顶点 t目标顶点 f当前的路径中的最小顶标的值*/
int dfs(int v, int t, int f)
{/*如果当前点就是重点 返回最小顶标值*/
	if (v == t)
		return f;
	used[v] == true;/*标记使用*/
	for (int i = 0; i < G[v].size(); i++)
	{
		edge &e = G[v][i];/*如果当前路没有使用过 并且剩余流量不为0*/
		if (!used[e.to] && e.cap > 0)
		{   /*深搜 下一个顶点 终点  当前所有边的最小流量*/
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{/*这条边的流量减少d  反项流量增加d*/
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	while (true)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
			return flow;
		else
			flow += f;
	}
}