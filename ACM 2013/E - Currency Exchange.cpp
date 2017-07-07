#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int v;
	double rate;
	double occ;
	node(int v = 0, double rate = 0, double occ = 0) :v(v), rate(rate), occ(occ) {}
	bool friend operator <(const node&a, const node&b)
	{
		return a.rate < b.rate;
	}
};

bool inqueue[1005];
int cnt[1005];
vector<node>G[1005];
double maxx[1005];
int start;
double money;
int V, E;

void init(void)
{
	for (int i = 1; i <= 1004; i++)
	{
		inqueue[i] = false;
		cnt[i] = 0;
		G[i].clear();
		maxx[i] = 0;
	}
}

bool Dijkstra(void)
{
	cnt[start]++;
	queue<node>Q;
	for (int i = 0; i < G[start].size(); i++)
	{
		int vex = G[start][i].v;
		Q.push(G[start][i]);
		cnt[vex]++;
		maxx[vex] = max(maxx[vex], (maxx[start] - G[start][i].occ) * G[start][i].rate);
		inqueue[vex] = true;
	}
	while (!Q.empty())
	{
		node now = Q.front();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			double moneyy = (maxx[now.v] - G[now.v][i].occ) * G[now.v][i].rate;
			if (moneyy > maxx[vex])
			{
				maxx[vex] = moneyy;
				if (maxx[start] > money)
					return true;
				if (!inqueue[vex])
				{
					cnt[vex]++;
					//if (cnt[start] == V + 1)
						//return true;
					//if (cnt[vex] == V + 1)
						//continue;
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return false;
}

int main(void)
{
	int a, b;
	double rate1, occ1, rate2, occ2;
	while (scanf_s("%d %d %d %lf", &V, &E, &start, &money) != EOF)
	{
		init();
		maxx[start] = money;
		for (int i = 1; i <= E; i++)
		{
			scanf_s("%d %d", &a, &b);
			scanf_s("%lf %lf %lf %lf", &rate1, &occ1, &rate2, &occ2);
			G[a].push_back(node(b, rate1, occ1));
			G[b].push_back(node(a, rate2, occ2));
		}
		if (Dijkstra())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}