#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum(int n)
{
	int s = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int a = 1;
			while (n % i == 0)
			{
				n /= i;
				a *= i;
			}
			s = s * (a * i - 1) / (i - 1);
		}
	}
	if (n > 1)
		s = s * (n + 1);
	return s;
}

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		printf("%d %d\n", i, sum(i));
	}
	return 0;
}