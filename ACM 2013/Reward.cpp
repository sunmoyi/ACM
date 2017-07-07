#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 10005

using namespace std;

vector<int>G[maxn];
int money[maxn];
int indgree[maxn];
int V, E;

int topu()
{
	int sum = 0;
	int t = 0;
	queue<int>Q;
	for (int i = 1; i <= V; i++)
	{
		if (indgree[i] == 0)
		{
			money[i] = 888;
			Q.push(i);
		}
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		t++;
		sum += money[now];
		for (int i = 0; i < G[now].size(); i++)
		{
			if (--indgree[G[now][i]] == 0)
			{
				Q.push(G[now][i]);
				money[G[now][i]] = money[now] + 1;
			}
		}
	}
	if (t == V)
		return sum;
	else
		return -1;
}

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &V, &E) != EOF)
	{
		memset(indgree, 0, sizeof(indgree));
		memset(money, 0, sizeof(money));
		for (int i = 1; i <= V; i++)
			G[i].clear();
		for (int i = 1; i <= E; i++)
		{
			scanf_s("%d %d", &a, &b);
			G[b].push_back(a);
			indgree[a]++;
		}
		int minn = topu();
		if (minn == -1)
			printf("-1\n");
		else
			printf("%d\n", minn);
	}
	return 0;
}