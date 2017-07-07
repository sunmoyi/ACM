#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn (210)
#define maxm (210)
#define INF (0xfffffff)
using namespace std;

struct Edge {
	int to, next, cap, flow;
	Edge(int to = 0, int next = 0, int cap = 0, int flow = 0) :to(to), next(next), cap(cap), flow(flow) {}

}edge[maxm];

int tol;
int head[maxn];
int gap[maxn], dep[maxn], cur[maxn];

void init()
{
	tol = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w, int rw = 0)
{
	edge[tol].to = v;
	edge[tol].cap = w;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = rw;
	edge[tol].flow = 0;
	edge[tol].next = head[v]; 
	head[v] = tol++;
}

int Q[maxn];

void bfs(int start, int end)
{
	memset(dep, -1, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	gap[0] = 1;
	int front = 0, rear = 0;
	dep[end] = 0;
	Q[rear++] = end;
	while (front != rear)
	{
		int u = Q[front++];
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dep[v] != -1)
				continue;
			Q[rear++] = v;
			dep[v] = dep[u] + 1;
			gap[dep[v]]++;
		}
	}
}

int S[maxn];

int sap(int start, int end, int N)
{
	bfs(start, end);
	memcpy(cur, head, sizeof(head));
	int top = 0;
	int u = start;
	int ans = 0;
	while (dep[start] < N)
	{
		if (u == end)
		{
			int Min = INF;
			int inser;
			for (int i = 0; i < top; i++)
			{
				if (Min > edge[S[i]].cap - edge[S[i]].flow)
				{
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
				}
			}
			for (int i = 0; i < top; i++)
			{
				edge[S[i]].flow += Min;
				edge[S[i] ^ 1].flow -= Min;
			}
			ans += Min;
			top = inser;
			u = edge[S[top] ^ 1].to;
			continue;
		}
		bool flag = false;
		int v;
		for (int i = cur[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
			{
				flag = true;
				cur[u] = i;
				break;
			}
		}
		if (flag)
		{
			S[top++] = cur[u];
			u = v;
			continue;
		}
		int Min = N;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
			{
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		}
		gap[dep[u]]--;
		if (!gap[dep[u]])
			return ans;
		dep[u] = Min + 1;
		gap[dep[u]]++;
		if (u != start)
			u = edge[S[--top] ^ 1].to;
	}
	return ans;
}

int main(void)
{
	int m, n, a, b, c;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
		}
		printf("%d\n", sap(1, n, n));
	}
	return 0;
}
