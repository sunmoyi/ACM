#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num1[105], num2[105], ans[105];

int main(void)
{
	while (scanf("%s %s", &num1, &num2) != EOF)
	{
		int len1 = strlen(num1);
		int len2 = strlen(num2);
		int k = min(len1, len2);
		int mark = 0;
		for (int i = 0; i < k; i++)
		{
			ans[i] = num1[i] - '0' + num2[i] + mark;
			mark = 0;
			if (ans[i] > '9')
			{
				ans[i] -= 10;
				mark = 1;
			}
		}
		for (int i = k; i < max(len1, len2); i++)
		{
			if (i < len1)
			{
				ans[i] = num1[i] + mark;
				mark = 0;
				if (ans[i] > '9')
				{
					ans[i] -= 10;
					mark = 1;
				}
			}
			else
			{
				ans[i] = num2[i] + mark;
				mark = 0;
				if (ans[i] > '9')
				{
					ans[i] -= 10;
					mark = 1;
				}
			}
		}
		ans[max(len1, len2)] == 0;
		if (mark == 1)
		{
			ans[max(len1, len2)] = '1';
			ans[max(len1, len2) + 1] = 0;
		}
		printf("%s\n", ans);
	}
	return 0;
}