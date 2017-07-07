#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int a;
	int b;
	int c;
	int d;
	int step;
};
bool vis[10005];
bool primer[10005];
int t;
int start, endd;

int bfs(int s)
{
	if (s == endd)
		return 0;
	vis[s] = true;
	node ss;
	ss.d = s % 10;
	s /= 10;
	ss.c = s % 10;
	s /= 10;
	ss.b = s % 10;
	s /= 10;
	ss.a = s;
	ss.step = 0;
	queue<node>Q;
	Q.push(ss);
	
	while (!Q.empty())
	{
		node now = Q.front(), next;
		Q.pop();
		for (int i = 1; i <= 9; i++)
		{
			next = now;
			next.a = i;
			next.step = now.step + 1;
			int x = next.a * 1000 + next.b * 100 + next.c * 10 + next.d;
			if (vis[x] || primer[x])
				continue;
			if (x == endd)
				return next.step;
			Q.push(next);
			vis[x] = true;
		}
		for (int i = 0; i <= 9; i++)
		{
			next = now;
			next.b = i;
			next.step = now.step + 1;
			int x = next.a * 1000 + next.b * 100 + next.c * 10 + next.d;
			if (vis[x] || primer[x])
				continue;
			if (x == endd)
				return next.step;
			Q.push(next);
			vis[x] = true;
		}
		for (int i = 0; i <= 9; i++)
		{
			next = now;
			next.c = i;
			next.step = now.step + 1;
			int x = next.a * 1000 + next.b * 100 + next.c * 10 + next.d;
			if (vis[x] || primer[x])
				continue;
			if (x == endd)
				return next.step;
			Q.push(next);
			vis[x] = true;
		}
		for (int i = 1; i <= 9; i += 2)
		{
			next = now;
			next.d = i;
			next.step = now.step + 1;
			int x = next.a * 1000 + next.b * 100 + next.c * 10 + next.d;
			if (vis[x] || primer[x])
				continue;
			if (x == endd)
				return next.step;
			Q.push(next);
			vis[x] = true;
		}
	}
}

int main(void)
{
	memset(primer, 0, sizeof(primer));
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = 2; i * j <= 10000; j++)
		{
			primer[i * j] = true;
		}
	}
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			memset(vis, 0, sizeof(vis));
			scanf("%d %d", &start, &endd);

			int ans = bfs(start);
			printf("%d\n", ans);
		}
	}
	return 0;
}