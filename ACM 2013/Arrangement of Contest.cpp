#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdio.h>

using namespace std;

char str[110][110];
char S;
int sum;
int ans;

int main(void)
{
	freopen("arrange.in", "r", stdin);
	freopen("arrange.out", "w", stdout);
	scanf("%d", &ans);
	getchar();
	for (int i = 1; i <= ans; i++)
	{
		gets(str[i]);
	}

	bool flag = true;
	sum = 0;
	S = 'A';
	while (flag && S <= 'Z')
	{
		flag = false;
		for (int i = 1; i <= ans; i++)
		{
			if (str[i][0] == S)
			{
				sum++;
				S++;
				flag = true;
				break;
			}
		}
	}
	printf("%d\n", sum);

	return 0;
}