#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
#define maxn 550

using namespace std;

int n, m, indegree[maxn], G[maxn][maxn], q[maxn];

void toposort()
{
	priority_queue<int, vector<int>, greater<int>>Q;
	int i = 0;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			Q.push(i);
	while (i < n)
	{
		int j = Q.top();
		Q.pop();
		q[i++] = j;
		for (int k = 1; k <= n; k++)
		{
			if (G[j][k])
			{
				indegree[k]--;
				if (indegree[k] == 0)
					Q.push(k);
			}
		}
	}
}

int main(void)
{
	int i, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(G, 0, sizeof(G));
		memset(indegree, 0, sizeof(indegree));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			if (G[a][b] == 0)
			{
				G[a][b] = 1;
				indegree[b]++;
			}
		}

		toposort();

		for (i = 0; i < n; i++)
		{
			if (i != n - 1)
				printf("%d ", q[i]);
			else
				printf("%d\n", q[i]);
		}
	}
	return 0;
}