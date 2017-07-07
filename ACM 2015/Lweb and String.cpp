#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[1000000];
int T;
bool vis[100];

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		getchar();
		for (int s = 1; s <= T; s++)
		{
			scanf("%s", str);
			memset(vis, false, sizeof(vis));
			int sum = 0;
			for (int i = 0; i < strlen(str); i++)
			{
				if (!vis[str[i] - 'a'])
				{
					sum++;
					vis[str[i] - 'a'] = true;
				}
			}
			printf("Case #%d: %d\n", s, sum);
		}
	}
	return 0;
}