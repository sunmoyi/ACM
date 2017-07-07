#include <cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>

#define LL long long
#define pii pair<int,int>
#define INF 0x7f7f7f7f
using namespace std;
const int N = 10000 + 100;

struct node
{
	int from;
	int to;
	int cap;
	int flow;
}edge[N];

int row[30];
int col[30];
int edge_cnt;
vector<int> vect[1000];

void add_node(int from, int to, int cap, int flow)
{
	edge[edge_cnt].from = from;
	edge[edge_cnt].to = to;
	edge[edge_cnt].cap = cap;
	edge[edge_cnt].flow = flow;
	vect[from].push_back(edge_cnt);
	edge_cnt++;
}

void build_graph(int n, int m)
{
	for (int i = 1; i <= n; i++) //加源点
	{
		add_node(0, i, row[i], 0);
		add_node(i, 0, 0, 0);
	}

	for (int i = 1; i <= m; i++) //汇点
	{
		add_node(n + i, n + m + 1, col[i], 0);
		add_node(n + m + 1, n + i, 0, 0);
	}

	for (int i = 1; i <= n; i++) //行-列
	{
		for (int j = 1; j <= m; j++)
		{
			add_node(i, n + j, 19, 0);
			add_node(n + j, i, 0, 0);
		}
	}
}

int flow[1000];
int path[1000];
int matrix[50][50];

int BFS(int s, int e)
{
	deque<int> que;
	que.push_back(s);
	flow[s] = INF;

	while (!que.empty())
	{
		int x = que.front();
		que.pop_front();
		for (int i = 0; i<vect[x].size(); i++)
		{
			node e = edge[vect[x][i]];
			if (!flow[e.to] && e.cap>e.flow)
			{
				path[e.to] = vect[x][i];
				flow[e.to] = min(flow[e.from], e.cap - e.flow);
				que.push_back(e.to);
			}
		}
		if (flow[e]) return flow[e];
	}
	return flow[e];
}

int cal(int s, int e)
{
	int ans = 0;
	while (true)
	{
		memset(flow, 0, sizeof(flow));
		memset(path, 0, sizeof(path));

		int tmp = BFS(s, e);
		if (tmp == 0)  return ans;

		ans += tmp;
		int ed = e;
		while (ed != s)
		{
			int t = path[ed];
			edge[t].flow += tmp;
			edge[t ^ 1].flow -= tmp;
			ed = edge[t].from;
		}

	}
	return 0;
}

void get_ans(int n, int m)
{
	for (int i = 0; i<edge_cnt; i += 2)
	{
		node e = edge[i];
		if (e.to<n)  continue;
		matrix[e.from][e.to - n] = e.flow;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", matrix[i][j] + 1);
		printf("\n");
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	int r, c, t, k, Case = 0;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i<1000; i++)    vect[i].clear();
		memset(matrix, 0, sizeof(matrix));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(edge, 0, sizeof(edge));
		edge_cnt = 0;


		scanf("%d%d", &r, &c);
		for (int i = 1; i <= r; i++)  //行
			scanf("%d", &row[i]);

		for (int i = 1; i <= c; i++)  //列
			scanf("%d", &col[i]);

		for (int i = r; i>0; i--)  //换成每行-c
			row[i] -= row[i - 1] + c;//细心点
		for (int i = c; i>0; i--)  //换成每列-r
			col[i] -= col[i - 1] + r;

		printf("Matrix %d\n", ++Case);
		build_graph(r, c);
		cal(0, r + c + 1);
		get_ans(r, c);
		if (t)   cout << endl;
	}
	return 0;
}