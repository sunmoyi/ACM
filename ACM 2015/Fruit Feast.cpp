#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int vis[5000050];
int T, A, B;

bool dfs(int s)
{
	vis[s] = 1;
	if (s == T)
	{
		return true;
	}
	if (s + A <= T && vis[s + A] == 0)
		if (dfs(s + A))
			return true;
	if (s + B <= T && vis[s + B] == 0)
		if (dfs(s + B))
			return true;
	if (s != 0 && vis[s / 2] == 0)
		if (dfs(s / 2))
			return true;
	return false;
}

int main(void)
{
	while (scanf("%d %d %d", &T, &A, &B) != EOF)
	{
		memset(vis, 0, sizeof(false));
		dfs(0);
		for (int i = T; i >= 0; i--)
		{
			if (vis[i] == 1)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}