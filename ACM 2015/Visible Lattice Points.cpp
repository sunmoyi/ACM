#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long phh[1010];

void  phi()
{
	for (int i = 1; i <= 1000; i++)
		phh[i] = i;
	for (int i = 2; i <= 1000; i += 2)
		phh[i] /= 2;
	for (int i = 3; i <= 1000; i += 2)
	{
		if (phh[i] == i)
		{
			for (int j = i; j <= 1000; j += i)
				phh[j] = phh[j] / i * (i - 1);
		}
	}
	for (int i = 2; i <= 1000; i++)
		phh[i] += phh[i - 1];
}

int main(void)
{
	phi();
	int ncase, n;
	while (scanf("%d", &ncase) != EOF)
	{
		for (int i = 1; i <= ncase; i++)
		{
			scanf("%d", &n);
			printf("%d %d %lld\n", i, n, phh[n] * 2 + 1);
		}
	}
	return 0;
}