#include<iostream> 
#include<cstdlib> 
using namespace std;
#define MAX_VERTEX_NUM 20   //��󶥵���
#define MaxSize 100 
bool visited[MAX_VERTEX_NUM];
enum GraphKind
{
	AG, AN, DG, DN
};//ͼ�����࣬����ͼ���������磬����ͼ����������
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
	int vexnum, arcnum;  //������������
	GraphKind kind;  //ͼ������
};
struct SeqQueue
{
	int *base;
	int front, rear;
};
SeqQueue InitQueue()
{  //ѭ�����г�ʼ��
	SeqQueue Q;
	Q.base = new int;
	Q.front = 0;
	Q.rear = 0;
	return Q;
}
void DeQueue(SeqQueue &Q, int &u)
{  //���Ӳ���
	u = *(Q.base + Q.front);
	Q.front = (Q.front + 1) % MaxSize;
}
int QueueFull(SeqQueue Q)
{  //�ж�ѭ�������Ƿ���
	return (Q.front == (Q.rear + 1) % MaxSize) ? 1 : 0;
}
void EnQueue(SeqQueue &Q, int x)
{  //��Ӳ���
	if (QueueFull(Q))
	{
		cout << "��������Ӳ���ʧ�ܣ�" << endl;
		exit(0);
	}
	*(Q.base + Q.rear) = x;
	Q.rear = (Q.rear + 1) % MaxSize;
}
void CreateDG(Graph & G, int n, int e)
{  //��ʼ���ڽӱ�ͷ���
	int i, j;
	for (i = 0; i < n; ++i)
	{
		G.vertex[i].data = i;
		G.vertex[i].firstarc = NULL;
	}
	for (i = 0; i < e; ++i)
	{
		cin >> i >> j;  //����ߵ���Ϣ
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
	visited[v] = true; Visit(G, v);  //���ʶ���V���Դ�δ���ʹ����ڽӵ�w�ݹ����DFS
	for (w = FirstAdjVex(G, v);
		w != 0;
		w = NextAdjVex(G, v, w));
	if (!visited[w]) 
		DFSGrahp(G, w);
}
void DFSTraverse(Graph G)
{  //��ͼG�������������
	int v;
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = false;  //��ʼ�����ʱ�־����visited
	for (v = 0; v < G.vexnum; ++v)
		if (!visited[v]) DFSGrahp(G, v);  //����δ���ʵĶ���v����DFS
}
void BFSGrahp(Graph G)
{  //ͼ�Ĺ����������
	SeqQueue Q;
	Q = InitQueue();
	int u;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[G, v])
		{
			EnQueue(Q, v);  //v�����
			while (!((Q.front == Q.rear) ? 1 : 0))
			{
				DeQueue(Q, u);  //����Ԫ�س��ӣ�����u
				visited[u] = true;
				Visit(G, u);
				for (int w = FirstAdjVex(G, u);
					w != 0;
					w = NextAdjVex(G, u, w))  //u��δ���ʹ����ڽӵ�w�����
					if (!visited[w])
						EnQueue(Q, w);
			}
		}
}
int main()
{
	Graph p;
	int n, e;
	cout << "����ͼ�Ķ��㼰������"<<endl;
	cin >> n >> e;
	cout << "����ͼ��"<<endl; 
	CreateDG(p, n, e);
	cout << "ͼ��������Ƚ��Ϊ��"<<endl;
	DFSTraverse(p);
	cout << "ͼ�Ĺ�����Ƚ��Ϊ��"<<endl; 
    BFSGrahp(p);
	printf("���������ʾ!\n"); 
	return 0;
}