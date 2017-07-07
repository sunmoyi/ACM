#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100];
int sum, T;

int main(void)
{
	while(scanf("%d", &T) != EOF)
	{
		
		for (int ss = 1; ss <= T; ss++)
		{
			long long mid = 0;
			long long ans1 = 0;;
			scanf("%d", &sum);
			for (int j = 0; j < sum; j++)
			{
				scanf("%d", &num[j]);
				mid += num[j];
				ans1 += num[j];
			}
			mid /= 2;
			
			sort(num, num + sum);
			ans1 -= num[sum - 1];

			if (ans1 < num[sum - 1])
				ans1 = ans1 * 2;
			else
				ans1 = ans1 + num[sum - 1];

			printf("Case #%d: %lld\n", ss, min(mid, ans1));
		}
	}
	return 0;
}