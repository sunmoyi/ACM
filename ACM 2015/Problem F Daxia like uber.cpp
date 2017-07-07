#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) : v(v), len(len) {}
	friend bool operator < (const node &a, const node &b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindistS[maxn];
int mindistx1[maxn];
int mindistx2[maxn];
int mindisty1[maxn];
int mindisty2[maxn];
int n, m;
vector<node>G[maxn];

void init1()
{
	for (int i = 0; i <= n + 1; i++)
	{
		G[i].clear();
	}
}

void init2(int *mindist)
{
	for (int i = 0; i <= n + 1; i++)
	{
		mindist[i] = INF;
		inqueue[i] = false;
	}
}

void Dijkstra(int S, int *mindist)
{
	mindist[S] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		Q.push(G[S][i]);
		mindist[vex] = min(G[S][i].len, mindist[vex]);
		inqueue[vex] = 1;
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = 0;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = len + mindist[now.v]; //先更新最短路径
				if (!inqueue[vex])
				{ //如果没在队列，再加入队列
					inqueue[vex] = 1;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
}

int main (void)
{
	int a, b, c, S, x1, x2, y1, y2;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init1();
		scanf("%d %d %d %d %d", &S, &x1, &y1, &x2, &y2);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(node(b, c));
			//G[b].push_back(node(a, c));
		}
		init2(mindistS);
		Dijkstra(S, mindistS);
		init2(mindistx1);
		Dijkstra(x1, mindistx1);
		init2(mindistx2);
		Dijkstra(x2, mindistx2);
		init2(mindisty1);
		Dijkstra(y1, mindisty1);
		init2(mindisty2);
		Dijkstra(y2, mindisty2);
		int ans1 = mindistS[x1] + mindistx1[y1] + mindisty1[x2] + mindistx2[y2];
		//printf("%d\n", ans1);
		int ans2 = mindistS[x1] + mindistx1[x2] + mindistx2[y1] + mindisty1[y2];
		//printf("%d\n", ans2);
		int ans3 = mindistS[x1] + mindistx1[x2] + mindistx2[y2] + mindisty2[y1];
		//printf("%d\n", ans3);
		int ans4 = mindistS[x2] + mindistx2[y2] + mindisty2[x1] + mindistx1[y1];
		//printf("%d\n", ans4);
		int ans5 = mindistS[x2] + mindistx2[x1] + mindistx1[y2] + mindisty2[y1];
		//printf("%d\n", ans5);
		int ans6 = mindistS[x2] + mindistx2[x1] + mindistx1[y1] + mindisty1[y2];
		//printf("%d\n", ans6);
		ans1 = min(ans1, ans2);
		ans1 = min(ans1, ans3);
		ans1 = min(ans1, ans4);
		ans1 = min(ans1, ans5);
		printf("%d\n", ans1);
	}
}