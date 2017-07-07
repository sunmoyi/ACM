#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, sum;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		sum = 0;
		while (n > 0 && m > 0)
		{
			if (n == 1 && m == 1)
				break;
			if (n > m)
			{
				n -= 2;
				m += 1;
			}
			else
			{
				n += 1;
				m -= 2;
			}
			sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}