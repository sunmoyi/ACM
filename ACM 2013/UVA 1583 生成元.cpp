#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100005];

int main(void)
{
	int n, T;

	memset(num, 0, sizeof(num));
	for (int i = 1; i < 100005; i++)
	{
		int sum = i;
		int k = i;
		while (k > 0)
		{
			sum += k % 10;
			k /= 10;
		}
		if (num[sum] == 0 /*|| i < num[sum]*/)
			num[sum] = i;
	}
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &n);
			printf("%d\n", num[n]);
		}
	}
	return 0;
}