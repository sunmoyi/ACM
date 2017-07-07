#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
long long num[32780];
int main(void)
{
	
	int n;
	memset(num, 0, sizeof(num));
	num[0] = 1;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i; j < 32780; j++)
			num[j] += num[j - i];
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%lld\n", num[n]);
	}
	return 0;
}