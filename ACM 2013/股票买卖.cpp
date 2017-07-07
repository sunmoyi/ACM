#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int days;
int num[100010];
int maxl[100010];
int maxr[100010];


int main(void)
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &days);
		//memset(maxl, 0, sizeof(maxl));
		//memset(maxr, 0, sizeof(maxr));
		for (int i = 1; i <= days; i++)
 			scanf("%d", &num[i]);

		int minn = num[1];
		for (int i = 1; i <= days; i++)
		{
			maxl[i] = num[i] - minn;
			minn = minn > num[i] ? num[i]: minn;
		}
		int maxx = num[days];
		for (int i = days; i >= 1; i--)
		{
			maxr[i] = maxx - num[i];
			maxx = maxx < num[i] ? num[i] : maxx;
		}
		for (int i = 2; i <= days; i++)
		{
			maxl[i] = maxl[i] < maxl[i - 1] ? maxl[i - 1] : maxl[i];
		}
		for (int i = days - 1; i >= 1; i--)
		{
			maxr[i] = maxr[i] > maxr[i + 1] ? maxr[i] : maxr[i + 1];
		}

		maxx = -1;
		for (int i = 1; i <= days; i++)
			maxx = max(maxx, maxr[i] + maxl[i]);

		printf("%d\n", maxx);
	}
	return 0;
}