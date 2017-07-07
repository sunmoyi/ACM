#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

int n, k;

int main(void)
{
	scanf("%d %d", &n, &k);
	if (k == 0)
	{
		for (int i = 1; i <= n * 2 - 1; i++)
			printf("%d ", i);
		printf("%d\n", n * 2);
		return 0;
	}
	else
	{
		printf("%d %d", 1 + k, 1);
		for (int i = 2; i <= n * 2; i++)
			if(i != 1 + k)
				printf(" %d", i);
		printf("\n");
	}
	return 0;
}