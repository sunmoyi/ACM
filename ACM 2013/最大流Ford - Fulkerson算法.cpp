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
				 /*���	   �յ�	   ����*/
void add_edge(int from, int to, int cap)
{
	G[from].push_back(edge(to, cap, G[to].size()));
	G[to].push_back(edge(from, 0, G[from].size()));
}
/*��������Ѱ������· v��ǰ���� tĿ�궥�� f��ǰ��·���е���С�����ֵ*/
int dfs(int v, int t, int f)
{/*�����ǰ������ص� ������С����ֵ*/
	if (v == t)
		return f;
	used[v] == true;/*���ʹ��*/
	for (int i = 0; i < G[v].size(); i++)
	{
		edge &e = G[v][i];/*�����ǰ·û��ʹ�ù� ����ʣ��������Ϊ0*/
		if (!used[e.to] && e.cap > 0)
		{   /*���� ��һ������ �յ�  ��ǰ���бߵ���С����*/
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{/*�����ߵ���������d  ������������d*/
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