#include<stdio.h>
int n;
int tot;
int vis[1000][1000];
int c[10000];
void search(int cur)
{
	if (cur == n)
		tot++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur + n - i])
			{
				c[cur] = i;
				vis[0][i] = vis[1][cur + 1] = vis[2][cur + n - i] = 1; 
				search(cur + 1);
				vis[0][i] = vsi[1][cur + 1] = vis[2][cur + 2 - i] = 0;
			}
		}
	}
}