#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int VM = 30;
const int EM = 1010;
const int INF = 0x3f3f3f3f;

int map[VM][VM], q[VM], pre[VM], src, des;

int BFS(int n) 
{
	int front = 0, rear = 0;
	memset(pre, -1, sizeof(pre));
	pre[src] = 0;
	q[rear++] = src;
	while (front != rear) 
	{
		int u = q[front++];
		for (int v = 1; v <= n; v++)
		{
			if (pre[v] != -1 || map[u][v] == 0)
				continue;
			pre[v] = u;
			if (v == des)
				return 1;
			q[rear++] = v;
		}
	}
	return 0;
}

int EK(int n) 
{
	int ans = 0, i;
	while (BFS(n)) 
	{
		int tmp = INF;
		for (i = des; i != src; i = pre[i])
			tmp = tmp<map[pre[i]][i] ? tmp : map[pre[i]][i];
		ans += tmp;
		for (i = des; i != src; i = pre[i]) 
		{
			map[pre[i]][i] -= tmp;
			map[i][pre[i]] += tmp;
		}
	}
	return ans;
}

int main() 
{
	int t, n, m;
	int cases = 0;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		src = 1;
		des = n;
		int u, v, w;
		while (m--)
		{
			scanf("%d%d%d", &u, &v, &w);
			map[u][v] += w;
		}
		int ans = EK(n);
		printf("Case %d: %d\n", ++cases, ans);
	}
	return 0;
}