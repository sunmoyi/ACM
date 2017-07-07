#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define inf 0x3f3f3f3f
#define eps 1e-6
#define ll __int64
using namespace std;
#define N 1010

struct node
{
	int v, w, next;
}e[30020];
int d[N], inq[N], outq[N], n, head[N], h;

void addedge(int a, int b, int c)
{
	e[h].v = b;
	e[h].w = c;
	e[h].next = head[a];
	head[a] = h++;
}

int spfa(int s)
{
	memset(d, 0x3f, sizeof d);
	memset(inq, 0, sizeof inq);
	memset(outq, 0, sizeof outq);
	d[s] = 0; inq[s] = 1;
	queue<int> q;
	q.push(s);
	int i, x;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		inq[x] = 0;
		outq[x]++;
		if (outq[x]>n) return 0;
		for (i = head[x]; i != -1; i = e[i].next)
		{
			if (d[e[i].v]>d[x] + e[i].w)
			{
				d[e[i].v] = d[x] + e[i].w;
				if (!inq[e[i].v])
				{
					inq[e[i].v] = 1;
					q.push(e[i].v);
				}
			}
		}
	}
	return 1;
}

void init()
{
	memset(head, -1, sizeof head);
	h = 0;
}

int main()
{
	int T, a, b, c, x, y;
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d%d%d", &n, &x, &y);
		while (x--)
		{
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c);
		}
		while (y--)
		{
			scanf("%d%d%d", &a, &b, &c);
			addedge(b, a, -c);
		}
		if (!spfa(1))
			printf("-1\n");
		else if (d[n] != inf)
			printf("%d\n", d[n]);
		else printf("-2\n");
	}
	return 0;
}