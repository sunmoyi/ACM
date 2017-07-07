#include<iostream> 
#include<cstdlib> 
using namespace std;
#define MAX_VERTEX_NUM 20   //最大顶点数
#define MaxSize 100 
bool visited[MAX_VERTEX_NUM];
enum GraphKind
{
	AG, AN, DG, DN
};//图的种类，无向图，无向网络，有向图，有向网络
struct ArcNode
{
	int adjvex;
	ArcNode * nextarc;
};
struct VNode
{
	int data;
	ArcNode * firstarc;
};
struct Graph
{
	VNode vertex[MAX_VERTEX_NUM];
	int vexnum, arcnum;  //顶点数，弧数
	GraphKind kind;  //图的类型
};
struct SeqQueue
{
	int *base;
	int front, rear;
};
SeqQueue InitQueue()
{  //循环队列初始化
	SeqQueue Q;
	Q.base = new int;
	Q.front = 0;
	Q.rear = 0;
	return Q;
}
void DeQueue(SeqQueue &Q, int &u)
{  //出队操作
	u = *(Q.base + Q.front);
	Q.front = (Q.front + 1) % MaxSize;
}
int QueueFull(SeqQueue Q)
{  //判断循环队列是否满
	return (Q.front == (Q.rear + 1) % MaxSize) ? 1 : 0;
}
void EnQueue(SeqQueue &Q, int x)
{  //入队操作
	if (QueueFull(Q))
	{
		cout << "队满，入队操作失败！" << endl;
		exit(0);
	}
	*(Q.base + Q.rear) = x;
	Q.rear = (Q.rear + 1) % MaxSize;
}
void CreateDG(Graph & G, int n, int e)
{  //初始化邻接表头结点
	int i, j;
	for (i = 0; i < n; ++i)
	{
		G.vertex[i].data = i;
		G.vertex[i].firstarc = NULL;
	}
	for (i = 0; i < e; ++i)
	{
		cin >> i >> j;  //输入边的信息
		ArcNode* s;
		s = new ArcNode;
		s->adjvex = j;
		s->nextarc = G.vertex[i].firstarc;
		G.vertex[i].firstarc = s;
	}
}
void Visit(Graph G, int u)
{
	cout << G.vertex[u].data << " ";
}
int FirstAdjVex(Graph G, int v)
{
	if (G.vertex[v].firstarc)
		return G.vertex[v].firstarc->adjvex;
	else
		return -1;
}
int NextAdjVex(Graph G, int v, int w)
{
	ArcNode* p = G.vertex[v].firstarc;
	while (p->adjvex != w)
		p = p->nextarc;
	if (p->nextarc)
		return p->nextarc->adjvex;
	else
		return -1;
}
void DFSGrahp(Graph G, int v)
{
	int w;
	visited[v] = true; Visit(G, v);  //访问顶点V，对从未访问过的邻接点w递归调用DFS
	for (w = FirstAdjVex(G, v);
		w != 0;
		w = NextAdjVex(G, v, w));
	if (!visited[w]) 
		DFSGrahp(G, w);
}
void DFSTraverse(Graph G)
{  //对图G做深度优先搜索
	int v;
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = false;  //初始化访问标志数组visited
	for (v = 0; v < G.vexnum; ++v)
		if (!visited[v]) DFSGrahp(G, v);  //对尚未访问的顶点v调用DFS
}
void BFSGrahp(Graph G)
{  //图的广度优先搜索
	SeqQueue Q;
	Q = InitQueue();
	int u;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[G, v])
		{
			EnQueue(Q, v);  //v入队列
			while (!((Q.front == Q.rear) ? 1 : 0))
			{
				DeQueue(Q, u);  //对首元素出队，赋给u
				visited[u] = true;
				Visit(G, u);
				for (int w = FirstAdjVex(G, u);
					w != 0;
					w = NextAdjVex(G, u, w))  //u的未访问过的邻接点w入队列
					if (!visited[w])
						EnQueue(Q, w);
			}
		}
}
int main()
{
	Graph p;
	int n, e;
	cout << "输入图的顶点及边数："<<endl;
	cin >> n >> e;
	cout << "创建图："<<endl; 
	CreateDG(p, n, e);
	cout << "图的优先深度结果为："<<endl;
	DFSTraverse(p);
	cout << "图的广度优先结果为："<<endl; 
    BFSGrahp(p);
	printf("结果如上所示!\n"); 
	return 0;
}