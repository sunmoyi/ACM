#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n, T, sum;
int val[100010];
pair<int, int> tree[100010];
int pre[100010];
struct node {
	int to;
	int len;
	node(int to = 0, int len = 0) :to(to), len(len){}
};
vector<node>G[100010];

pair<int, int> build(int s)
{
	pair<int, int> maxx;
	maxx.first = val[s], maxx.second = 0;
	for (int i = 0; i < G[s].size(); i++)
	{
		if (G[s][i].to == pre[s])
			continue;
		//maxx = max(maxx, build(G[s][i].to) + G[s][i].len);
		pair<int, int>a = build(G[s][i].to);
		if (maxx.first < a.first + G[s][i].len)
		{
			maxx.first = a.first + G[s][i].len;
			maxx.second = a.second + val[s] - G[s][i].len;
		}
		else if (maxx.first = a.first + G[s][i].len && maxx.second > a.second + val[s] - G[s][i].len;)
			maxx.second = a.second + val[s] - G[s][i].len;
	}
	return tree[s] = maxx;
}
//价值， 距离起始点距离
pair<int, int> query(int s, int front)
{
	pair<int, int> ans0 , ans1 , ans2 , ans3 , ans4;//0不动  1向下  2向上  3向下后向上 4 向上后向下
	ans0.first = val[s], ans0.second = 0;
	ans1.first = -1, ans1.second = 0;
	ans2.first = -1, ans2.second = 0;
	ans3.first = -1, ans3.second = 0;
	ans4.first = -1, ans4.second = 0;
	for (int i = 0; i < G[s].size(); i++)
	{
		if (G[s][i].to == front)
			continue;
		if (G[s][i].to == pre[s])
		{
			pair<int, int> a = query(pre[s], s);
			ans2.first = G[s][i].len + a.first;
			ans2.second = a.second + val[s] - G[s][i].len;
		}
		else
		{
			ans1.first
			//ans1 = max(ans1, tree[G[s][i].to] + G[s][i].len);
		}
	}
	ans3 = ans1 + 
	return max(ans1, ans2);
}

int main (void)
{
	int a, b, c;
	while(scanf("%d", &T) != EOF)
	{
		for (int ss = 1; ss <= T; ss++)
		{
			scanf("%d", &sum);
			for (int i = 1; i <= sum; i++)
				scanf("%d", &val[i]);
			for (int i = 1; i < sum; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				G[a].push_back(node(b, val[a] - c));
				G[b].push_back(node(a, val[b] - c));
				pre[b] = a;
			}

			build(1);
			printf("Case #%d:\n", ss);
			for(int i = 1; i <= sum; i++)
				printf("%d\n", query(i, 0));
		}
	}
	return 0;
}