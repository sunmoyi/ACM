#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

int num[maxn];
int sum, a;

int main(void)
{
	memset(num, 0, sizeof(num));
	scanf("%d", &sum);
	for (int i = 1; i <= sum; i++)
	{
		scanf("%d", &a);
		num[a]++;
	}
	int maxx = -1, site = 0;
	for (int i = 1; i < maxn; i++)
	{
		if (num[i] > maxx)
		{
			maxx = num[i];
			site = i;
		}
	}
	printf("%d\n%d\n", site, maxx);
	return 0;
}