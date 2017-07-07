#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[220];
int vis[220];
int len;
char aim[220];

void dfs(int x)
{
	if (x == len)
	{
		printf("%s\n", aim);
		return;
	}
	else
	{
		char front = 0;
		for (int i = 0; i < len; i++)
		{
			if (vis[i])
				continue;
			if (front == str[i])
				continue;
			front = str[i];
			vis[i] = true;
			aim[x] = str[i];
			aim[x + 1] = 0;
			dfs(x + 1);
			vis[i] = false;
		}
	}
}

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		len = strlen(str);
		sort(str, str + len);
		
 		memset(vis, 0, sizeof(vis));
		dfs(0);
	}
	return 0;
}