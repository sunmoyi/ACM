/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char map[7][7];
int sum[7][7];
int mapp[7][7];
int n, a, b, c, d, count1;

void minn(void)
{
	int minn = sum[1][1];
	c = 1; d = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (sum[i][j] < minn && sum[i][j] != -3)
			{
				minn = sum[i][j];
				c = i;
				d = j;
			}
	return;
}

bool exict(int m)
{
	int flag = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (mapp[i][j] == m)
				flag = 0;
	if (flag == 0)
		return true;
	else
		return false;
}
int main(void)
{
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		count1 = 0;
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 6; j++)
				sum[i][j] = -3;
		memset(mapp, 0, sizeof(mapp));
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf_s("%c", &map[i][j]);
				if (map[i][j] == 'X')
					mapp[i][j] = 1;
			}
			getchar();
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] != 'X')
				{
					a = i;
					b = j;
					while (i >= 1 && i <= n && j >= 1 && i <= n && map[i][j] != 'X')
					{
						sum[a][b] ++;
						i++;
					}
					i = a;
					j = b;
					while (i >= 1 && i <= n && j >= 1 && i <= n && map[i][j] != 'X')
					{
						sum[a][b] ++;
						i--;
					}
					i = a;
					j = b;
					while (i >= 1 && i <= n && j >= 1 && j <= n && map[i][j] != 'X')
					{
						sum[a][b] ++;
						j++;
					}
					i = a;
					j = b;
					while (i >= 1 && i <= n && j >= 1 && j <= n && map[i][j] != 'X')
					{
						sum[a][b] ++;
						j--;
					}
					i = a;
					j = b;
				}
			}
		}
		while (1)
		{
			if (!exict(0))
				break;
			minn();
			sum[c][d] = INT_MAX;
			if (mapp[c][d] == 0)
			{
				count1++;
				mapp[c][d] = 1;
				for (int i = c; i <= n; i++)
				{
					mapp[i][d] = 1;
					if (map[i][d] == 'X')
						break;
				}
				for (int i = c; i >= 1; i--)
				{
					mapp[i][d] = 1;
					if (map[i][d] == 'X')
						break;
				}
				for (int i = d; i <= n; i++)
				{
					mapp[c][i] = 1;
					if (map[c][i] == 'X')
						break;
				}
				for (int i = d; i >= 1; i--)
				{
					mapp[c][i] = 1;
					if (map[c][i] == 'X')
						break;
				}
			}
		}
		printf("%d\n", count1);
	}
	return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define REP(a,b,c) for(int a = b; a < c; ++a)
#define eps 10e-8

const int MAX_ = 110;
const int N = 100010;
const int INF = 0x7fffffff;

struct node{
	int s, e;
	int num;
}t[MAX_];

int vis[MAX_][MAX_];
char str[MAX_][MAX_];


bool cmp(const node& a, const node& b)
{
	return a.num < b.num;
}

int main()
{
	int T;
	int n, m;
	//scanf("%d",&T);
	while (scanf_s("%d", &n), n) {
		REP(i, 0, n){
			scanf_s("%s", str[i], 110);
		}
		int cnt = 0;
		//mst(vis, 0);
		REP(i, 0, n){
			REP(j, 0, n){
				if (str[i][j] == '.'){
					vis[i][j] = 0;
					int tmp = 0; 
					int h = 0;
					while (i - h > -1 && str[i - h][j] == '.'){ h++; tmp++; }

					h = 1;
					while (i + h < n && str[i + h][j] == '.'){ h++; tmp++; }

					h = 1;
					while (j - h > -1 && str[i][j - h] == '.'){ h++; tmp++; }

					h = 1;
					while (j + h < n && str[i][j + h] == '.'){ h++; tmp++; }

					t[cnt].s = i;
					t[cnt].e = j;
					t[cnt].num = tmp;
					cnt++;
				}
				else vis[i][j] = 1;
			}
		}
		sort(t, t + cnt, cmp);


		int ans = 0;
		REP(i, 0, cnt){
			int x = t[i].s, y = t[i].e;
			if (!vis[x][y]){
				ans++;
				int h = 0;
				while (x - h > -1 && str[x - h][y] == '.')
				{ 
					vis[x - h][y] = 1; 
					h++; 
				}

				h = 1;
				while (x + h < n && str[x + h][y] == '.')
				{ 
					vis[x + h][y] = 1; 
					h++; 
				}

				h = 1;
				while (y - h > -1 && str[x][y - h] == '.')
				{ 
					vis[x][y - h] = 1; 
					h++; 
				}

				h = 1;
				while (y + h < n && str[x][y + h] == '.')
				{
					vis[x][y + h] = 1; 
					h++; 
				}

			}
		}

		printf("%d\n", ans);

	}
	return 0;
}