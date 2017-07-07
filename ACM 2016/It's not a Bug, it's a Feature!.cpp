#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30
#define maxm 110
#define maxx 2000000
#define INF 0x3f3f3f3f

using namespace std;

int s[2][maxm], t[2][maxm], w[maxm], n, m;
char a[maxn], b[maxn];
int q[maxx], inq[maxx], d[maxx];

int init()
{
	int i, j;
	scanf("%d %d", &n, &m);
	if (!n && !m)
		return 0;
	memset(s, 0, sizeof(s));
	memset(t, 0, sizeof(t));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %s %s", &w[i], a, b);
		for (j = 0; j < n; j++)
		{
			if (a[j] == '+')//这里的1是有效的
				s[1][i] += (1 << j);
			if (a[j] != '-')//这里的0是有效的
				s[0][i] += (1 << j);
			if (b[j] == '+')
				t[1][i] += (1 << j);
			if (b[j] != '-')
				t[0][i] += (1 << j);
		}
	}
	return 1;
}

void SPFA()
{
	int i, j, k, MAX, front, rear, u, v;
	MAX = 1 << n;
	for (i = 0; i < MAX; i++)
	{
		d[i] = INF;
		inq[i] = 0;
	}
	front = rear = 0;
	d[MAX - 1] = 0;
	q[rear++] = MAX - 1;
	while (front != rear)
	{
		u = q[front++];
		if (front > MAX)
			front = 0;
		inq[u] = 0;
		for (int i = 0; i < m; i++)
		{
			if ((u | s[1][i]) == u && (u & s[0][i]) == u)
			{
				v = u;
				v |= t[1][i];
				v &= t[0][i];
				if (d[u] + w[i] < d[v])
				{
					d[v] = d[u] + w[i];
					if (!inq[v])
					{
						q[rear++] = v;
						if (rear > MAX)
							rear = 0;
						inq[v] = 1;
					}
				}
			}
		}
	}
	if (d[0] == INF)
		printf("Bugs cannot be fixed.\n");
	else
		printf("Fastest sequence takes %d seconds.\n", d[0]);
}

int main(void)
{
	int T = 0;
	while (init())
	{
		printf("Product %d\n", ++T);
		SPFA();
		printf("\n");
	}
	return 0;
}