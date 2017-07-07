#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int num[105];
int a;

int main(void)
{
	int n;
	int sum;
	while (scanf("%D", &n) !=EOF)
	{
		a = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] % 2 == 1)
				a++;
		}
		if (a % 2 == 1)
			printf("%d\n", a);
		else
			printf("%d\n", n - a);
	}
	return 0;
}