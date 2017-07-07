#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define eps 1e-6

const int MAXN = 3005;
const int INF = 1 << 28;
int g[MAXN][MAXN], Mx[MAXN], My[MAXN], Nx, Ny;
int dx[MAXN], dy[MAXN], dis;
bool vst[MAXN];
vector<int>G[MAXN];

struct Node1
{
	int x, y, s;
}guests[MAXN];

struct Node2
{
	int x, y;
}um[MAXN];

void init(void)
{
	for (int i = 0; i < MAXN; i++)
		G[i].clear();
}
double distance(Node1 a, Node2 b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;

	return sqrt(x*x + y*y);
}
bool searchP()
{
	queue<int>Q;
	dis = INF;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for (int i = 0; i<Nx; i++)
		if (Mx[i] == -1)
		{
			Q.push(i);
			dx[i] = 0;
		}
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (dx[u]>dis)  break;
		int size = G[u].size();
		for (int i = 0; i < size; i++)
		{
			int v = G[u][i];
			if (dy[v] == -1)
			{
				dy[v] = dx[u] + 1;
				if (My[v] == -1)  dis = dy[v];
				else
				{
					dx[My[v]] = dy[v] + 1;
					Q.push(My[v]);
				}
			}
		}
	}
	return dis != INF;
}

bool DFS(int u)
{
	int size = G[u].size();
	for (int i = 0; i < size; i++)
	{
		int v = G[u][i];
		if (!vst[v] && dy[v] == dx[u] + 1)
		{
			vst[v] = 1;
			if (My[v] != -1 && dy[v] == dis) 
				continue;
			if (My[v] == -1 || DFS(My[v]))
			{
				My[v] = u;
				Mx[u] = v;
				return 1;
			}
		}
	}
	return 0;
}
int MaxMatch()
{
	int res = 0;
	memset(Mx, -1, sizeof(Mx));
	memset(My, -1, sizeof(My));
	while (searchP())
	{
		memset(vst, 0, sizeof(vst));
		for (int i = 0; i<Nx; i++)
			if (Mx[i] == -1 && DFS(i))  res++;
	}
	return res;
}

int main()
{
	int n, m, t, i, j;
	int T, iCase = 0;
	scanf_s("%d", &T);
	while (T--)
	{
		init();
		iCase++;
		scanf_s("%d", &t);
		scanf_s("%d", &m);
		for (i = 0; i<m; i++)
			scanf_s("%d%d%d", &guests[i].x, &guests[i].y, &guests[i].s);
		scanf_s("%d", &n);
		for (i = 0; i<n; i++)
			scanf_s("%d%d", &um[i].x, &um[i].y);
		Nx = m; Ny = n;
		memset(g, 0, sizeof(g));
		for (i = 0; i<m; i++)
		{
			for (j = 0; j<n; j++)
			{
				if (distance(guests[i], um[j]) / guests[i].s - t<eps)
				{
					G[i].push_back(j);
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n", iCase, MaxMatch());
	}
	return 0;
}