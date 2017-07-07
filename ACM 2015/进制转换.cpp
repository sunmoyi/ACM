#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int from, to;
char num[1000];
int ans[1000], top;

int main(void)
{
	while (scanf("%d", &from) != EOF)
	{
		getchar();
		scanf("%s", num);
		scanf("%d", &to);
		memset(ans, 0, sizeof(0));
		top = 0;
		long long temp = 0;
		for (int i = 0; i < strlen(num); i++)
		{
			temp *= from;
			if (num[i] >= 'A')
				temp += num[i] - 'A' + 10;
			else
				temp += num[i] - '0';
		}
		while (temp > 0)
		{
			ans[top++] = temp % to;
			temp /= to;
		}
		for (int i = top - 1; i >= 0; i--)
		{
			if (ans[i] < 10)
				printf("%d", ans[i]);
			else
				printf("%c", ans[i] - 10 + 'A');
		}
		printf("\n");
	}
	return 0;
}