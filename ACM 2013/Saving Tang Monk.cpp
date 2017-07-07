#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
#define N 1000007

int dis[104][104][12][33], Stot, M;
struct node
{
	int x, y, key, step, S;
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
map<pair<int, int>, int> snake;
char ss[105][105];
int n, m;

bool OK(int nx, int ny)
{
	if (nx < n && nx >= 0 && ny < n && ny >= 0 && ss[nx][ny] != '#')
		return true;
	return false;
}

void bfs(node s)
{
	queue<node> que;
	que.push(s);
	while (!que.empty())
	{
		node now = que.front();
		que.pop();
		int nx = now.x, ny = now.y;
		int key = now.key, step = now.step;
		int S = now.S;
		node tmp;
		for (int k = 0; k<4; k++)
		{
			int kx = nx + dx[k];
			int ky = ny + dy[k];
			if (!OK(kx, ky)) continue;
			tmp.x = kx, tmp.y = ky;
			if (ss[kx][ky] == 'S')                    //蛇
			{
				int ind = snake[make_pair(kx, ky)];   //是第几条蛇
				tmp.key = key;
				if (S & (1 << (ind - 1)))                 //如果已经杀死
				{
					tmp.S = S;
					tmp.step = step + 1;
				}
				else                                 //否则要杀
				{
					tmp.S = S | (1 << (ind - 1));
					tmp.step = step + 2;
				}
				if (tmp.step < dis[kx][ky][tmp.key][tmp.S])
				{
					dis[kx][ky][tmp.key][tmp.S] = tmp.step;
					que.push(tmp);
				}
			}
			else if (ss[kx][ky] >= '1' && ss[kx][ky] <= '9')  //钥匙点
			{
				int num = ss[kx][ky] - '0';
				tmp.step = step + 1;
				tmp.S = S;
				if (num == key + 1)                             //正好是要拿的那个
					tmp.key = key + 1;
				else
					tmp.key = key;
				if (tmp.step < dis[kx][ky][tmp.key][tmp.S])
				{
					dis[kx][ky][tmp.key][tmp.S] = tmp.step;
					que.push(tmp);
				}
			}
			else if (ss[kx][ky] == '$')   //唐僧这个点
			{
				tmp.key = key;
				tmp.S = S;
				tmp.step = step + 1;
				if (M == key + 1)           //已经集齐了所有钥匙，不再扩展，更新dis即可
					dis[kx][ky][M][S] = min(dis[kx][ky][M][S], step + 1);
				else                     //没有集齐，继续走
					que.push(tmp);
			}
			else if (ss[kx][ky] == '.')
			{
				tmp.key = key;
				tmp.S = S;
				tmp.step = step + 1;
				if (tmp.step < dis[kx][ky][tmp.key][tmp.S])
				{
					dis[kx][ky][tmp.key][tmp.S] = tmp.step;
					que.push(tmp);
				}
			}
		}
	}
}

int main()
{
	int Sx, Ex, Sy, Ey;
	int i, j;
	while (scanf("%d%d", &n, &m) != EOF && n + m)
	{
		if (n == 1)
		{
			puts("impossible");
			continue;
		}
		snake.clear();
		Stot = 0;
		M = m + 1;
		for (i = 0; i<n; i++)
		{
			scanf("%s", ss[i]);
			for (j = 0; j<n; j++)
			{
				if (ss[i][j] == 'K')
					Sx = i, Sy = j, ss[i][j] = '.';
				else if (ss[i][j] == 'T')
					Ex = i, Ey = j, ss[i][j] = '$';
				else if (ss[i][j] == 'S')
					snake[make_pair(i, j)] = ++Stot;
			}
		}
		node tmp;
		tmp.x = Sx, tmp.y = Sy, tmp.key = 0, tmp.step = 0, tmp.S = 0;
		memset(dis, INF, sizeof(dis));
		dis[Sx][Sy][0][0] = 0;
		bfs(tmp);
		int mini = INF;
		for (i = 0; i<(1 << Stot); i++)
			mini = min(mini, dis[Ex][Ey][M][i]);
		if (mini == INF)
			puts("impossible");
		else
			printf("%d\n", mini);
	}
	return 0;
}