#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<iostream>  
using namespace std;

const int maxn = 20000 + 10;
const int INF = 10000 + 10;

struct Node
{
	int w, h;
}node[maxn], dp[maxn];

bool cmp(Node a, Node b)
{
	if (a.w == b.w) return a.h < b.h;
	else return a.w > b.w;
}

int main()
{
	int T;
	int n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &node[i].w, &node[i].h);
			dp[i].w = dp[i].h = INF; //假设初始化有 N 个可以嵌套的娃娃  
		}
		sort(node, node + n, cmp);
		//for(int i = 0; i < n; i++) printf("%d %d\n", node[i].w, node[i].h); printf("\n");  

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while (dp[j].w <= node[i].w || dp[j].h <= node[i].h) j++;
			dp[j].w = node[i].w; //不断更新为当前情况  
			dp[j].h = node[i].h;
		}

		// for(int i = 0; i < n; i++) printf("%d %d\n", dp[i].w, dp[i].h); printf("\n");  

		int ans = 0;
		for (int i = 0; i < n; i++)
			if (dp[i].h != INF) //看有几个嵌套过  
				ans++;

		printf("%d\n", ans);
	}
	return 0;
}