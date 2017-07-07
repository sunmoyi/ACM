#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<string>
#include<iostream>
#define maxn 10024

using namespace std;

char str[maxn];
bool vis[maxn][4];

set<string>ans;
set<string>::iterator it;

int main (void)
{
	int len, sum = 0;
	scanf("%s", str);
	len = strlen(str);
	memset(vis, true, sizeof(vis));
	vis[len][0] = false;
	for (int i = len; i >= 5; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (!vis[i][j])
			{
				string x = "", y = "";
				for (int k = 0; k < j; k++)
					y = y + str[i + k];
				for (int k = 1; (i - k) >= 5 && k < 4; k++)
				{
					x = str[i - k] + x;
					if (x != y && k > 1)
					{
						ans.insert(x);
						vis[i - k][k] = false;
					}
				}
			}
		}
	}
	printf("%d\n", int(ans.size()));
	for (it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
	return 0;
}