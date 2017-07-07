#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[5050];
bool ans[5000010];
int sum;

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		memset(ans, false, sizeof(ans));
		for (int i = 1; i <= sum; i++)
			scanf("%d", &num[i]);
		sort(num + 1, num + sum + 1);
		for (int i = 1; i <= sum; i++)
		{
			for (int j = i + 1; j <= sum; j++)
			{
				ans[num[j] - num[i]] = true;
			}
		}
		for (int i = sum; i < 5000010; i++)
		{
			bool flag = true;
			if (ans[i] == false)
			{
				for (int j = 2; j * i < 5000010; j += i)
				{
					if (ans[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}