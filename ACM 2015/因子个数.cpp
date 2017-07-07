#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int count(int n)
{
	int s = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int a = 0;
			while (n % i == 0)
			{
				a++;
				n /= i;
			}
			s *= (a + 1);
		}
	}
	if (n > 1)
		s *= 2;
	return s;
}

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		printf("%d %d\n", i, count(i));
	}
	return 0;
}