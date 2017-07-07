#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[30];
long long a;

int main(void)
{
	num[0] = 1;
	for (int i = 1; i < 30; i++)
		num[i] = num[i - 1] * 3;
	while (scanf("%lld", &a) != EOF && a)
	{
		printf("%d\n", lower_bound(num, num + 29, a) - num);
	}
	return 0;
}