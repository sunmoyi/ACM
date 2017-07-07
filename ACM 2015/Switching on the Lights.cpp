#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

#define maxn 200

using namespace std;

int n, m;
bool light[maxn][maxn];
struct node{
	int x, y;
	node(int x = 0, int y = 0) :x(x), y(y) {}
	bool friend operator == (node a, node b)
	{
		if (a.x == b.x && b.y == a.y)
			return true;
		else
			return false;
	}
};
vector<int>open[200000];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1},  {0, -1} };
bool vis[maxn][maxn];

int main(void)
{
	int a, b, c, d;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(light, false, sizeof(light));
		memset(open, 0, sizeof(open));
		light[1][1] = true;
		for (int i = 1; i <= n * 103; i++)
			open[i].clear();
		queue<node>Q;
		Q.push(node(1, 1));
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			open[a * 100 + b].push_back(c * 100 + d);
			if (a * 100 + b == 101)
				light[c][d] = true;
		}
		bool flag = true;
		while (flag)
		{
			memset(vis, 0, sizeof(vis));
			flag = false;
			node now1 = Q.front();
			while (Q.front() == now1)
			{
				node now = Q.front();
				Q.pop();
				vis[now.x][now.y] = 1;
				for (int i = 0; i < 4; i++)
				{
					node next(now.x + dir[i][0], now.y + dir[i][1]);
					if (next.x <= 0 || next.x > n)
						continue;
					if (next.y <= 0 || next.y > n)
						continue;
					if (light[next.x][next.y] == false)
						continue;
					if (vis[next.x][next.y] == 1)
						continue;
					vis[next.x][next.y] = 1;
					Q.push(next);
					flag = true;
					for (int i = 0; i < open[next.x * 100 + next.y].size(); i++)
					{
						int temp = open[next.x * 100 + next.y][i];
						int yy = temp % 100;
						if (yy == 0)
							yy = 100;
						int xx = (temp - yy) / 100;
						light[xx][yy] = true;
					}
				}
				Q.push(now);
			}

		}
		int temp = 0;
		while (!Q.empty())
		{
			temp++;
			Q.pop();
		}
		printf("%d\n", temp);
	}
	return 0;
}