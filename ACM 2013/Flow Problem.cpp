#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 100010;//���������ֵ
const int MAXM = 400010;//���������ֵ
const int INF = 0x3f3f3f3f;
struct Edge {
	int to, next, cap, flow;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];

void init()
{
	tol = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w, int rw)
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

int Q[MAXN];

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

int S[MAXN];

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
				if (Min > edge[S[i]].cap - edge[S[i]].flow)
				{
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
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

int kk, V, E;
int main(void)
{
	int a, b, c;
	while (scanf_s("%d", &kk) != EOF)
	{
		for (int i = 1; i <= kk; i++)
		{
			init();
			scanf_s("%d %d", &V, &E);
			for (int j = 1; j <= E; j++)
			{
				scanf_s("%d %d %d", &a, &b, &c);
				addedge(a, b, c, 0);
			}
			printf("Case %d: %d\n", i, sap(1, V, V));
		}
	}
}