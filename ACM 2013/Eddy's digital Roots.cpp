#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int root(int x)
{
	int i = x;
	while (i >= 10)
	{
		int k = i;
		int sum = 0;
		while (k > 0)
		{
			sum += (k % 10);
			k /= 10;
		}
		i = sum;
	}
	return i;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		int ss = n;
		for (int i = 2; i <= n; i++)
			ss = root(ss * n);
		printf("%d\n", ss);
	}
	return 0;
}