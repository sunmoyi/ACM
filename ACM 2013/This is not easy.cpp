#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 0xfffffff

using namespace std;

typedef struct node{
	int x, y, t;
	int k, dog;
}node;

int fmin(int a, int b)
{ 
	return a<b ? a : b; 
}

int dirx[] = { 0, 0, 1, 0, -1 }, diry[] = { 0, 1, 0, -1, 0 };
int dogx[10], dogy[10], dogl;
int n, TT;
bool mark[105][105][20][64];
char maze[105][105];

int which_dog(int x, int y){
	for (int i = 1; i <= dogl; ++i)
		if (x == dogx[i] && y == dogy[i]) 
			return i;
}

void bfs(node s){
	queue <node> q;
	mark[s.x][s.y][s.k][s.dog] = true;
	q.push(s);
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		if (s.t>TT)continue;
		if (maze[s.x][s.y] == 'P')
		{
			TT = fmin(TT, s.t);
			continue;
		}
		for (int i = 1; i <= 4; i++)
		{
			node w = s;
			w.x += dirx[i];
			w.y += diry[i];
			w.t++;
			if (w.x<1 || w.x>n || w.y<1 || w.y>n || maze[w.x][w.y] == '#') continue;
			char c = maze[w.x][w.y];
			if (c == 'D'){
				int j = which_dog(w.x, w.y);
				if ((w.dog&(1 << j)) == 0)
				{
					w.dog |= (1 << j);
					w.t++;
				}
				if (!mark[w.x][w.y][w.k][w.dog])
				{
					q.push(w);
					mark[w.x][w.y][w.k][w.dog] = true;
				}
			}
			else if (isdigit(c))
			{
				w.k |= (1 << (c - '1'));
				if (!mark[w.x][w.y][w.k][w.dog])
				{
					mark[w.x][w.y][w.k][w.dog] = true;
					q.push(w);
				}
			}
			else if (islower(c))
			{
				if ((w.k & (1 << (c - 'a'))) && (!mark[w.x][w.y][w.k][w.dog]))
				{
					mark[w.x][w.y][w.k][w.dog] = true;
					q.push(w);
				}
			}
			else if (!mark[w.x][w.y][w.k][w.dog])
			{
				mark[w.x][w.y][w.k][w.dog] = true;
				q.push(w);
			}
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		node s;
		memset(mark, false, sizeof(mark));
		dogl = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", &maze[i][1]);
			for (int j = 1; j <= n; j++)
				if (maze[i][j] == 'O') s.x = i, s.y = j;
				else if (maze[i][j] == 'D') dogx[++dogl] = i, dogy[dogl] = j;
		}
		TT = INF;
		s.k = 0;
		s.dog = 0;
		s.t = 0;
		bfs(s);
		if (TT == INF)
			printf("GgSmd\n");
		else 
			printf("%d\n", TT);
	}
	return 0;
}
