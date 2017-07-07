#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct node {
	int x;
	int y;
	int heigh;
	node(int a = 0, int b = 0, int c = 0) :x(a), y(b), heigh(c) {}
	friend bool operator < (node a, node b)
	{
		return a.heigh > b.heigh;
	}
}map[110][110];
int n, m;
int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int dp[110][110];

int main(void)
{
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		priority_queue<node>Q;
		int maxx = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &map[i][j].heigh);
				map[i][j].x = i;
				map[i][j].y = j;
				Q.push(node(i, j, map[i][j].heigh));
				dp[i][j] = 1;
			}
		}
		while (!Q.empty())
		{
			node a = Q.top();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int xx = a.x + dir[i][0];
				int yy = a.y + dir[i][1];
				if (xx <= 0 || xx > n || yy <= 0 || yy > m)
					continue;
				if (map[xx][yy].heigh <= map[a.x][a.y].heigh)
					continue;
				dp[xx][yy] = max(dp[xx][yy], dp[a.x][a.y] + 1);
				maxx = max(maxx, dp[xx][yy]);
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}