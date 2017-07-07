#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n, m;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
char s[505][505];
int r1, c1, r2, c2;

struct point{
	int x;
	int y;

}st, en;

bool judge(int x, int y)
{
	if (x >= 1 && y >= 1 && x <= n&&y <= m)
		return true;
	else
		return false;
}

bool bfs(){
	queue<point>q;
	st.x = r1, st.y = c1;
	q.push(st);
	point temp, next;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			next.x = temp.x + dir[i][0];
			next.y = temp.y + dir[i][1];
			if (judge(next.x, next.y) && (s[next.x][next.y] == '.' || (next.x == r2 && next.y == c2)))
			{
				if (next.x == r2 && next.y == c2 && s[next.x][next.y] == 'X')
					return true;
				s[next.x][next.y] = 'X';
				q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s[i] + 1);
		}
		cin >> r1 >> c1 >> r2 >> c2;
		if (bfs())
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
}