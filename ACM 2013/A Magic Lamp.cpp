#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 1005;
const int maxm = 2005;
const int inf = 999999;
struct node {
	int v, u, next;
}edge[maxm];
int head[maxn], cnt;
int vis[maxn], low[maxn], dfn[maxn], id;
int n, m, ans1;//ans1:缩点的个数( from 1 to ans1 )
int cost[maxn];
int belong[maxn], inde[maxn];//缩点，入度
stack<int>q;
void init() {
	cnt = 0;
	id = 0;
	ans1 = 0;
	memset(vis, 0, sizeof(vis));
	memset(dfn, -1, sizeof(dfn));
	memset(low, -1, sizeof(low));
	memset(head, -1, sizeof(head));
}
void addedge(int a, int b) {
	edge[cnt].v = a;
	edge[cnt].u = b;
	edge[cnt].next = head[a];
	head[a] = cnt++;
}
void tarjan(int now) {
	dfn[now] = low[now] = id++;
	vis[now] = 1;
	q.push(now);
	for (int i = head[now]; i != -1; i = edge[i].next) {
		int next = edge[i].u;
		if (dfn[next] == -1) {
			tarjan(next);
			low[now] = min(low[now], low[next]);
		}
		else if (vis[next] == 1) {
			low[now] = min(low[now], dfn[next]);
		}
	}
	if (low[now] == dfn[now]) {
		ans1++;
		while (1) {
			int tmp;
			tmp = q.top(), q.pop();
			vis[tmp] = 0;
			belong[tmp] = ans1;
			if (tmp == now) break;
		}
	}
}

int main() 
{
	while (scanf("%d%d", &n, &m) != EOF) 
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &cost[i]);
		init();
		int a, b;
		while (m--)
		{
			scanf("%d%d", &a, &b);
			addedge(a, b);
		}
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (dfn[i] == -1)
			{
				tarjan(i);
			}
		}
		memset(inde, 0, sizeof(inde));
		for (int i = 0; i<cnt; i++) {
			a = edge[i].v, b = edge[i].u;
			if (belong[a] != belong[b]) {
				inde[belong[b]]++;
			}
		}
		int ANS1, ANS2;
		ANS1 = ANS2 = 0;
		int tmp_cnt[maxn];
		for (int i = 1; i <= ans1; i++) {
			if (inde[i] == 0)
				ANS1++;//统计缩点之后，入度为0的点
			tmp_cnt[i] = inf;
		}
		for (int i = 1; i <= n; i++)
		{
			int tmp = belong[i];
			if (inde[tmp] == 0)
			{
				tmp_cnt[tmp] = min(tmp_cnt[tmp], cost[i]);
			}
		}
		for (int i = 1; i <= ans1; i++) 
		{
			if (tmp_cnt[i] != inf)
				ANS2 += tmp_cnt[i];
		}
		printf("%d %d\n", ANS1, ANS2);
	}
	return 0;
}