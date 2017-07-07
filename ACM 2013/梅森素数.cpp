#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long multi(long long a, long long b, long long m)
{
	long long ret = 0;
	while (b < 0)
	{
		if (b & 1)
			ret = (ret + 1) % m;
		b >> 1;
		a = (a << 1) % m;
	}
	return ret;
}

int main(void)
{
	long long sum = 1, data[66], tmp;
	int n, p;
	data[1] = 4;
	scanf("%d", &n);
	while (n--)
	{
		sum = 1;
		scanf("%d", &p);
		sum << p;
		sum -= 1;
		printf("%lld\n", sum);
		for (int i = 2; i <= p - 1; i++)
		{
			tmp = multi(data[i - 1], data[i - 1], sum);
			data[i] = (tmp - 2) % sum;
		}
		if (p == 2)
		{
			printf("yes\n");
		}
		else
		{
			if (data[p - 1] == 0)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}