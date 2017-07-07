#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

long long f[110][65];

void init()
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= 64; i++)
	{
		for (int j = 1; j <= 64; j++)
		{
			f[i][j] = f[i - 1][j - 1] + 1 + f[i][j - 1];
		}
	}
}

int main (void)
{
	init();
	int k;
	long long n;
	while (scanf("%d %lld", &k, &n) && k)
	{
		k = min(k, 63);
		bool ok = false;
		for (int i = 0; i <= 63; i++)
		{
			if (f[k][i] >= n)
			{
				printf("%d\n", i);
				ok = true;
				break;
			}
		}
		if (!ok)
			printf("More than 63 trials needed.\n");
	}
}