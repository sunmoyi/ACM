#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<queue>  
#define eps 1e-6  

using namespace std;

const int MAXN = 5000000;
int n;
int a[10], b[10];
int vis[MAXN];
bool fuck[10];

void bfs(int n) 
{
	queue<int> q;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp += (i + 1) * (1 << (3 * i));
	}
	q.push(tmp);
	vis[tmp] = 0;
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		memset(fuck, 0, sizeof(fuck));
		for (int i = 0; i < n; i++) 
		{ //i+1ÔÚÄÄ¸öÎ»ÖÃ   
			int pos = (s >> (3 * i)) % 8;
			if (fuck[pos]) 
				continue;
			fuck[pos] = 1;
			if (pos>1 && !fuck[pos - 1])
			{
				int t = s - (1 << (3 * i));
				if (vis[t] == -1)
				{
					q.push(t);
					vis[t] = vis[s] + 1;
				}
			}
			if (pos<n && !fuck[pos + 1])
			{
				int t = s + (1 << (3 * i));
				if (vis[t] == -1)
				{
					q.push(t);
					vis[t] = vis[s] + 1;
				}
			}
		}
	}
}
int main()
{
	int T; cin >> T;
	memset(vis, -1, sizeof(vis));
	for (int i = 1; i <= 7; i++) 
		bfs(i);
	while (T--) 
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) 
			a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
		int s = 0;
		for (int i = 1; i <= n; i++)
		{
			s += i*(1 << (3 * a[i]));
		}
		printf("%d\n", vis[s]);
	}
	return 0;
}