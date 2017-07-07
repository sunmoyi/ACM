/*奇偶剪枝
*
*简单的说每走错（不一定是错 方向 因为墙的绕路等等）一步都需要另一步来更正  这就是2步
*经过N次错误和修正之后必定为偶数
*所以最终的路径长度等于最短路径长度+ 2 * n;（*********）
*
*推广之，若 t-[abs(ex-sx)+abs(ey-sy)] 结果为非偶数（奇数），则无法在t步恰好到达；
*返回，false；
*反之亦反。  百度百科
*********************************
*从新写一份  
*首先注意使用此条件的前提是是剩余的步数大于大于不考虑墙的最短路径
*反证法：
*假设当前的步数没错 
*
*当我没说  记住就行  不会证
*
*第N步到达某个坐标 （N - 可行最短路径） % 2 == 0
*/
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int sx, sy, ex, ey;
int n, m;
char map[10][10];
int flag, step;
int d[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
void dfs(int x, int y, int t)
{
	if (flag == 1) 
		return;                           
	if (t < abs(ex - x) + abs(ey - y) || (t - (abs(ex - x) + abs(ey - y))) % 2) 
		return;//剪枝  如果步数小于不考虑墙的最短路径                                                             
	else if (t == 0)                
	{
		if (x == ex&&y == ey)  
		{ 
			flag = 1; 
			return; 
		}   
		else 
			return; 
	}
	else
		for (int i = 0; i<4; i++)                  
		{
			int nx = x + d[i][0], ny = y + d[i][1];
			if (nx>0 && nx <= n&&ny>0 && ny <= m && (map[nx][ny] == '.' || map[nx][ny] == 'D')) 
			{
				map[nx][ny] = 'X';               
				dfs(nx, ny, t - 1);
				map[nx][ny] = '.';                   
			}

		}
	return;
}
int main()
{


	char str[10];
	int t;
	while (scanf_s("%d%d%d", &n, &m, &t) != EOF)
	{
		if (n == 0 && m == 0 && t == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%s", str, 10);
			for (int j = 1; j <= m; j++)
			{
				map[i][j] = str[j - 1];
				if (map[i][j] == 'S')  sx = i, sy = j;
				else if (map[i][j] == 'D') ex = i, ey = j;
			}
		}
		flag = 0;
		dfs(sx, sy, t);
		if (flag == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}