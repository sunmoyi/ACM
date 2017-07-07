#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#define maxn 1000
#define INF 0xfffffff

using namespace std;

int n, m;
double l, u;
struct node {
	int to;
	double val;
	node(int to, double val) :to(to), val(val) {}
};
bool vis[maxn];
double mindist[maxn];
int cnt[maxn];
vector<node>G[maxn];

bool spfa(int n)
{
	for (int i = 0; i <= n; i++)
		vis[i] = 0, mindist[i] = INF, cnt[i] = 0;
	queue<int>Q;
	Q.push(1);
	cnt[1] = 1;
	vis[1] = true;
	mindist[1] = 0;
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		vis[cur] = false;
		for (int i = 0; i < G[cur].size(); i++)
		{
			int next = G[cur][i].to;
			double val = G[cur][i].val;
			if (mindist[cur] + val < mindist[next])
			{
				mindist[next] = mindist[cur] + val;
				if (!vis[next])
				{
					Q.push(next);
					cnt[next]++;
					vis[next] = true;
					if (cnt[next] > sqrt(n * 1.0))
						return false;
				}
			}
		}
	}
	return true;
}

int main(void)
{
	while (scanf_s("%d %d %lf %lf", &n, &m, &l, &u) != EOF)
	{
		for (int i = 0; i <= n + m; i++)
			G[i].clear();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int x;
				scanf_s("%d", &x);
				G[i].push_back(node(j + n, -log(l / x)));
				G[j + n].push_back(node(i, log(u / x)));
			}
		}
		if (spfa(m + n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}