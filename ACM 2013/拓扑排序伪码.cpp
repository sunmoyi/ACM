/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

void Topsort(Graph G)
{
int counter;
vectex V, W;

for (counter = 0; counter < numvertex; counter++)
{
v = FindNewVertexOfIndegreeZero();
if (v == NotAVertex)
{
Error("Graph has a cycle");
break;
}
TopNum[v] = countor;
for each w adjacent to v
indegree[W]--;
}
}*/

/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<int>G[100];
int indgree[100];
int V, E, a, b;

void topsort(void)
{
int count = 0;
queue<int>Q;
for (int i = 1; i <= V; i++)
{
if (!indgree[i])
Q.push(i);
}

while (!Q.empty())
{
int t = Q.front();
Q.pop();
printf("%d", t);
count++;
for (int i = 0; i <= G[t].size(); i++)
{
if (--indgree[G[t][i]] == 0)
Q.push(G[t][i]);
}
}
if (count < V)
printf("ERROR\n");
else
printf("work over\n");
return;
}

int main(void)
{
memset(indgree, 0, sizeof(indgree));
scanf("%d", &E, &V);
for (int i = 1; i <= E; i++)
{
scanf("%d %d", &a, &b);
G[a].push_back(b);
indgree[b]++;
}
topsort();
return 0;
}*/

void TopSort2(Graph& g)
{
	queue<VertexNode> q;
	for (int i = 0; i < g.vertexNum; i++)
	{
		if (g.VertexNode[i].indegree == 0)
			q.push(g.VertexNode[i]);
	}
	int count = 0;
	cout << "The topsort is:" << endl;
	while (!q.empty())
	{
		VertexNode v = q.front();
		q.pop();
		cout << v.data << " ";
		count++;
		adjVertexNode* padjv = v.list;
		while (padjv != NULL)
		{
			if (--(g.VertexNode[padjv->adjVertexPosition].indegree) == 0)
				q.push(g.VertexNode[padjv->adjVertexPosition]);
			padjv = padjv->next;
		}
	}
	if (count != g.vertexNum)
		cout << "The graph has cycle, can not do topsort" << endl;
}