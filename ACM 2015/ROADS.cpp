#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int d, L, t;
};
int K, N, R;
vector<vector<node>>citymap(110);
int minlen = 1 << 30;
int totalen;
int totalcost;
int visited[110];
int minl[110][10100];

void dfs(int s)
{
	if (s == N)
	{
		minlen = min(minlen, totalen);
		return;
	}
	for (int i = 0; i < citymap[s].size(); i++)
	{
		int d = citymap[s][i].d;
		if (!visited[d])
		{
			int cost = totalcost + citymap[s][i].t;
			if (cost > K)
				continue;
			if (totalen + citymap[s][i].L >= minlen || totalen + citymap[s][i].L >= minl[d][cost])
				continue;
			totalen += citymap[s][i].L;
			totalcost += citymap[s][i].t;
			minl[d][cost] = totalen;
			visited[d] = 1;
			dfs(d);
			visited[d] = 0;
			totalcost -= citymap[s][i].t;
			totalen -= citymap[s][i].L;
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &K, &N, &R);
	for (int i = 0; i < R; i++)
	{
		int s;
		node r;
		scanf("%d %d %d %d", &s, &r.d, &r.L, &r.t);
		if (s != r.d)
			citymap[s].push_back(r);
	}
	for(int i = 0; i < 110; i++)
		for (int j = 0; j < 10100; j++)
			minl[i][j] = 1 << 30;
	memset(visited, 0, sizeof(visited));
	totalen = 0;
	totalcost = 0;
	visited[1] = 1;
	minlen = 1 << 30;
	dfs(1);
	if (minlen < (1 << 30))
		printf("%d\n", minlen);
	else
		printf("-1");
	return 0;
}