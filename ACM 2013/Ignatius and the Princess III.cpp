#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int num[1000005];
int k, cnt, sum, tim;
int maxx, side;

int main(void)
{
	while (scanf("%d", &k) != EOF)
	{
		sum = 0;
		maxx = 0;
		side = 1;
		for (int i = 1; i <= k; i++)
			scanf("%d", &num[i]);
		num[k + 1] = INT_MAX;
		sort(num + 1, num + k + 2);//nlongn    6 * 10^6
		tim = num[1];
		cnt = 0;
		for (int i = 1; i <= k + 1; i++)//10n        10^7    2 * 10^7
		{
			if (tim == num[i])
			{
				cnt++;
			}
			else
			{
				if (cnt > maxx)
				{
					maxx = cnt;
					side = i - 1;
				}
				cnt = 1;
				tim = num[i];
			}

		}
		printf("%d\n", num[side]);
	}
	return 0;
}