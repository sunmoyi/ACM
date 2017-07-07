#include <iostream>
using namespace std;
#define MAXT 26
#define MAXE 1000
#define INF INT_MAX

typedef struct {
	int s, t, w;
}Edge;

Edge edge[MAXE];

int r[MAXT];		//某个小时需要多少人
int t[MAXT];		//在第i个小时应聘的人数
int d[MAXT];
int n, edgesum, ans;

void add(int s, int t, int w) 
{
	edge[edgesum].s = s;
	edge[edgesum].t = t;
	edge[edgesum++].w = w;
}

void buildgragh(int x) 
{
	int i;
	edgesum = 48;
	for (i = 1; i <= 16; i++) 
		add(i + 8, i, -r[i + 8]);
	for (i = 17; i <= 24; i++) 
		add(i - 16, i, x - r[i - 16]);
	add(24, 0, -x);
}

int bellman_ford() 
{
	int i, j;
	for (i = 0; i <= 24; i++) 
		d[i] = INF;
	d[0] = 0;
	for (i = 0; i <= 24; i++)
	{
		for (j = 0; j<edgesum; j++) 
		{
			if (d[edge[j].s] + edge[j].w<d[edge[j].t])
			{
				d[edge[j].t] = d[edge[j].s] + edge[j].w;
			}
		}
	}


	for (j = 0; j<edgesum; j++) 
	{						//判断是否有负环
		if (d[edge[j].s] + edge[j].w<d[edge[j].t]) 
		{
			return 0;
		}
	}
	return 1;
}

void Besearch(int low, int high)
{
	if (low>high) return;
	int mid = (low + high) / 2;
	buildgragh(mid);
	if (bellman_ford()) 
	{
		ans = mid;
		Besearch(low, mid - 1);
	}
	else 
	{
		Besearch(mid + 1, high);
	}
}

int main()
{
	int i, Case, x;
	scanf("%d", &Case);
	while (Case--)
	{
		memset(t, 0, sizeof(t));
		for (i = 1; i <= 24; i++) scanf("%d", &r[i]);

		scanf("%d", &n);
		for (i = 1; i <= n; i++) 
		{		//x+1时刻的应聘人数加1
			scanf("%d", &x);
			t[x + 1]++;
		}
		edgesum = 0;
		for (i = 1; i <= 24; i++)
		{			//这48条边是固定的，每个图都需要
			add(i - 1, i, t[i]);
			add(i, i - 1, 0);
		}
		ans = -1;						//对人数二分枚举求解
		Besearch(0, n);
		if (ans == -1) printf("No Solution\n");
		else printf("%d\n", ans);
	}
	return 0;
}