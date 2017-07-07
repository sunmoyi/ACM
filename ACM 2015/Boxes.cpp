#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

bool vis[8888888];
int T;
int ans;
int num[10],endd;
int temp[10][10];

int bfs()
{
	queue<int>Q;
	int start = 0;
	for (int i = 1; i <= ans; i++)
		start += num[i] * pow(10, i - 1);
	memset(vis, false, sizeof(vis));
	vis[start] = true;
	Q.push(start);
	while (!Q.empty())
	{
		int now = Q.front();
		memset(temp, 0, sizeof(temp));
		int tempp = now, site = ans;//shuzi  abcdefg  代表数字1在a号位置
		while (tempp > 0)
		{
			int a = tempp % 10;
			temp[a][0]++;
			temp[a][temp[a][0]] = site;
			site--;
		}
		for (int i = 1; i <= ans; i++)
		{
			if (i - 1 > 0)
			{
				if (temp[i][temp[i][0]] < temp[i - 1][temp[i - 1][0]])
					;
				double a = 1;
				double s = sqrt(a);
			}
		}
	}
}

int main(void)
{
	scanf("`%d", &T);
	while (T--)
	{
		scanf("%d", &ans);
		for (int i = 1; i <= ans; i++)
		{
			scanf("%d", &num[i]);
		}
		printf("%d\n", bfs());
	}
	return 0;
}