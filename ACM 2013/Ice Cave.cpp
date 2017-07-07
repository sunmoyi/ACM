#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
char map[505][505];
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

struct point{
	int x;
	int y;
}start, endd;

bool inmap(int x, int y)
{
	if (x >= 1 && y >= 1 && x <= n && y <= m)
		return true;
	else
		return false;
}
bool BFS(point start)
{
	queue<point>q;
	q.push(start);
	point temp, next;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next.x = temp.x + dir[i][0];
			next.y = temp.y + dir[i][1];
			if (inmap(next.x, next.y) && (map[next.x][next.y] == '.' || (next.x == endd.x && next.y == endd.y)))
			{
				if (next.x == endd.x && next.y == endd.y && map[next.x][next.y] == 'X')
					return true;
				map[next.x][next.y] = 'X';
				q.push(next);
			}
		}
	}
	return false;
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", map[i] + 1);
		}
		scanf("%d %d %d %d", &start.x, &start.y, &endd.x, &endd.y);
		if (BFS(start))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}