#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 60;
const int INF = (1 << 29);

int in[maxn][12], cap[maxn][maxn], n, flow[maxn][maxn];
int G[330][maxn];
bool visited[maxn];
int Layer[maxn],m;

bool countlayer()
{
	int layer = 0;
	deque<int>Q;
	memset(Layer, 0xff, sizeof(Layer));
	Layer[0] = 0;
	Q.push_back(0);
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
		Q.push_back(0);
		memset(visited, 0, sizeof(visited));
		visited[0] = 1;
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
					flow[vs][ve] += nminc;
					G[ve][vs] += nminc; //添加反向边
					flow[ve][vs] -= nminc;
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


int main() 
{
	int p;

	while (scanf("%d%d", &p, &n) == 2) 
	{

		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		memset(G, 0, sizeof(G));

		for (int i = 0; i<2 * p + 1; i++)
		{        //初始化超源，超汇
			in[0][i] = 0;
			in[n + 1][i] = 1;
		}

		for (int i = 1; i <= n; i++) 
		{           //输入数据
			for (int j = 0; j<2 * p + 1; j++) 
			{
				scanf("%d", &in[i][j]);
			}
		}

		n += 2;                               //点数+2
		m = n - 1;
		for (int i = 0; i<n; i++)
		{            //将可以连通的点，记录,算出每条边的容量
			for (int j = 0; j<n; j++) 
			{
				if (i == j) continue;

				bool flag = true;
				for (int k = 1; k <= p; k++) 
				{
					if (!((in[j][k] == 2) || (in[i][k + p] == in[j][k]))) 
					{
						flag = false;
					}
				}
				if (flag && i == 0) 
					G[i][j] = in[j][0];
				else if (flag && j == n - 1)
					G[i][j] = in[i][0];
				else if (flag) 
					G[i][j] += min(in[i][0], in[j][0]);
			}
		}

		printf("%d ", Dinic());          //增广路算法

		int cnt = 0;                        //计数
		for (int i = 1; i<n - 1; i++)
		{
			for (int j = 1; j<n - 1; j++) 
			{
				if (flow[i][j] > 0) cnt++;
			}
		}
		printf("%d\n", cnt);

		for (int i = 1; i<n - 1; i++) 
		{          //输出
			for (int j = 1; j<n - 1; j++) 
			{
				if (flow[i][j] > 0)
					printf("%d %d %d\n", i, j, flow[i][j]);
			}
		}
	}
	return 0;
}