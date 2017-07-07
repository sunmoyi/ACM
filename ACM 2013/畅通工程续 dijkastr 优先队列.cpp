#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1005;
const int maxm = 50005;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to, weight, next;
};

struct Node
{
	int vex, weight;
	bool operator<(const Node& x)const//堆优化使用
	{
		return weight > x.weight;//注意这里是大于号
	}
	Node(int _vex = 0, int _weight = 0) : vex(_vex), weight(_weight){}
};
Edge edge[maxn];
int mindist[maxn], head[maxn], tot;
bool intree[maxn];
priority_queue<Node> Heap;

void Init()

{
	tot = 0;
	for (int i = 0; i < maxn; ++i)
		mindist[i] = INF;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(intree, false, sizeof(intree));
	while (!Heap.empty())
		Heap.pop();
}

void addEdge(int u, int v, int w)
{
	edge[tot].to = v;
	edge[tot].weight = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int Dijkstra(int s, int e, int n)//堆优化
{
	int v1, v2;
	Node pre;

	mindist[s] = 0;
	Heap.push(Node(s, 0));
	while (!Heap.empty())
	{
		pre = Heap.top(), Heap.pop();
		v1 = pre.vex;
		if (intree[v1] == true)
			continue;
		intree[v1] = true;
		//printf("%d ",v1);
		for (int i = head[v1]; i != -1; i = edge[i].next)
		{
			v2 = edge[i].to;
			if (intree[v2] == false && mindist[v2] > edge[i].weight + pre.weight)
			{//注意这里
				mindist[v2] = edge[i].weight + pre.weight;
				Heap.push(Node(v2, mindist[v2]));
			}
		}
	}
	//printf("\n");
	return mindist[e];
}
int main()
{
	int n, m, u, v, w;
	int s, t;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		Init();//不要忘记初始化
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);//无向图
		}
		scanf("%d%d", &s, &t);
		int ans = Dijkstra(s, t, n);
		if (ans == INF)
			printf("%d\n", -1);
		else
			printf("%d\n", ans);
	}
	return 0;
}