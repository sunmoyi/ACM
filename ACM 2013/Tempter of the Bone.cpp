/*��ż��֦
*
*�򵥵�˵ÿ�ߴ���һ���Ǵ� ���� ��Ϊǽ����·�ȵȣ�һ������Ҫ��һ��������  �����2��
*����N�δ��������֮��ض�Ϊż��
*�������յ�·�����ȵ������·������+ 2 * n;��*********��
*
*�ƹ�֮���� t-[abs(ex-sx)+abs(ey-sy)] ���Ϊ��ż���������������޷���t��ǡ�õ��
*���أ�false��
*��֮�෴��  �ٶȰٿ�
*********************************
*����дһ��  
*����ע��ʹ�ô�������ǰ������ʣ��Ĳ������ڴ��ڲ�����ǽ�����·��
*��֤����
*���赱ǰ�Ĳ���û�� 
*
*����û˵  ��ס����  ����֤
*
*��N������ĳ������ ��N - �������·���� % 2 == 0
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
		return;//��֦  �������С�ڲ�����ǽ�����·��                                                             
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