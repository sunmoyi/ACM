#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define maxn 110

using namespace std;

char str[maxn][maxn];
int n;
char str1[maxn][maxn];
int road[maxn];

int main(void)
{
	scanf("%d", &n);
	
		memset(road, 0, sizeof(road));
		for (int i = 1; i <= n; i++)
		{
			getchar();
			scanf("%s %s", str[i], str1[i]);
			if (strcmp(str1[i], "SAME") == 0)
				road[i] = i;
		}
		int start = 1, endd = n;

		for (int i = 1; i <= n; i++)
		{
			if (strcmp(str1[i], "DOWN") == 0)
			{
				while (road[start] != 0)
					start++;
				road[start++] = i;
			}
		}

		for (int i = n; i >= 1; i--)
		{
			if (strcmp(str1[i], "UP") == 0)
			{
				while (road[endd] != 0)
					endd--;
				road[endd--] = i;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%s\n", str[road[i]]);
	
	return 0;
}