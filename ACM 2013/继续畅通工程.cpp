#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int from;
	int to;
	int len;
	int mark;
}a[100000];
int father[105];
int rankk[105];
int n, m;

bool cmp(node a, node b)
{
	return a.len < b.len;
}

void init(int x)
{
	for (int i = 0; i < x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];


	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] == rankk[y])
			rankk[x] ++;
	}
	return true;
}

int main(void)
{
	while (scanf("%d", &n) != EOF && n != 0)
	{
		init(104);
		int road = (n * (n - 1)) / 2;
		for (int i = 1; i <= road; i++)
		{
			scanf("%d %d %d %d", &a[i].from, &a[i].to, &a[i].len, &a[i].mark);
			if (a[i].mark == 1)
				unoin(a[i].from, a[i].to);
		}
		sort(a + 1, a + road, cmp);
		int ans = 0;
		for (int i = 1; i <= road; i++)
		{
			if (a[i].mark == 0 && unoin(a[i].from, a[i].to))
				ans += a[i].len;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f
#define max 100+10
int lowcost[max], map[max][max], visit[max];
int city, road;
int prime()
{
	int i, j, next;
	int min;
	int mincost = 0;
	memset(visit, 0, sizeof(visit));
	for (i = 1; i <= city; i++)
	{
		lowcost[i] = map[1][i];
	}
	visit[1] = 1;
	for (i = 1; i < city; i++)
	{
		min = INF;
		for (j = 1; j <= city; j++)
		{
			if (!visit[j] && min > lowcost[j])
			{
				min = lowcost[j];
				next = j;
			}
		}
		if (min == INF) break;
		mincost += min;
		visit[next] = 1;
		for (j = 1; j <= city; j++)
		{
			if (!visit[j] && lowcost[j] > map[next][j])
			{
				lowcost[j] = map[next][j];
			}
		}
	}
	return mincost;
}
int main()
{
	int i, j, need;
	int a, b, c, exist;
	while (scanf("%d", &city) && (city != 0))
	{
		memset(map, INF, sizeof(map));
		road = city*(city - 1) / 2;
		for (i = 0; i < road; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &exist);
			if (exist)
				map[a][b] = map[b][a] = 0;
			else
				map[a][b] = map[b][a] = c;
		}
		need = prime();
		printf("%dn", need);
	}
	return 0;
}
*/