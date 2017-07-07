#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int num[maxn], sum, n, k, ans;

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 0; i < sum; i++)
			scanf("%d", &num[i]);

		sort(num, num + sum);

		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &k);
			ans = upper_bound(num, num + sum, k) - num;
			printf("%d\n", ans);
		}
	}
	return 0;
}