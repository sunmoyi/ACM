#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, sum, num[15];
bool vis[15];

bool check(int i, int j)// 前一步 i   后以步 j  
{
	if (vis[j] == true)
		return false;
	if (i == 1 && j == 3 || i == 3 && j == 1)
		if (vis[2] == false)
			return false;
	if (i == 1 && j == 9 || i == 9 && j == 1)
		if (vis[5] == false)
			return false;
	if (i == 1 && j == 7 || i == 7 && j == 1)
		if (vis[4] == false)
			return false;
	if (i == 2 && j == 8 || i == 8 && j == 2)
		if (vis[5] == false)
			return false;
	if (i == 7 && j == 3 || i == 3 && j == 7)
		if (vis[5] == false)
			return false;
	if (i == 4 && j == 6 || i == 6 && j == 4)
		if (vis[5] == false)
			return false;
	if (i == 7 && j == 9 || i == 9 && j == 7)
		if (vis[8] == false)
			return false;
	if (i == 3 && j == 9 || i == 9 && j == 3)
		if (vis[6] == false)
			return false;
	return true;
}

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			memset(vis, 0, sizeof(vis));
			scanf("%d", &sum);
			for (int i = 1; i <= sum; i++)
				scanf("%d", &num[i]);

			bool flag = true;
			vis[num[1]] = true;
			for (int i = 2; i <= sum; i++)
			{
				if (!check(num[i - 1], num[i]))
					flag = false;
				vis[num[i]] = true;
			}
			int kk = 0;
			for (int i = 1; i <= 9; i++)
			{
				if (vis[i])
					kk++;
			}
			if (flag && kk >= 4)
				printf("valid\n");
			else
				printf("invalid\n");
		}
	}
}