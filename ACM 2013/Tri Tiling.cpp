#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	long long num[40];
	memset(num, 0, sizeof(num));
	num[2] = 3; 
	num[0] = 1;
	for (int i = 4; i < 40; i += 2)
	{
		long long temp = 0;
		for (int j = 0; j <= i - 4; j += 2)
		{
			temp += num[j];
		}
		num[i] = num[2] * num[i - 2] + 2 * temp;
	}
	int n;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		printf("%lld\n", num[n]);
	}
	return 0;
}