#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500010
#define INF 0x3f3f3f3f

using namespace std;

char str[maxn];

int main (void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		if (m == 2)
		{
			int c1 = 0, c2 = 0;
			for (int i = 1; i <= len; i++)
			{
				if (i & 1)
				{
					if (str[i] == 'A')
						c2++;
					else
						c1++;
				}
				else
				{
					if (str[i] == 'A')
						c1++;
					else
						c2++;
				}
			}
			printf("%d\n", min(c1, c2));
			for (int i = 1; i <= len; i++)
			{
				if (i & 1)
					printf("%c", (c1 < c2) ? 'A' : 'B');
				else
					printf("%c", (c1 < c2) ? 'B' : 'A');
			}
			printf("\n");
		}
		else
		{
			int ans = 0;
			str[len + 1] = str[0] = '@';
			for (int i = 2; i <= len; i++)
			{
				if (str[i] == str[i - 1])
				{
					ans++;
					for (int j = 1; j <= m; j++)
					{
						char ch = 'A' + j - 1;
						if (str[i] == ch || str[i + 1] == ch)
							continue;
						else
							str[i] = ch;
						break;
					}
				}
			}
			printf("%d\n", ans);
			str[len + 1] = 0;
			printf("%s\n", str + 1);
		}
	}
	return 0;
}