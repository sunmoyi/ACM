#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

#define maxn 1000000
using namespace std;

struct Node {
	int a;
	int b;
	int step;
	char str[100][10];
};
int va, vb, vc;
int vis[110][110];

bool bfs()
{
	Node s;
	s.a = s.b = s.step = 0;
	queue<Node>Q;
	Q.push(s);
	while (!Q.empty())
	{
		Node now = Q.front();
		Q.pop();
		if (now.a == vc || now.b == vc)
		{
			printf("%d\n", now.step);
			for (int i = 1; i <= now.step; i++)
				printf("%s\n", now.str[i]);
			return true;
		}

////////////////////a/////////////////////////////////
		if (now.a != 0)
		{
			Node next = now;
			next.a = 0;
			next.step++;
			strcpy_s(next.str[next.step], "DROP(1)");
			if (!vis[next.a][next.b])
			{
				Q.push(next);
				vis[next.a][next.b] = true;
			}
		}
		if (now.a != va)
		{
			Node next = now;
			next.a = va;
			next.step++;
			strcpy_s(next.str[next.step], "FILL(1)");
			if (!vis[next.a][next.b])
			{
				Q.push(next);
				vis[next.a][next.b] = true;
			}
		}
		if (now.a != 0 && now.b != vb)
		{
			Node next = now;
			if (now.a + now.b <= vb)
			{
				next.b = now.a + now.b;
				next.a = 0;
				next.step++;
				strcpy_s(next.str[next.step], "POUR(1,2)");
				if (!vis[next.a][next.b])
				{
					Q.push(next);
					vis[next.a][next.b] = true;
				}
			}
			else
			{
				next.b = vb;
				next.a = now.a - (vb - now.b);
				next.step++;
				strcpy_s(next.str[next.step], "POUR(1,2)");
				if (!vis[next.a][next.b])
				{
					Q.push(next);
				}
			}
		}

/////////////////////b/////////////////////////////////
		if (now.b != 0)
		{
			Node next = now;
			next.b = 0;
			next.step++;
			strcpy_s(next.str[next.step], "DROP(2)");
			if (!vis[next.a][next.b])
			{
				Q.push(next);
				vis[next.a][next.b] = true;
			}
		}
		if (now.b != vb)
		{
			Node next = now;
			next.b = vb;
			next.step++;
			strcpy_s(next.str[next.step], "FILL(2)");
			if (!vis[next.a][next.b])
			{
				Q.push(next);
				vis[next.a][next.b] = true;
			}
		}
		if (now.b != 0 && now.a != va)
		{
			Node next = now;
			if (now.a + now.b <= va)
			{
				next.a = now.a + now.b;
				next.b = 0;
				next.step++;
				strcpy_s(next.str[next.step], "POUR(2,1)");
				if (!vis[next.a][next.b])
				{
					Q.push(next);
					vis[next.a][next.b] = true;
				}
			}
			else
			{
				next.a = va;
				next.b = now.b - (va - now.a);
				next.step++;
				strcpy_s(next.str[next.step], "POUR(2,1)");
				if (!vis[next.a][next.b])
				{
					Q.push(next);
				}
			}
		}
///////////////////////////////////////////////////////

	}
	return false;
}

int main(void)
{
	while (scanf_s("%d %d %d", &va, &vb, &vc) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		if (!bfs())
			printf("impossible\n");
	}
	return 0;
}