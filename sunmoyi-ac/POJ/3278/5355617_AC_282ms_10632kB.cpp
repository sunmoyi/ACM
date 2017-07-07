#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int site;
	int step;
}a;
int start, endd;
bool vis[10000000];

int bfs(node a)
{
	queue<node>Q;
	Q.push(a);
	vis[a.site] = true;
	while (!Q.empty())
	{
		node now = Q.front(), next;
		Q.pop();
		if (now.site == endd)
			return now.step;
		if (!vis[now.site + 1] && now.site + 1 <= 100005 && now.site + 1 >= 0)
		{
			next.site = now.site + 1;
			next.step = now.step + 1;
			vis[next.site] = true;
			Q.push(next);
		}
		if (!vis[now.site - 1] && now.site - 1 <= 100005 && now.site - 1 >= 0)
		{
			next.site = now.site - 1;
			next.step = now.step + 1;
			vis[next.site] = true;
			Q.push(next);
		}
		if (!vis[now.site * 2] && now.site * 2 <= 100005 && now.site * 2 >= 0)
		{
			next.site = now.site * 2;
			next.step = now.step + 1;
			vis[next.site] = true;
			Q.push(next);
		}
		
	}
}

int main(void)
{
	while (scanf("%d %d", &start, &endd) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		a.site = start;
		a.step = 0;
		int ans = bfs(a);
		printf("%d\n", ans);
	}
	return 0;
}