#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

__int64 a[1000000];
__int64 s;
int ans;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		memset(a, 0, sizeof(a));
		__int64 site = 0;
		for (int i = 1; i <= ans; i++)
		{
			scanf("%I64d", &s);
			a[s]++;
			if (site == 0 && a[s] >= ans / 2 + 1)
			{
				site = s;
			}
		}
		printf("%I64d\n", site);
	}
	return 0;
}