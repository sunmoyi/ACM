#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 10000

using namespace std;

char str[maxn];
vector<int>map[30];
bool vis[30];
bool flag1 = false, flag2 = false;

bool dfs()
{
	queue<int>Q;
	Q.push('b' - 'a');
	vis['b' - 'a'] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];
			if (!vis[next])
			{
				vis[next] = true;
				Q.push(next);
			}
		}
	}
	return vis['m' - 'a'];
}

int main(void)
{
	while (scanf("%s", str) != EOF && str[0] != '0')
	{
		flag1 = false, flag2 = false;
		for (int i = 0; i < 29; i++)
			map[i].clear();
		memset(vis, false, sizeof(vis));

		map[str[0] - 'a'].push_back(str[strlen(str) - 1] - 'a');
		if (str[0] == 'b')
			flag1 = true;
		if (str[strlen(str) - 1] == 'm')
			flag2 = true;
		while (scanf("%s", str) != EOF && str[0] != '0')
		{
			map[str[0] - 'a'].push_back(str[strlen(str) - 1] - 'a');
			if (str[0] == 'b')
				flag1 = true;
			if (str[strlen(str) - 1] == 'm')
				flag2 = true;
		}
		if (flag1 && flag2 && dfs())
			printf("Yes.\n");
		else
			printf("No.\n");
	}
	return 0;
}