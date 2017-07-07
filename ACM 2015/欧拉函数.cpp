#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int phi(int n)
{
	int rea = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			rea = rea - rea / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		rea = rea - rea / n;
	return rea;
}

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		printf("%d %d\n", i, phi(i));
	}
	return 0;
}