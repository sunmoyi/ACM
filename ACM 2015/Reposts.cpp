#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#define maxn 420
#define INF 0x3f3f3f3f

using namespace std;

vector<int>G[maxn];
map<string, int>mp;
int num, maxx;
string str;
int vis[maxn];

void init()
{
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i <= 2 * num; i++)
		G[i].clear();
	mp.clear();
}

int dfs(int x)
{
	if (vis[x] != -1)
		return vis[x];
	if (G[x].size() == 0)
		return 1;
	int ans = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		ans = max(ans, dfs(G[x][i]) + 1);
	}
	return vis[x] = ans;
}

string simple(string a)
{
	for (int i = 0; a[i] != 0; i++)
	{
		a[i] = tolower(a[i]);
	}
	return a;
}

int main(void)
{
	int a, b;
	while (cin >> num)
	{
		init();
		int top = 1;
		for (int i = 1; i <= num; i++)
		{
			cin >> str;
			str = simple(str);
			if (mp[str] == 0)
			{
				a = top;
				mp[str] = top++;
			}
			else
				a = mp[str];
			cin >> str;
			cin >> str;
			str = simple(str);
			if (mp[str] == 0)
			{
				b = top;
				mp[str] = top++;
			}
			else
				b = mp[str];
			G[a].push_back(b);
		}
		maxx = 1;
		for (int i = 1; i < top; i++)
		{
			if (vis[i] == -1)
				maxx = max(dfs(i), maxx);
		}
		printf("%d\n", maxx);
	}
	return 0;
}