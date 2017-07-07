#include<iostream>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
struct node
{
	int e, next;
}edge[50002];
int head[20002], exist[20002], dfn[20002], low[20002], stack[20002], weight[20002], n, m, s, e, top, Count, Time;
int ind[20002], outd[20002];

void tarjan(int u)
{
	stack[top++] = u;
	dfn[u] = low[u] = ++Time;
	exist[u] = 1;
	for (int end = head[u]; end != -1; end = edge[end].next)
	{
		if (!dfn[edge[end].e])
		{
			tarjan(edge[end].e);
			low[u] = min(low[u], low[edge[end].e]);
		}
		else
		{
			if (exist[edge[end].e] == 1)
				low[u] = min(low[u], dfn[edge[end].e]);
		}
	}
	if (dfn[u] == low[u])
	{
		int v;
		do {
			v = stack[--top];
			minn[Count] = min(minn[Count], point[v].price);
			exist[v] = false;
			weight[v] = Count;
		} while( v != u);
		Count++;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++)
		{
			head[i] = -1;
			ind[i] = outd[i] = exist[i] = weight[i] = low[i] = dfn[i] = 0;
		}
		Time = top = Count = 0;
		for (int i = 0; i<m; i++)
		{
			scanf("%d%d", &s, &e);
			edge[i].e = e;
			edge[i].next = head[s];
			head[s] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i])
			{
				tarjan(i);
			}
		}
		if (Count == 1)
		{ 
			printf("0\n"); 
			continue; 
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				for (int end = head[i]; end != -1; end = edge[end].next)
				{
					if (weight[i] != weight[edge[end].e])
					{
						ind[weight[edge[end].e]]++;
						outd[weight[i]]++;
					}
				}
			}
			int maxin = 0, maxout = 0;
			for (int i = 0; i<Count; i++)
			{
				if (ind[i] == 0)maxout++;
				if (outd[i] == 0)maxin++;
			}
			printf("%d\n", max(maxout, maxin));
		}
	}
	return 0;
}
