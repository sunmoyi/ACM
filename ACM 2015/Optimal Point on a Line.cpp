#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3000000
using namespace std;

int num[maxn];
int sum;

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%d", &num[i]);
		sort(num + 1, num + sum + 1);
		if (sum % 2 == 0)
			printf("%d\n", num[sum / 2]);
		else
			printf("%d\n", num[sum - sum / 2]);
	}
	return 0;
}