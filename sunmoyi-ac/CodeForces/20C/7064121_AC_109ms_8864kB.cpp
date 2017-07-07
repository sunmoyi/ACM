#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
const int INF = 0xfffffff;
const int maxn = 100010;

using namespace std;

struct node {
	long long len;
	int v;
	node(int v = 0, int len = 0) :v(v), len(len) {}
	friend bool operator <(const node &a, const node&b)
	{
		return a.len < b.len;
	}
};

bool inqueue[maxn];
long long minDist[maxn];
int n, m;
int back[maxn];
vector<node>G[maxn];

long long Dijktra(int S, int T)
{
	minDist[S] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		Q.push(G[S][i]);
		minDist[vex] = min(G[S][i].len, minDist[vex]);
		back[vex] = S;
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
			long long len = G[now.v][i].len;
			if (len + minDist[now.v] < minDist[vex])
			{
				minDist[vex] = len + minDist[now.v]; 
				back[vex] = now.v;
				if (!inqueue[vex])
				{ 
					inqueue[vex] = 1;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return minDist[T];
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			minDist[i] = 999999999999999;
		int a, b, len;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		long long ans = Dijktra(1, n);
		if (ans == 999999999999999)
			printf("-1\n");
		else
		{
			stack<int>S;
			for (int i = n; i != 1; i = back[i])
				S.push(i);
			S.push(1);
			while (!S.empty())
			{
				printf("%d ", S.top());
				S.pop();
			}
			printf("\n");
		}
	}
	return 0;
}
