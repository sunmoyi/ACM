#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int vist[105][105][105];
int a, b, c;
struct node
{
	int a, b, c;
	int step;
}s[105];
int sum = 0;

int  bfs()
{
	queue<node>q;
	memset(vist, 0, sizeof(vist));
	node p1;
	p1.a = a;
	p1.b = 0;
	p1.c = 0;
	p1.step = 0;
	q.push(p1);
	vist[p1.a][0][0] = 1;
	while (!q.empty())
	{
		p1 = q.front();
		q.pop();
		if ((p1.a == a / 2 && p1.b == a / 2) || (p1.a == a / 2 && p1.c == a / 2) || (p1.b == a / 2 && p1.c == a / 2))
		{
			return p1.step;
		}
		node p2;
		if (p1.a != 0)
		{
			if (p1.a>b - p1.b)
			{
				p2.a = p1.a - (b - p1.b);
				p2.b = b;
				p2.c = p1.c;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.a = 0;
				p2.b = p1.b + p1.a;
				p2.c = p1.c;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}

		if (p1.a != 0)
		{
			if (p1.a>c - p1.c)
			{
				p2.a = p1.a - (c - p1.c);
				p2.b = p1.b;
				p2.c = c;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.a = 0;
				p2.b = p1.b;
				p2.c = p1.c + p1.a;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}

		if (p1.b != 0)
		{
			if (p1.b>a - p1.a)
			{
				p2.b = p1.b - (a - p1.a);
				p2.a = a;
				p2.c = p1.c;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.b = 0;
				p2.a = p1.a + p1.b;
				p2.c = p1.c;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}

		if (p1.b != 0)
		{
			if (p1.b>c - p1.c)
			{
				p2.b = p1.b - (c - p1.c);
				p2.a = p1.a;
				p2.c = c;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.b = 0;
				p2.a = p1.a;
				p2.c = p1.c + p1.b;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}

		if (p1.c != 0)
		{
			if (p1.c>a - p1.a)
			{
				p2.c = p1.c - (a - p1.a);
				p2.a = a;
				p2.b = p1.b;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.c = 0;
				p2.a = p1.a + p1.c;
				p2.b = p1.b;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}

		if (p1.c != 0)
		{
			if (p1.c>b - p1.b)
			{
				p2.c = p1.c - (b - p1.b);
				p2.a = p1.a;
				p2.b = b;
				p2.step = p1.step + 1;
			}
			else
			{
				p2.c = 0;
				p2.a = p1.a;
				p2.b = p1.b + p1.c;
				p2.step = p1.step + 1;
			}
			if (!vist[p2.a][p2.b][p2.c])
			{
				vist[p2.a][p2.b][p2.c] = 1;
				q.push(p2);
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf_s("%d %d %d", &a, &b, &c) != EOF && (a + b + c))
	{
		if (a % 2 == 1)
		{
			printf("NO\n");
			continue;
		}
		int ans = bfs();
		if (ans >= 0)
			printf("%d\n", ans);
		else
			printf("NO\n");
	}
	return 0;
}
