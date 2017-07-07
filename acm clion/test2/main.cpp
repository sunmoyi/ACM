#include<iostream>
#define MVNum 100//表示最大顶点数
using namespace std;
typedef struct ArcNode//边结点
{
    int adjvex;//该边所指向顶点的位置
    struct ArcNode *nextarc;//指向下一条边的指针
}ArcNode;
typedef struct VNode//顶点信息
{
    int data;
    ArcNode *firstarc;//指向第一条依附于该顶点的边的指针
}VNode, AdjList[MVNum];
typedef struct//邻接表
{
    AdjList vertices;
    int vexnum, arcnum;//图的当前顶点数和边数
}DAGraph;
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;
void InitStack(LinkStack &S)
{
    S = NULL;
}
int Pop(LinkStack &S,int &e)
{
    StackNode *p;
    e = S->data;
    p = S;
    S = S->next;
    delete p;
    return e;
}

void Push(LinkStack &S, int e)
{
    cout << "b" << endl;
    StackNode *p;
    p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
}

int StackEmpty(LinkStack S)
{
    if (S == NULL)
        return 1;
    else
        return 0;
}

int Get_Position(DAGraph G, int ch)
{
    int i;
    for (i = 0; i<G.vexnum; i++)
        if (G.vertices[i].data == ch)
            return i;
    return -1;
}

DAGraph *Create_Graph()
{
    DAGraph *G1;
    int i, s, d, a, b;
    ArcNode *p1;
    G1 = new DAGraph;
    cout << "请输入总顶点数：" << endl;
    cin >> G1->vexnum;
    cout << "请输入总边数：" << endl;
    cin >> G1->arcnum;
    cout << "输入顶点：" << endl;
    for (i = 0; i < G1->vexnum; ++i)
    {
        cin >> G1->vertices[i].data;
        G1->vertices[i].firstarc = NULL;
    }
    for (i = 0; i < G1->arcnum; ++i)
    {
        cout << "输入一条边的起点和终点：" << endl;
        cin >> s >> d;
        a = Get_Position(*G1, s);
        b = Get_Position(*G1, d);
        p1 = new ArcNode;
        p1->adjvex = b;
        p1->nextarc = G1->vertices[a].firstarc;
        G1->vertices[a].firstarc = p1;
        cout << "e" << endl;//tiaoshi
    }
    return G1;
}

void TopologicalSort(DAGraph G)
{
    int i, m, k;
    int topo[100];
    int indegree[100];
    ArcNode *p,*q;
    LinkStack S;
    InitStack(S);
    for (i = 0; i < G.vexnum; i++)//统计每一个结点的入度
    {
        q = G.vertices[i].firstarc;
        while (q != NULL)
        {
            indegree[q->adjvex]++;
            q = q->nextarc;
        }
        //！！！！！cout << indegree[q->adjvex] << endl;！！！！
    }
    for (i = 0; i < G.vexnum; ++i)
        if (!indegree[i])
            Push(S, i);
    m = 0;
    while (StackEmpty(S) == 0)
    {
        Pop(S, i);
        topo[m] = i;
        ++m;
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            //cout << "c" << endl;
            k = p->adjvex;
            --indegree[k];
            if (indegree[k] == 0)
                Push(S, k);
            p = p->nextarc;
        }
    }
    if (m < G.vexnum)
        cout << "该有向图有回路" << endl;
    else
    {
        cout << "拓扑排序为：" << endl;
        for (i = 0; i < m; i++)
        {
            cout << topo[i] << endl;
        }
    }
}
int main()
{
    DAGraph *G;
    G=Create_Graph();
    TopologicalSort(*G);
    return 0;
}