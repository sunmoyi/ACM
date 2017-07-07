#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <queue>  
using namespace std;

const int MAXN = 210;
const int MAXM = 210 * 210;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v, f;
	int next;
}edge[MAXM];

int n, m;
int cnt;

int first[MAXN], level[MAXN];
int q[MAXN];

void init()
{
	cnt = 0;
	memset(first, -1, sizeof(first));
}

void read_graph(int u, int v, int f)
{
	edge[cnt].v = v, edge[cnt].f = f;
	edge[cnt].next = first[u], first[u] = cnt++;
	edge[cnt].v = u, edge[cnt].f = 0;  //增加一条反向弧，容量为0   
	edge[cnt].next = first[v], first[v] = cnt++;
}

int bfs(int s, int t) //构建层次网络   
{
	memset(level, 0, sizeof(level));
	level[s] = 1;
	int front = 0, rear = 1;
	q[front] = s;
	while (front < rear)
	{
		int x = q[front++];
		if (x == t) return 1;
		for (int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v, f = edge[e].f;
			if (!level[v] && f)
			{
				level[v] = level[x] + 1;
				q[rear++] = v;
			}
		}
	}
	return 0;
}

int dfs(int u, int maxf, int t)
{
	if (u == t) return maxf;
	int ret = 0;
	for (int e = first[u]; e != -1; e = edge[e].next)
	{
		int v = edge[e].v, f = edge[e].f;
		if (level[u] + 1 == level[v] && f)
		{
			int Min = min(maxf - ret, f);
			f = dfs(v, Min, t);
			edge[e].f -= f;
			edge[e^1].f += f;
			ret += f;
			if (ret == maxf) return ret;
		}
	}
	return ret;
}

int Dinic(int s, int t) //Dinic  
{
	int ans = 0;
	while (bfs(s, t)) ans += dfs(s, INF, t);
	return ans;
}