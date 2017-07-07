#include <cstdio>
#include<cstring>
#include<algorithm>
#define maxn 210

using namespace std;

struct node {
	int x, y, dir;
	node(int x = 0, int y = 0, int dir = -1) : x(x), y(y), dir(dir) {}
};
int map[maxn][maxn];
bool vis[maxn][maxn];
node stack[maxn * maxn], S, T;
int top = 0, n, m;
int dir[4][2] = { {0, -1}, {0, 1},  {1, 0},  {-1, 0} };

bool check_rule(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m)
		return false;
	if (vis[x][y])
		return false;
	if (map[x][y] == 1)
		return false;
	return true;
}

bool check_end(int x, int y)
{
	if (x == T.x && y == T.y)
		return true;
	return false;
}

void print()
{
	printf("(%d, %d)\n", T.x, T.y);
	while (top)
	{
		printf("(%d, %d)\n", stack[top].x, stack[top].y);
		top--;
	}
}

bool dfs()
{
	node next, now;
	int i, j, k, g, h;
	S.dir = -1;
	stack[++top] = S;
	vis[S.x][S.y] = true;
	while (top != 0)
	{
		now = stack[top--];
		i = now.x;
		j = now.y;
		k = now.dir + 1;
		while (k <= 3)
		{
			g = i + dir[k][0];
			h = j + dir[k][1];
			if (check_end(g, h))
			{
				stack[++top] = node(i, j, -1);
				return true;
			}
			if (check_rule(g, h))
			{
				vis[g][h] = true;
				next.x = i;
				next.y = j;
				next.dir = k;
				stack[++top] = next;
				i = g;
				j = h;
				k = -1;
			}
			k++;
		}
	}
	return false;
}

int main(void)
{
	memset(map, 0, sizeof(map));
	memset(vis, false, sizeof(vis));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d %d", &S.x, &S.y);
	scanf("%d %d", &T.x, &T.y);
	if (dfs())
	{
		printf("Find the road!\n");
		print();
	}
	else
		printf("NO!\n");
	return 0;
}