#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

char sat[maxn][10];

int main (void)
{
	int sum;
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%s", sat[i]);
		bool flag = false;
		for (int i = 1; i <= sum; i++)
		{
			if (sat[i][0] == sat[i][1] && sat[i][0] == 'O')
			{
				flag = true;
				sat[i][0] = sat[i][1] = '+';
				break;
			}
			if (sat[i][3] == sat[i][4] && sat[i][3] == 'O')
			{
				flag = true;
				sat[i][3] = sat[i][4] = '+';
				break;
			}
		}
		if (!flag)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for (int i = 1; i <= sum; i++)
				printf("%s\n", sat[i]);
		}
	}
	return 0;
}