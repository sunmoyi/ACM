#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, a, k;
	while (scanf("%d %d %d", &n, &a, &k) != EOF)
	{
		if (k < 0)
		{
			int s = abs(k);
			for (int i = 1; i <= s; i++)
			{
				a--;
				if (a <= 0)
					a = n;
			}
			printf("%d\n", a);
		}
		else
		{
			for (int i = 1; i <= k; i++)
			{
				a++;
				if (a > n)
					a = 1;
			}
			printf("%d\n", a);
		}
	}
	return 0;
}