#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m, a, b, q, p;
	while (scanf("%d", &q) != EOF)
	{
		while (q--)
		{
			int num = 1;
			while (scanf("%d %d", &n, &m) && (n + m))
			{
				int cnt = 0;
				for (b = 2; b < n; b++)
				{
					for (a = 1; a < b; a++)
					{
						if ((a * a + b * b + m) % (a * b) == 0)
							cnt++;
					}
				}
				printf("Case %d: %d\n", num++, cnt);
			}
			if (q)
				printf("\n");
		}
	}
	return 0;
}