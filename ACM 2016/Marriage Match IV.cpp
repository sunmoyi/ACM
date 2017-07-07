#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 2222
#define maxm 333333
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, cap;
	node(int v = 0, int cap = 0) :v(v), cap(cap){}
};
vector<node>vet[maxn];
struct Edge {
	int v, cap, next;
}edge[maxm];
int head[maxn], cur[maxn], pre[maxn], level[maxn], gap[maxn];
int NV, NE, n, m, vs, vt;

int dist[maxn];
bool vis[maxn];

void insert(int u, int v, int cap, int cc = 0)
{
	edge[NE].v = v; edge[NE].cap = cap;
	edge[NE].next = head[u]; head[u] = NE++;

	edge[NE].v = u; edge[NE].cap = cc;
	edge[NE].next = head[v]; head[v] = NE++;
}

void spfa()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[vs] = 0;
	queue<int>Q;
	Q.push(vs);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for (int i = 0; i < vet[u].size(); i++)
		{
			int v = vet[u][i].v;
			int w = vet[u][i].cap;
			if (dist[u] + w < dist[v])
			{
				dist[v] = w + dist[u];
				if (!vis[v])
				{
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

int SAP(int vs, int vt)
{
	memset(level, 0, sizeof(level));
	memset(pre, -1, sizeof(pre));
	memset(gap, 0, sizeof(gap));
	//cur[i]保存的是当前弧
	for (int i = 0; i <= NV; i++)
		cur[i] = head[i];
	int u = pre[vs] = vs;//源点的pre还是其本身
	int maxflow = 0, aug = -1;
	gap[0] = NV;
	while (level[vs]<NV) 
	{
	loop:
		for (int &i = cur[u]; i != -1; i = edge[i].next) 
		{
			int v = edge[i].v;//v是u的后继
							  //寻找可行弧
			if (edge[i].cap&&level[u] == level[v] + 1) 
			{
				//aug表示增广路的可改进量
				aug == -1 ? (aug = edge[i].cap) : (aug = min(aug, edge[i].cap));
				// if(aug>edge[i].cap)aug=edge[i].cap;
				pre[v] = u;
				u = v;
				//如果找到一条增广路
				if (v == vt) 
				{
					maxflow += aug;//更新最大流；
								   //路径回溯更新残留网络
					for (u = pre[v]; v != vs; v = u, u = pre[u]) 
					{
						//前向弧容量减少，反向弧容量增加
						edge[cur[u]].cap -= aug;
						edge[cur[u] ^ 1].cap += aug;
					}
					aug = -1;
					// aug=inf;
				}
				goto loop;
			}
		}
		int minlevel = NV;
		//寻找与当前点相连接的点中最小的距离标号（重标号）
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (edge[i].cap&&minlevel>level[v])
			{
				cur[u] = i;//保存弧
				minlevel = level[v];
			}
		}
		if ((--gap[level[u]]) == 0)
			break;//更新gap数组后如果出现断层，则直接退出。
		level[u] = minlevel + 1;//重标号
		gap[level[u]]++;//距离标号为level[u]的点的个数+1;
		u = pre[u];//转当前点的前驱节点继续寻找可行弧
	}
	return maxflow;
}

int main (void)
{
	int Case, u, v, d;
	scanf("%d", &Case);
	while (Case--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			vet[i].clear();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &u, &v, &d);
			if (u == v)
				continue;
			vet[u].push_back(node(v, d));
		}
		scanf("%d %d", &vs, &vt);
		spfa();
		NE = 0, NV = n;
		memset(head, -1, sizeof(head));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < vet[i].size(); j++)
			{
				if (dist[vet[i][j].v] == dist[i] + vet[i][j].cap)
					insert(i, vet[i][j].v, 1);
			}
		}
		printf("%d\n", SAP(vs, vt));
	}
	return 0;
}