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
	//cur[i]������ǵ�ǰ��
	for (int i = 0; i <= NV; i++)
		cur[i] = head[i];
	int u = pre[vs] = vs;//Դ���pre�����䱾��
	int maxflow = 0, aug = -1;
	gap[0] = NV;
	while (level[vs]<NV) 
	{
	loop:
		for (int &i = cur[u]; i != -1; i = edge[i].next) 
		{
			int v = edge[i].v;//v��u�ĺ��
							  //Ѱ�ҿ��л�
			if (edge[i].cap&&level[u] == level[v] + 1) 
			{
				//aug��ʾ����·�ĿɸĽ���
				aug == -1 ? (aug = edge[i].cap) : (aug = min(aug, edge[i].cap));
				// if(aug>edge[i].cap)aug=edge[i].cap;
				pre[v] = u;
				u = v;
				//����ҵ�һ������·
				if (v == vt) 
				{
					maxflow += aug;//�����������
								   //·�����ݸ��²�������
					for (u = pre[v]; v != vs; v = u, u = pre[u]) 
					{
						//ǰ���������٣�������������
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
		//Ѱ���뵱ǰ�������ӵĵ�����С�ľ����ţ��ر�ţ�
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			if (edge[i].cap&&minlevel>level[v])
			{
				cur[u] = i;//���满
				minlevel = level[v];
			}
		}
		if ((--gap[level[u]]) == 0)
			break;//����gap�����������ֶϲ㣬��ֱ���˳���
		level[u] = minlevel + 1;//�ر��
		gap[level[u]]++;//������Ϊlevel[u]�ĵ�ĸ���+1;
		u = pre[u];//ת��ǰ���ǰ���ڵ����Ѱ�ҿ��л�
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