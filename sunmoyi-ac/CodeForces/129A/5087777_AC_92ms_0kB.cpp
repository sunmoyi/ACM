#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int num[105];
int a, b;

int main(void)
{
	int n;
	int sum;
	while (scanf("%D", &n) !=EOF)
	{
		sum = 0;
		a = b = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] % 2 == 1)
				a++;
			else
				b++;
			sum += num[i];
		}
		if (sum % 2 == 1)
			printf("%d\n", a);
		else
			printf("%d\n", b);
	}
	return 0;
}