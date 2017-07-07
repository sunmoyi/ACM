#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[25];
int a;

int main(void)
{
	num[2] = 1;
	num[3] = 2;
	num[4] = 9;
	for (int i = 4; i <= 25; i++)
		num[i] = (i - 1)* (num[i - 1] + num[i - 2]);
	while (scanf("%d", &a) != EOF)
	{
		printf("%lld\n", num[a]);
	}
	return 0;
}