#include <stdio.h>
#include <stdlib.h>
#define MVNum 100
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode
{
    char data;
    ArcNode *firstarc;
    int num;
}VNode,AdjList[MVNum];
typedef struct//邻接表
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
typedef struct stacknode
{
    int *base;
    int f;
    int t;
}Stack;
int main()
{
    ALGraph G;
    int i,k;
    printf("请输入总的顶点数和边数中间用空格分开：\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    getchar();
    printf("输入各个顶点值：\n");
    for(i=0;i<G.vexnum;i++)
    {
        scanf("%c",&G.vertices[i].data);
        getchar();
        G.vertices[i].num=0;
        G.vertices[i].firstarc=NULL;
    }
    for(k=0;k<G.arcnum;++k)
    {
        char t1,t2;
        int l,r;
        printf("请输入第%d条边的两个端点：\n",k+1);
        scanf("%c %c",&t1,&t2);
        getchar();
        for( i=0;i<G.vexnum;i++)
        {
            if(t1==G.vertices[i].data){
                l=i;
                G.vertices[l].num++;

            }
            if(t2==G.vertices[i].data) {
                r = i;
            }

        }
        ArcNode *p1=(ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex=r;
        p1->nextarc=G.vertices[l].firstarc; G.vertices[l].firstarc=p1;
    }
    int indegree[G.vexnum];
    int j;
    for(i=0;i<G.vexnum;i++)
        indegree[i]=0;
    ArcNode *p=NULL;
    for(i=0;i<G.vexnum;i++)
    {
        p=G.vertices[i].firstarc;

        for(j=0;j<G.vertices[i].num;j++)//用来控制移动次数
        {

            indegree[p->adjvex]++;
            p=p->nextarc;//指针不后移


        }
        //printf("aaa\n");
    }

    Stack s;
    s.base= (int*)malloc(G.vexnum*sizeof(int));
    s.f=s.t=0;
    for(i=0;i<G.vexnum;i++)
    {
        if(!indegree[i])
        {
            s.base[s.t++]=i;
        }
    }
    //入度为0者入栈
    int m=0;
    int temp;
    int topo[G.vexnum];//出栈元素也用其标号来表示
    while(s.t!=s.f)
    {
        temp=s.base[--s.t];//栈顶顶点出栈
        topo[m]=temp;
        m++;
        ArcNode *pp=G.vertices[temp].firstarc;//指向第一个邻接点

        for(j=0;j < G.vertices[temp].num;j++)
        {
            int k = pp->adjvex;

            --indegree[k];
            if(indegree[k]==0)
            {
                s.base[s.t++]=k;
                pp=pp->nextarc;
            }


        }
    }
    if(m<G.vexnum)
        printf("该图有回路\n");
    else
    {
        for(k=0;k<G.vexnum;k++)
            printf("%c \n",G.vertices[topo[k]].data);
    }
    return 0;
}