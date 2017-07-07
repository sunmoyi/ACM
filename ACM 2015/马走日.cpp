/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int maxx, maxy;
bool vis[15][15];
int dir[8][2] = { {1,2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1},{-1, 2 } };
int summ;

void dfs(int x, int y, int sum)
{

	if (sum == maxx * maxy)
	{
		summ++;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (vis[xx][yy])
			continue;
		if (xx < 0 || xx >= maxx || yy < 0 || yy >= maxy)
			continue;
		vis[xx][yy] = true;
		dfs(xx, yy, sum + 1);
		vis[xx][yy] = false;
	}
}

int main(void)
{
	int i;
	int sx, sy;
	scanf("%d", &i);	
	while (i--)
	{
		scanf("%d %d %d %d", &maxx, &maxy, &sx, &sy);
		memset(vis, false, sizeof(vis));
		summ = 0;
		vis[sx][sy] = true;
		dfs(sx, sy, 1);
		printf("%d\n", summ);
	}
	return 0;
}*/



#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

bool Map[5][5];
char input;
int dir_i[4] = { 0, 0, -1, 1 };
int dir_j[4] = { -1, 1, 0, 0 };

bool ifAllSame() {
	bool sign = Map[0][0];
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			if (Map[i][j] != sign) 
				return false;
		}
	}
	return true;
}

void change(int a, int b) 
{
	Map[a][b] = !Map[a][b];
	int temp_i = a;
	int temp_j = b;
	for (int i = 0; i < 4; i++)
	{
		temp_i = a + dir_i[i];
		temp_j = b + dir_j[i];
		if (temp_i >= 0 && temp_i < 4 && temp_j >= 0 && temp_j < 4) 
		{
			Map[temp_i][temp_j] = !Map[temp_i][temp_j];
		}
	}
}

bool dfs(int step, int i, int j)
{
	if (step == 0) 
	{
		if (ifAllSame())
			return true;
		else 
			return false;
	}
	for (int t_i = i; t_i < 4; t_i++) 
	{
		if (t_i == i)
			for (int t_j = j; t_j < 4; t_j++) 
			{
				change(t_i, t_j);
				if (dfs(step - 1, t_i, t_j)) 
					return true;
				else 
					change(t_i, t_j);
			}
		else
			for (int t_j = 0; t_j < 4; t_j++)
			{
				change(t_i, t_j);
				if (dfs(step - 1, t_i, t_j)) 
					return true;
				else 
					change(t_i, t_j);
			}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			scanf("%c", &input);
			if (input == 'w') 
				Map[i][j] = true;
			else 
				Map[i][j] = false;
		}
		getchar();
	}
	if (ifAllSame()) 
	{
		printf("0\n");
		return 0;
	}
	else
	{
		for (int k = 1; k <= 16; k++) 
		{
			if (dfs(k, 0, 0))
			{
				printf("%d\n", k);
				return 0;
			}
		}
		printf("Impossible\n");
	}
	return 0;
}