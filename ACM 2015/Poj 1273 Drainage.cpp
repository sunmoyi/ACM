#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<deque>
#define INF 9999999;
#define maxn 330

using namespace std;

int G[330][maxn];
bool visited[maxn];
int Layer[maxn], n, m;

bool countlayer()
{
	int layer = 0;
	deque<int>Q;
	memset(Layer, 0xff, sizeof(Layer));
	Layer[1] = 0;
	Q.push_back(1);
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop_front();
		for (int j = 1; j <= m; j++)
		{
			if (G[v][j] > 0 && Layer[j] == -1)
			{
				Layer[j] = Layer[v] + 1;
				if (j == m)
					return true;
				else
					Q.push_back(j);
			}
		}
	}
	return false;
}

int Dinic()
{
	int i, s;
	int nmaxflow = 0;
	deque<int>Q;
	while (countlayer())
	{
		Q.push_back(1);
		memset(visited, 0, sizeof(visited));
		visited[1] = 1;
		while (!Q.empty())
		{
			int nd = Q.back();
			if (nd == m)
			{
				int nminc = INF;
				int nminc_vs;
				for (int i = 1; i < Q.size(); i++)
				{
					int vs = Q[i - 1];
					int ve = Q[i];

					if (G[vs][ve] > 0)
					{
						if (nminc > G[vs][ve])
						{
							nminc = G[vs][ve];
							nminc_vs = vs;
						}
					}
				}
				nmaxflow += nminc;
				for (i = 1; i < Q.size(); i++)
				{
					int vs = Q[i - 1];
					int ve = Q[i];
					G[vs][ve] -= nminc; //修改边容量
					G[ve][vs] += nminc; //添加反向边
				}
				//退栈到 nMinC_vs成为栈顶，以便继续dfs
				while (!Q.empty() && Q.back() != nminc_vs) 
				{
					visited[Q.back()] = 0; //没有这个应该也对
					Q.pop_back();
				}
			}
			else 
			{ //nd不是汇点
				for (i = 1; i <= m; i++)
				{
					if (G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 && !visited[i])
					{
						//只往下一层的没有走过的节点走
						visited[i] = 1;
						Q.push_back(i);
						break;
					}
				}
				if (i > m) //找不到下一个点 
				Q.pop_back(); //回溯
			}
		}
	}
	return nmaxflow;
}

int main(void)
{
	while (cin >> n >> m)
	{
		int i, j, k;
		int s, e, c;
		memset(G, 0, sizeof(G));
		for (i = 1; i <= n; i++)
		{
			cin >> s >> e >> c;
			G[s][e] += c;
		}
		cout << Dinic() << endl;
	}
	return 0;
}