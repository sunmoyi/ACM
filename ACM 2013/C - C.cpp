#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define Min(x, y) (x < y? x: y) 
using namespace std;
const int INF = 0xfffffff;
const int maxn = 1005;

struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator < (const node &a, const node &b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn];
int n, start, endd;
int qidian[maxn], zhongdian[maxn];
int a, b, len, minn;
vector<node>G[maxn];

void init(void)
{
	for (int i = 0; i <= maxn; ++i)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		G[i].clear();
	}
}

void init2(void)
{
	for (int i = 1; i <= maxn; ++i)
	{
		inqueue[i] = false;
		mindist[i] = INF;
	}
}

void Dijkstra(int s)
{
	mindist[s] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); ++i)
	{
		int vex = G[s][i].v;
		Q.push(G[s][i]);
		inqueue[vex] = true;
		mindist[vex] = min(mindist[vex], G[s][i].len);
	}

	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = mindist[now.v] + len;
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
}

int main(void)
{
	while (scanf("%d %d %d", &n, &start, &endd) != EOF)
	{
		init();
		minn = INF;
		memset(qidian, 0, sizeof(qidian));
		memset(zhongdian, 0, sizeof(zhongdian));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		for (int i = 1; i <= start; i++)
			scanf("%d", &qidian[i]);
		for (int i = 1; i <= endd; i++)
			scanf("%d", &zhongdian[i]);
		if (start < endd)
		{
			for (int i = 1; i <= start; i++)
			{
				init2();
				Dijkstra(qidian[i]);
				for (int j = 1; j <= endd; j++)
				{
					if (mindist[j] < minn)
						minn = mindist[zhongdian[j]];
				}
			}
		}
		else
		{
			for (int i = 1; i <= endd; i++)
			{
				init2();
				Dijkstra(zhongdian[i]);
				for (int j = 1; j <= start; j++)
				{
					if (mindist[j] < minn)
						minn = mindist[j];
				}
			}
		}
		printf("%d\n", minn);
	}
	return 0;
}