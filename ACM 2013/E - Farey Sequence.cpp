#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long pri[1000010];
long long res[1000010];

void re(void)
{
	int i, j;
	memset(pri, 0, sizeof(pri));
	pri[1] = 1;
	for (i = 2; i <= 1000010; i++)
	{
		if (pri[i] == 0)
		{
			for (j = i; j <= 1000010; j += i)
			{
				if (pri[j] == 0)
					pri[j] = j; 
				pri[j] = pri[j] / i * (i - 1);
			}
		}
	}
}
int main(void)
{
	re();
	memset(res, 0, sizeof(res));
	res[1] = res[2] = 1;
	for (int i = 3; i < 1000010; i++)
		res[i] = res[i - 1] + pri[i];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		printf("%lld\n", res[n]);
	}
	return 0;
}