#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, k;

int main (void)
{ 
	while (scanf("%d", &n) != EOF)
	{
		m = sqrt(2 * n * 1.0);
		while (m > 0)
		{
			if(!((2 * n) % (m + 1)))
			{
				k = 2 * n / (m + 1);
				k -= m;
				k >>= 1;
				if ((2 * k + m) * (m + 1) / 2 == n && m >= 0)
					printf("%d %d\n", k, k + m);
			}
			m -= 1;
		}
	}
	return 0;
} 