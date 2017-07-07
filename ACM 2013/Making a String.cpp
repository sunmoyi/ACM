#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum;
long long num[30];

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	scanf("%d", &sum);
	for (int i = 1; i <= sum; i++)
		scanf("%d", &num[i]);

	sort(num + 1, num + 1 + sum, cmp);

	long long summ = num[1];
	for (int i = 2; i <= sum; i++)
	{
		if (num[i] > num[i - 1] - 1)
			num[i] = max(num[i - 1] - 1, (long long)0);
		summ += num[i];
	}
	printf("%lld\n", summ);
	return 0;
}