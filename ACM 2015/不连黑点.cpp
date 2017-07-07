#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

bool vis[10][10];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

struct node {
	int x, y;
	node(int xx = 0, int yy = 0) :x(xx), y(yy) {}
};

stack<node>S;

void dfs(int x, int y, int t)
{
	if (t == 24)
	{
		while (S.size() != 0)
		{
			printf("%d %d\n", S.top().x, S.top().y);
		}
		printf("\n\n\n");
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx <= 0 || xx > 5 || yy <= 0 || yy > 5 || vis[xx][yy])
			continue;
		vis[xx][yy] = true;
		S.push(node(xx, yy));
		dfs(xx, yy, t + 1);
		S.pop();
		vis[xx][yy] = false;
	}
	return ;
}

int main(void)
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			memset(vis, false, sizeof(vis));
			vis[1][2] = true;
			vis[i][j] = true;
			while (S.size())
				S.pop();
			dfs(i, j, 1);
		}
	}
	return 0;
}